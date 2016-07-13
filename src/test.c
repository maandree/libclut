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

#include <math.h>



struct clut
{
  size_t   red_size;
  size_t green_size;
  size_t  blue_size;
  uint16_t   *red;
  uint16_t *green;
  uint16_t  *blue;
};



static inline int clutcmp(const struct clut *a, const struct clut *b, uint16_t tol)
{
  size_t i;
  if (tol == 0)
    return memcmp(a->red, b->red, 3 * 256 * sizeof(uint16_t));
  for (i = 0; i < 3 * 256; i++)
    if (a->red[i] > b->red[i])
      {
	if (a->red[i] - b->red[i] > tol)
	  return +1;
      }
    else if (a->red[i] < b->red[i])
      {
	if (b->red[i] - a->red[i] > tol)
	  return -1;
      }
  return 0;
}


static int dumpcluts(const struct clut *a, const struct clut *b, int tol)
{
  size_t i;
  uint16_t *r1 = a->red, *r2 = b->red, *g1 = a->green, *g2 = b->green, *b1 = a->blue, *b2 = b->blue;
  for (i = 0; i < 256; i++)
    {
      if ((tol >= 0) &&
	  (((r1[i] > r2[i]) ? (r1[i] - r2[i]) : (r2[i] - r1[i])) <= tol) &&
	  (((g1[i] > g2[i]) ? (g1[i] - g2[i]) : (g2[i] - g1[i])) <= tol) &&
	  (((b1[i] > b2[i]) ? (b1[i] - b2[i]) : (b2[i] - b1[i])) <= tol))
	continue;
      printf("%3zu (%02x)  ::  %04x - %04x  ----  %04x - %04x  ----  %04x - %04x\n",
	     i, i, a->red[i], b->red[i], a->green[i], b->green[i], a->blue[i], b->blue[i]);
    }
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
  double param;
  
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
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_start_over failed\n"), rc = 1;
  
  
  for (i = 0, j = 255; i < 256; i++, j--)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)i;
      t2.blue[j] = t2.green[j] = t2.red[j] = (uint16_t)i;
    }
  libclut_negative(&t1, UINT16_MAX, uint16_t, 1, 1, 1);
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_negative failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)i;
      t2.blue[i] = t2.green[i] = t2.red[i] = UINT16_MAX - (uint16_t)i;
    }
  libclut_rgb_invert(&t1, UINT16_MAX, uint16_t, 1, 1, 1);
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_rgb_invert failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)((i << 8) | i);
      t2.blue[i] = 1 + (t2.green[i] = 1 + (t2.red[i] = 1000 + (uint16_t)i));
    }
  libclut_rgb_limits(&t1, UINT16_MAX, uint16_t, 1000, 1255, 1001, 1256, 1002, 1257);
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_rgb_limits failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)i;
      t2.red[i]   = t1.blue[i]  * 2;
      t2.green[i] = t1.green[i] * 3;
      t2.blue[i]  = t1.blue[i]  * 4;
    }
  libclut_rgb_brightness(&t1, UINT16_MAX, uint16_t, 2, 3, 4);
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_rgb_brightness failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)i;
      t2.blue[i] = t2.green[i] = 2 * (t2.red[i] = (uint16_t)i);
    }
  libclut_manipulate(&t1, UINT16_MAX, uint16_t, (double (*)(double))(NULL), make_double, make_double);
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_manipulate failed\n"), rc = 1;
  

  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)i;
      t2.blue[i] = t2.green[i] = t2.red[i] = (uint16_t)(pow((double)i / UINT16_MAX, 1.0 / 1.1) * UINT16_MAX);
    }
  libclut_gamma(&t1, UINT16_MAX, uint16_t, 1.1, 1.1, 1.1);
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_gamma failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)((i << 8) | i);
      t2.blue[i] = t2.green[i] = t2.red[i] = (t1.red[i] - UINT16_MAX / 2) / 2 + UINT16_MAX / 2;
    }
  libclut_rgb_contrast(&t1, UINT16_MAX, uint16_t, 0.5, 0.5, 0.5);
  if (clutcmp(&t1, &t2, 1))
    printf("libclut_rgb_contrast failed\n"), rc = 1;
  
  
  param = 2.0;
  for (i = 0; i < 256; i++)
    {
      double x = i / 255.0;
      if (i % 255)
	{
	  x = 1.0 / x - 1.0;
	  x = log(x);
	  x = 0.5 - x / param;
	}
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)((i << 8) | i);
      t2.blue[i] = t2.green[i] = t2.red[i] = (uint16_t)(x * UINT16_MAX);
    }
  libclut_sigmoid(&t1, UINT16_MAX, uint16_t, &param, &param, &param);
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_sigmoid failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)((i << 8) | i);
      t2.blue[i] = t2.green[i] = t2.red[i] = t1.red[i & ~15] | (t1.red[i & ~15] >> 4);
    }
  libclut_lower_resolution(&t1, UINT16_MAX, uint16_t, 16, 0, 16, 0, 16, 0);
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_lower_resolution (x) failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)((i << 8) | i);
      t2.blue[i] = t2.green[i] = t2.red[i] = (uint16_t)(i / 255.0 * 15.0 + 0.5) * UINT16_MAX / 15;
    }
  libclut_lower_resolution(&t1, UINT16_MAX, uint16_t, 0, 16, 0, 16, 0, 16);
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_lower_resolution (y) failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)((i << 8) | i);
      t2.blue[i] = t2.green[i] = t2.red[i] = (uint16_t)((i << 8) | i);
    }
  libclut_linearise(&t1, UINT16_MAX, uint16_t, 1, 1, 1);
  if (!clutcmp(&t1, &t2, 1))
    printf("libclut_linearise failed\n"), rc = 1;
  libclut_standardise(&t1, UINT16_MAX, uint16_t, 1, 1, 1);
  if (clutcmp(&t1, &t2, 12))
    printf("libclut_linearise/libclut_standardise failed\n"), rc = 1;
  /* High error rate, especially at low values, are expected due
   * to low precision and truncated values rather rounded values. */
  
  
  if (!rc)
    printf("everything is fine\n");
  return rc;
 fail:
  perror(*argv);
  return 2;
  (void) argc;
}


/*
  libclut_cie_contrast
  libclut_cie_brightness
  libclut_cie_invert
  libclut_cie_limits
  libclut_cie_manipulate
  libclut_clip
  libclut_apply
  libclut_cie_apply
*/

