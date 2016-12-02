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

struct dclut
{
  size_t   red_size;
  size_t green_size;
  size_t  blue_size;
  double   *red;
  double *green;
  double  *blue;
};



static int clutcmp(const struct clut *a, const struct clut *b, uint16_t tol)
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


static int dclutcmp(const struct dclut *a, const struct dclut *b, double tol)
{
  size_t i;
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


static void dumpcluts(const struct clut *a, const struct clut *b, int tol)
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
      printf("%3zu (%02zx)  ::  %04x - %04x  ----  %04x - %04x  ----  %04x - %04x\n",
	     i, i, r1[i], r2[i], g1[i], g2[i], b1[i], b2[i]);
    }
}


static void dumpdcluts(const struct dclut *a, const struct dclut *b, double tol)
{
  size_t i;
  double *r1 = a->red, *r2 = b->red, *g1 = a->green, *g2 = b->green, *b1 = a->blue, *b2 = b->blue;
  for (i = 0; i < 256; i++)
    {
      if ((tol >= 0) &&
	  (((r1[i] > r2[i]) ? (r1[i] - r2[i]) : (r2[i] - r1[i])) <= tol) &&
	  (((g1[i] > g2[i]) ? (g1[i] - g2[i]) : (g2[i] - g1[i])) <= tol) &&
	  (((b1[i] > b2[i]) ? (b1[i] - b2[i]) : (b2[i] - b1[i])) <= tol))
	continue;
      printf("%3zu (%02zx)  ::  %lf - %lf  ----  %lf - %lf  ----  %lf - %lf\n",
	     i, i, r1[i], r2[i], g1[i], g2[i], b1[i], b2[i]);
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
#define HALF       ((double)5 / 10)
#define TENTHS(x)  ((double)x / 10)
  
  libclut_colour_space_conversion_matrix_t M, Minv;
  libclut_rgb_colour_space_t srgb  = LIBCLUT_RGB_COLOUR_SPACE_SRGB_INITIALISER;
  libclut_rgb_colour_space_t wgrgb = LIBCLUT_RGB_COLOUR_SPACE_WIDE_GAMUT_RGB_INITIALISER;
  struct clut t1, t2, t3;
  struct dclut d1, d2;
  size_t i, j;
  int rc = 0;
  double param, r, g, b;
  
  t1.  red_size = t2.  red_size = t3.  red_size = d1.  red_size = d2.  red_size = 256;
  t1.green_size = t2.green_size = t3.green_size = d1.green_size = d2.green_size = 256;
  t1. blue_size = t2. blue_size = t3. blue_size = d1. blue_size = d2. blue_size = 256;
  if (!(t1.red = malloc(3 * 256 * sizeof(uint16_t))))  goto fail;
  if (!(t2.red = malloc(3 * 256 * sizeof(uint16_t))))  goto fail;
  if (!(t3.red = malloc(3 * 256 * sizeof(uint16_t))))  goto fail;
  if (!(d1.red = malloc(3 * 256 * sizeof(double))))  goto fail;
  if (!(d2.red = malloc(3 * 256 * sizeof(double))))  goto fail;
  t1.blue = (t1.green = t1.red + 256) + 256;
  t2.blue = (t2.green = t2.red + 256) + 256;
  t3.blue = (t3.green = t3.red + 256) + 256;
  d1.blue = (d1.green = d1.red + 256) + 256;
  d2.blue = (d2.green = d2.red + 256) + 256;
  
  
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
      t2.blue[i] = t2.green[i] = t2.red[i] = (uint16_t)(UINT16_MAX - (uint16_t)i);
    }
  libclut_rgb_invert(&t1, UINT16_MAX, uint16_t, 1, 1, 1);
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_rgb_invert failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)((i << 8) | i);
      t2.blue[i] = (uint16_t)(1 + (t2.green[i] = (uint16_t)(1 + (t2.red[i] = (uint16_t)(1000 + i)))));
    }
  libclut_rgb_limits(&t1, UINT16_MAX, uint16_t, 1000, 1255, 1001, 1256, 1002, 1257);
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_rgb_limits failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)i;
      t2.red[i]   = (uint16_t)(t1.blue[i]  * 2);
      t2.green[i] = (uint16_t)(t1.green[i] * 3);
      t2.blue[i]  = (uint16_t)(t1.blue[i]  * 4);
    }
  libclut_rgb_brightness(&t1, UINT16_MAX, uint16_t, 2, 3, 4);
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_rgb_brightness failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)i;
      t2.blue[i] = t2.green[i] = (uint16_t)(2 * (t2.red[i] = (uint16_t)i));
    }
  libclut_manipulate(&t1, UINT16_MAX, uint16_t, (double (*)(double))(NULL), make_double, make_double);
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_manipulate failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)i;
      t2.blue[i] = t2.green[i] = t2.red[i] = (uint16_t)(pow((double)i / UINT16_MAX, (double)10 / 11) * UINT16_MAX);
    }
  libclut_gamma(&t1, UINT16_MAX, uint16_t, TENTHS(11), TENTHS(11), TENTHS(11));
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_gamma failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)((i << 8) | i);
      t2.blue[i] = t2.green[i] = t2.red[i] = (uint16_t)((t1.red[i] - UINT16_MAX / 2) / 2 + UINT16_MAX / 2);
    }
  libclut_rgb_contrast(&t1, UINT16_MAX, uint16_t, HALF, HALF, HALF);
  if (clutcmp(&t1, &t2, 1))
    printf("libclut_rgb_contrast failed\n"), rc = 1;
  
  
  param = 2;
  for (i = 0; i < 256; i++)
    {
      double x = (double)i / 255;
      if (i % 255)
	{
	  x = 1 / x - 1;
	  x = log(x);
	  x = HALF - x / param;
	}
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)((i << 8) | i);
      t2.blue[i] = t2.green[i] = t2.red[i] = (uint16_t)(x * UINT16_MAX);
    }
  libclut_sigmoid(&t1, UINT16_MAX, uint16_t, &param, &param, &param);
  t1.blue[0]   = t1.green[0]   = t1.red[0]   = t2.red[0];
  t1.blue[255] = t1.green[255] = t1.red[255] = t2.red[255];
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_sigmoid failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)((i << 8) | i);
      t2.blue[i] = t2.green[i] = t2.red[i] = t1.red[i & 0xF0] | (t1.red[i & 0xF0] >> 4);
    }
  libclut_lower_resolution(&t1, UINT16_MAX, uint16_t, 16, 0, 16, 0, 16, 0);
  if (clutcmp(&t1, &t2, 0))
    printf("libclut_lower_resolution (x) failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)((i << 8) | i);
      t2.blue[i] = t2.green[i] = t2.red[i] = (uint16_t)((uint16_t)((double)i / 255 * 15 + HALF) * UINT16_MAX / 15);
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
  
  
  for (i = 0; i < 256; i++)
    {
      d1.blue[i] = d1.green[i] = d1.red[i] = (i & 1) ? -1 : 2;
      d2.blue[i] = d2.green[i] = d2.red[i] = (i & 1) ?  0 : 1;
    }
  libclut_clip(&d1, 1, double, 1, 1, 1);
  if (dclutcmp(&d1, &d2, 0))
    printf("libclut_clip failed\n"), rc = 1;
  
  
  for (i = 0; i < 256; i++)
    {
      t1.blue[i] = t1.green[i] = t1.red[i] = (uint16_t)(((255 - i) << 8) | (255 - i));
      t2.blue[i] = t2.green[i] = t2.red[i] = (uint16_t)(pow((double)i / 255, (double)10 / 11) * UINT16_MAX);
    }
  for (i = 0; i < 256; i++)
    t3.blue[i] = t3.green[i] = t3.red[i] = t2.red[255 - i];
  libclut_apply(&t1, UINT16_MAX, uint16_t, &t2, UINT16_MAX, uint16_t, 1, 1, 1);
  if (clutcmp(&t1, &t3, 0))
    printf("libclut_apply failed\n"), rc = 1;
  
  
  if (libclut_model_get_rgb_conversion_matrix(&srgb, &wgrgb, M, Minv))
    {
      printf("libclut_model_get_rgb_conversion_matrix failed\n"), rc = 1;
      goto rgb_conversion_done;
    }
  if (0.5587 > M[0][0] || M[0][0] > 0.5589 ||
      0.3587 > M[0][1] || M[0][1] > 0.3588 ||
      -.0101 > M[0][2] || M[0][2] > -.0099 ||
      0.0938 > M[1][0] || M[1][0] > 0.0939 ||
      0.8564 > M[1][1] || M[1][1] > 0.8566 ||
      0.0746 > M[1][2] || M[1][2] > 0.0747 ||
      0.0186 > M[2][0] || M[2][0] > 0.0188 ||
      0.0967 > M[2][1] || M[2][1] > 0.0968 ||
      1.2237 > M[2][2] || M[2][2] > 1.2239)
    {
      printf("libclut_model_get_rgb_conversion_matrix failed\n"), rc = 1;
      goto rgb_conversion_done;
    }
  
  
  libclut_model_convert_rgb(0.1, 0.5, 0.9, M, &r, &g, &b);
  if (0.3024 > r || r > 0.3025 ||
      0.5301 > g || g > 0.5302 ||
      0.9931 > b || b > 0.9932)
    {
      printf("libclut_model_convert_rgb failed\n"), rc = 1;
      goto rgb_conversion_done;
    }
  
  
  libclut_model_convert_rgb(0.1, 0.5, 0.9, Minv, &r, &g, &b);
  if (-1.3341 > r || r > -1.3339 ||
       0.4916 > g || g >  0.4917 ||
       0.8144 > b || b >  0.8145)
    {
      printf("libclut_model_convert_rgb failed\n"), rc = 1;
      goto rgb_conversion_done;
    }
  
  
  libclut_convert_rgb_inplace(&t1, 1, double, M, trunc); /* TODO test */
  libclut_convert_rgb(&t1, 1, double, M, trunc, &t2);    /* TODO test */
  
  
 rgb_conversion_done:

  
  libclut_model_ciexyz_to_cieluv(1, 1, 1, 1, 1, 1, &r, &g, &b); /* TODO test */
  libclut_model_cieluv_to_ciexyz(1, 1, 1, 1, 1, 1, &r, &g, &b); /* TODO test */
  libclut_model_cielch_to_cieluv(1, 1, &r, &g); /* TODO test */
  libclut_model_cieluv_to_cielch(1, 1, &r, &g); /* TODO test */
  libclut_model_srgb_to_yiq(1, 1, 1, &r, &g, &b); /* TODO test */
  libclut_model_yiq_to_srgb(1, 1, 1, &r, &g, &b); /* TODO test */
  libclut_model_srgb_to_ydbdr(1, 1, 1, &r, &g, &b); /* TODO test */
  libclut_model_ydbdr_to_srgb(1, 1, 1, &r, &g, &b); /* TODO test */
  libclut_model_yuv_to_ydbdr(1, 1, &r, &g); /* TODO test */
  libclut_model_ydbdr_to_yuv(1, 1, &r, &g); /* TODO test */
  libclut_model_srgb_to_ypbpr(1, 1, 1, &r, &g, &b); /* TODO test */
  libclut_model_ypbpr_to_srgb(1, 1, 1, &r, &g, &b); /* TODO test */
  libclut_model_srgb_to_ycgco(1, 1, 1, &r, &g, &b); /* TODO test */
  libclut_model_ycgco_to_srgb(1, 1, 1, &r, &g, &b); /* TODO test */
  libclut_model_cie_1960_ucs_to_ciexyz(1, 1, 1, &r, &g, &b); /* TODO test */
  libclut_model_ciexyz_to_cie_1960_ucs(1, 1, 1, &r, &g, &b); /* TODO test */
  libclut_model_cieuvw_to_cie_1960_ucs(1, 1, 1, 1, 1, &r, &g, &b); /* TODO test */
  libclut_model_cie_1960_ucs_to_cieuvw(1, 1, 1, 1, 1, &r, &g, &b); /* TODO test */
  
  
  if (!rc)
    printf("everything is fine\n");
  free(t1.red);
  free(t2.red);
  free(t3.red);
  free(d1.red);
  free(d2.red);
  return rc;
 fail:
  perror(*argv);
  return 2;
  (void) argc;
  
  (void) dumpcluts;
  (void) dumpdcluts;
}


/*
  TODO test these too: (also add this to the makefile)
  
  libclut_translate
  libclut_cie_contrast
  libclut_cie_brightness
  libclut_cie_invert
  libclut_cie_limits
  libclut_cie_manipulate
  libclut_cie_apply
*/

