/**
 * Copyright © 2016  Mattias Andrée <maandree@member.fsf.org>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "libclut.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct clut
{
  size_t   red_size;
  size_t green_size;
  size_t  blue_size;
  uint16_t   *red;
  uint16_t *green;
  uint16_t  *blue;
};



static inline int clutcmp(const struct clut *a, const struct clut *b)
{
  return memcmp(a->red, b->red, 3 * 256 * sizeof(uint16_t));
}


static int dumpcluts(const struct clut *a, const struct clut *b)
{
  size_t i;
  for (i = 0; i < 256; i++)
    printf("%3zu (%02x)  ::  %04x - %04x  ----  %04x - %04x  ----  %04x - %04x\n",
	   i, i, a->red[i], b->red[i], a->green[i], b->green[i], a->blue[i], b->blue[i]);
}

static double make_double(double x)
{
  return x * 2;
}


/**
 * Test libclut
 * 
 * @return  0: All tests passed
 *          1: At east one test fail
 *          2: An error occurred
 */
int main(int argc, char *argv[])
{
  struct clut t1, t2, t3;
  size_t i, j;
  int rc = 0;
  
  t1.  red_size = t2.  red_size = t3.  red_size = 256;
  t1.green_size = t2.green_size = t3.green_size = 256;
  t1. blue_size = t2. blue_size = t3. blue_size = 256;
  if (!(t1.red = malloc(3 * 256 * sizeof(uint16_t))))  goto fail;
  if (!(t2.red = malloc(3 * 256 * sizeof(uint16_t))))  goto fail;
  if (!(t3.red = malloc(3 * 256 * sizeof(uint16_t))))  goto fail;
  t1.blue = (t1.green = t1.red + 256) + 256;
  t2.blue = (t2.green = t2.red + 256) + 256;
  t3.blue = (t3.green = t3.red + 256) + 256;
  
  
  libclut_start_over(&t1, UINT16_MAX, uint16_t, 1, 1, 1);
  for (i = 0; i < 256; i++)
    t2.blue[i] = t2.green[i] = t2.red[i] = (uint16_t)((i << 8) | i);
  if (clutcmp(&t1, &t2))
    printf("libclut_start_over failed\n"), rc = 1;
  
  
  for (i = 0, j = 255; i < 256; i++, j--)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)i;
      t2.blue[j] = t2.green[j] = t2.red[j] = (uint16_t)i;
    }
  libclut_negative(&t1, UINT16_MAX, uint16_t, 1, 1, 1);
  if (clutcmp(&t1, &t2))
    printf("libclut_negative failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)i;
      t2.blue[i] = t2.green[i] = t2.red[i] = UINT16_MAX - (uint16_t)i;
    }
  libclut_rgb_invert(&t1, UINT16_MAX, uint16_t, 1, 1, 1);
  if (clutcmp(&t1, &t2))
    printf("libclut_rgb_invert failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)((i << 8) | i);
      t2.blue[i] = 1 + (t2.green[i] = 1 + (t2.red[i] = 1000 + (uint16_t)i));
    }
  libclut_rgb_limits(&t1, UINT16_MAX, uint16_t, 1000, 1255, 1001, 1256, 1002, 1257);
  if (clutcmp(&t1, &t2))
    printf("libclut_rgb_limits failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)i;
      t2.red[i]   = t1.blue[i]  * 2;
      t2.green[i] = t1.green[i] * 3;
      t2.blue[i]  = t1.blue[i]  * 4;
    }
  libclut_rgb_brightness(&t1, UINT16_MAX, uint16_t, 2, 3, 4);
  if (clutcmp(&t1, &t2))
    printf("libclut_rgb_brightness failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)i;
      t2.blue[i] = t2.green[i] = 2 * (t2.red[i] = (uint16_t)i);
    }
  libclut_manipulate(&t1, UINT16_MAX, uint16_t, (double (*)(double))(NULL), make_double, make_double);
  if (clutcmp(&t1, &t2))
    printf("libclut_manipulate failed\n"), rc = 1;
  
  
  if (!rc)
    printf("everything is fine\n");
  return rc;
 fail:
  perror(*argv);
  return 2;
  (void) argc;
}


/*
  libclut_rgb_contrast
  libclut_cie_contrast
  libclut_cie_brightness
  libclut_linearise
  libclut_standardise
  libclut_gamma
  libclut_cie_invert
  libclut_sigmoid
  libclut_cie_limits
  libclut_cie_manipulate
  libclut_clip
  libclut_lower_resolution
  libclut_apply
  libclut_cie_apply
*/

