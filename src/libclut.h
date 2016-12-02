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
#ifndef LIBCLUT_H
#define LIBCLUT_H

#include <stddef.h>
#include <string.h>
#include <math.h>



/* Not documented, may be removed or modified in the future. */
#define LIBCLUT_ILLUMINANT_A    .white_x = 0.44757, .white_y = 0.40745, .white_Y = 1
#define LIBCLUT_ILLUMINANT_B    .white_x = 0.34842, .white_y = 0.35161, .white_Y = 1
#define LIBCLUT_ILLUMINANT_C    .white_x = 0.31006, .white_y = 0.31616, .white_Y = 1
#define LIBCLUT_ILLUMINANT_D50  .white_x = 0.34567, .white_y = 0.35850, .white_Y = 1
#define LIBCLUT_ILLUMINANT_D55  .white_x = 0.33242, .white_y = 0.34743, .white_Y = 1
#define LIBCLUT_ILLUMINANT_D65  .white_x = 0.31271, .white_y = 0.32902, .white_Y = 1
#define LIBCLUT_ILLUMINANT_D75  .white_x = 0.29902, .white_y = 0.31485, .white_Y = 1
#define LIBCLUT_ILLUMINANT_E    .white_x = 1. / 3,  .white_y = 1. / 3,  .white_Y = 1
#define LIBCLUT_ILLUMINANT_F1   .white_x = 0.31310, .white_y = 0.33727, .white_Y = 1
#define LIBCLUT_ILLUMINANT_F2   .white_x = 0.37208, .white_y = 0.37529, .white_Y = 1
#define LIBCLUT_ILLUMINANT_F3   .white_x = 0.40910, .white_y = 0.39430, .white_Y = 1
#define LIBCLUT_ILLUMINANT_F4   .white_x = 0.44018, .white_y = 0.40329, .white_Y = 1
#define LIBCLUT_ILLUMINANT_F5   .white_x = 0.31379, .white_y = 0.34531, .white_Y = 1
#define LIBCLUT_ILLUMINANT_F6   .white_x = 0.37790, .white_y = 0.38835, .white_Y = 1
#define LIBCLUT_ILLUMINANT_F7   .white_x = 0.31292, .white_y = 0.32933, .white_Y = 1
#define LIBCLUT_ILLUMINANT_F8   .white_x = 0.34588, .white_y = 0.35875, .white_Y = 1
#define LIBCLUT_ILLUMINANT_F9   .white_x = 0.37417, .white_y = 0.37281, .white_Y = 1
#define LIBCLUT_ILLUMINANT_F10  .white_x = 0.34609, .white_y = 0.35986, .white_Y = 1
#define LIBCLUT_ILLUMINANT_F11  .white_x = 0.38052, .white_y = 0.37713, .white_Y = 1
#define LIBCLUT_ILLUMINANT_F12  .white_x = 0.43695, .white_y = 0.40441, .white_Y = 1

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the sRGB colour space.
 * 
 * sRGB does not use a regular gamma function, but rather two different
 * functions. `libclut_model_linear_to_standard1` and
 * and `libclut_model_standard_to_linear1` can be used so to convert
 * between sRGB and linear sRGB.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_SRGB_INITIALISER		\
  {								\
    .red_x   = 0.6400, .red_y   = 0.3300, .red_Y   = 0.212656,	\
    .green_x = 0.3000, .green_y = 0.6000, .green_Y = 0.715158,	\
    .blue_x  = 0.1500, .blue_y  = 0.0600, .blue_Y  = 0.072186,	\
    LIBCLUT_ILLUMINANT_D65					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the Adobe RGB (1998) colour space.
 * 
 * This gamma colour space's gamma is 2.2. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_ADOBE_RGB_INITIALISER		\
  {								\
    .red_x   = 0.6400, .red_y   = 0.3300, .red_Y   = 0.297361,	\
    .green_x = 0.2100, .green_y = 0.7100, .green_Y = 0.627355,	\
    .blue_x  = 0.1500, .blue_y  = 0.0600, .blue_Y  = 0.075285,	\
    LIBCLUT_ILLUMINANT_D65					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the Apple RGB colour space.
 * 
 * This gamma colour space's gamma is 1.8. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_APPLE_RGB_INITIALISER		\
  {								\
    .red_x   = 0.6250, .red_y   = 0.3400, .red_Y   = 0.244634,	\
    .green_x = 0.2800, .green_y = 0.5950, .green_Y = 0.672034,	\
    .blue_x  = 0.1550, .blue_y  = 0.0700, .blue_Y  = 0.083332,	\
    LIBCLUT_ILLUMINANT_D65					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the Best RGB colour space.
 * 
 * This gamma colour space's gamma is 2.2. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_BEST_RGB_INITIALISER		\
  {								\
    .red_x   = 0.7347, .red_y   = 0.2653, .red_Y   = 0.228457,	\
    .green_x = 0.2150, .green_y = 0.7750, .green_Y = 0.737352,	\
    .blue_x  = 0.1300, .blue_y  = 0.0350, .blue_Y  = 0.034191,	\
    LIBCLUT_ILLUMINANT_D50					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the Beta RGB colour space.
 * 
 * This gamma colour space's gamma is 2.2. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_BETA_RGB_INITIALISER		\
  {								\
    .red_x   = 0.6888, .red_y   = 0.3112, .red_Y   = 0.303273,	\
    .green_x = 0.1986, .green_y = 0.7551, .green_Y = 0.663786,	\
    .blue_x  = 0.1265, .blue_y  = 0.0352, .blue_Y  = 0.032941,	\
    LIBCLUT_ILLUMINANT_D50					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the Bruce RGB colour space.
 * 
 * This gamma colour space's gamma is 2.2. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_BRUCE_RGB_INITIALISER		\
  {								\
    .red_x   = 0.6400, .red_y   = 0.3300, .red_Y   = 0.240995,	\
    .green_x = 0.2800, .green_y = 0.6500, .green_Y = 0.683554,	\
    .blue_x  = 0.1500, .blue_y  = 0.0600, .blue_Y  = 0.075452,	\
    LIBCLUT_ILLUMINANT_D65					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the CIE RGB colour space.
 * 
 * This gamma colour space's gamma is 2.2. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_CIE_RGB_INITIALISER		\
  {								\
    .red_x   = 0.7350, .red_y   = 0.2650, .red_Y   = 0.176204,	\
    .green_x = 0.2740, .green_y = 0.7170, .green_Y = 0.812985,	\
    .blue_x  = 0.1670, .blue_y  = 0.0090, .blue_Y  = 0.010811,	\
    LIBCLUT_ILLUMINANT_E					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the ColorMatch RGB colour space.
 * 
 * This gamma colour space's gamma is 1.8. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_COLORMATCH_RGB_INITIALISER	\
  {								\
    .red_x   = 0.6300, .red_y   = 0.3400, .red_Y   = 0.274884,	\
    .green_x = 0.2950, .green_y = 0.6050, .green_Y = 0.658132,	\
    .blue_x  = 0.1500, .blue_y  = 0.0750, .blue_Y  = 0.066985,	\
    LIBCLUT_ILLUMINANT_D50					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the Don RGB 4 colour space.
 * 
 * This gamma colour space's gamma is 2.2. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_DON_RGB_4_INITIALISER		\
  {								\
    .red_x   = 0.6960, .red_y   = 0.3000, .red_Y   = 0.278350,	\
    .green_x = 0.2150, .green_y = 0.7650, .green_Y = 0.687970,	\
    .blue_x  = 0.1300, .blue_y  = 0.0350, .blue_Y  = 0.033680,	\
    LIBCLUT_ILLUMINANT_D50					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the ECI RGB v2 colour space.
 * 
 * This gamma colour space's used the L* gamma function. It cannot
 * be used with RGB colour space conversion unless the values are
 * tranlated into using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_ECI_RGB_V2_INITIALISER		\
  {								\
    .red_x   = 0.6700, .red_y   = 0.3300, .red_Y   = 0.320250,	\
    .green_x = 0.2100, .green_y = 0.7100, .green_Y = 0.602071,	\
    .blue_x  = 0.1400, .blue_y  = 0.0800, .blue_Y  = 0.077679,	\
    LIBCLUT_ILLUMINANT_D50					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the Ekta Space PS5 colour space.
 * 
 * This gamma colour space's gamma is 2.2. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_EKTA_SPACE_PS5_INITIALISER	\
  {								\
    .red_x   = 0.6950, .red_y   = 0.3050, .red_Y   = 0.260629,	\
    .green_x = 0.2600, .green_y = 0.7000, .green_Y = 0.734946,	\
    .blue_x  = 0.1100, .blue_y  = 0.0050, .blue_Y  = 0.004425,	\
    LIBCLUT_ILLUMINANT_D50					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the ITU-R Recommendation BT.709 (ITU-R BT.709) colour space.
 * 
 * This gamma colour space's gamma is 2.4. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_ITU_R_BT_709_INITIALISER	\
  {								\
    .red_x   = 0.6400, .red_y   = 0.3300, .red_Y   = 0.212656,	\
    .green_x = 0.3000, .green_y = 0.6000, .green_Y = 0.715158,	\
    .blue_x  = 0.1500, .blue_y  = 0.0600, .blue_Y  = 0.072186,	\
    LIBCLUT_ILLUMINANT_D65					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the Lightroom RGB colour space.
 * 
 * This gamma colour space's gamma is 1.0. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_LIGHTROOM_RGB_INITIALISER	\
  {								\
    .red_x   = 0.7347, .red_y   = 0.2653, .red_Y   = 0.288040,	\
    .green_x = 0.1596, .green_y = 0.8404, .green_Y = 0.711874,	\
    .blue_x  = 0.0366, .blue_y  = 0.0001, .blue_Y  = 0.000086,	\
    LIBCLUT_ILLUMINANT_D50					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the NTSC RGB colour space.
 * 
 * This gamma colour space's gamma is 2.2. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_NTSC_RGB_INITIALISER		\
  {								\
    .red_x   = 0.6700, .red_y   = 0.3300, .red_Y   = 0.298839,	\
    .green_x = 0.2100, .green_y = 0.7100, .green_Y = 0.586811,	\
    .blue_x  = 0.1400, .blue_y  = 0.0800, .blue_Y  = 0.114350,	\
    LIBCLUT_ILLUMINANT_C					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the PAL/SECAM RGB colour space.
 * 
 * This gamma colour space's gamma is 2.2. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_PAL_SECAM_RGB_INITIALISER	\
  {								\
    .red_x   = 0.6400, .red_y   = 0.3300, .red_Y   = 0.222021,	\
    .green_x = 0.2900, .green_y = 0.6000, .green_Y = 0.706645,	\
    .blue_x  = 0.1500, .blue_y  = 0.0600, .blue_Y  = 0.071334,	\
    LIBCLUT_ILLUMINANT_D65					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the ProPhoto RGB colour space.
 * 
 * This gamma colour space's gamma is 1.8. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_PROPHOTO_RGB_INITIALISER	\
  {								\
    .red_x   = 0.7347, .red_y   = 0.2653, .red_Y   = 0.288040,	\
    .green_x = 0.1596, .green_y = 0.8404, .green_Y = 0.711874,	\
    .blue_x  = 0.0366, .blue_y  = 0.0001, .blue_Y  = 0.000086,	\
    LIBCLUT_ILLUMINANT_D50					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the SMPTE-C RGB colour space.
 * 
 * This gamma colour space's gamma is 2.2. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_SMPTE_C_RGB_INITIALISER	\
  {								\
    .red_x   = 0.6300, .red_y   = 0.3400, .red_Y   = 0.212395,	\
    .green_x = 0.3100, .green_y = 0.5950, .green_Y = 0.701049,	\
    .blue_x  = 0.1550, .blue_y  = 0.0700, .blue_Y  = 0.086556,	\
    LIBCLUT_ILLUMINANT_D65					\
  }

/**
 * Initialiser for `struct libclut_rgb_colour_space` with the values
 * of the Wide Gamut RGB colour space.
 * 
 * This gamma colour space's gamma is 2.2. It cannot be used with
 * RGB colour space conversion unless the values are tranlated into
 * using the sRGB gamma function.
 */
#define LIBCLUT_RGB_COLOUR_SPACE_WIDE_GAMUT_RGB_INITIALISER	\
  {								\
    .red_x   = 0.7350, .red_y   = 0.2650, .red_Y   = 0.258187,	\
    .green_x = 0.1150, .green_y = 0.8260, .green_Y = 0.724938,	\
    .blue_x  = 0.1570, .blue_y  = 0.0180, .blue_Y  = 0.016875,	\
    LIBCLUT_ILLUMINANT_D50					\
  }

/*
 * name                                          gamma  xw     yw     xr     yr     xg     yg     xb     yb
 * ITU-R Recommendation BT.2020 (ITU-R BT.2020)  *1     { D65      }  0.708  0.292  0.170  0.797  0.131  0.046
 * ITU-R Recommendation BT.2100 (ITU-R BT.2100)  *2     { D65      }  0.708  0.292  0.170  0.797  0.131  0.046
 * DCI-P3 D65                                    ?      { D65      }  0.680  0.320  0.265  0.690  0.150  0.060
 * DCI-P3 Theater                                ?      0.314  0.351  0.680  0.320  0.265  0.690  0.150  0.060
 * https://en.wikipedia.org/wiki/Rec._601
 * 
 * *1  https://en.wikipedia.org/wiki/Rec._2020#Transfer_characteristics
 * *2  http://www.itu.int/dms_pubrec/itu-r/rec/bt/R-REC-BT.2100-0-201607-I!!PDF-E.pdf
 */



/**
 * RGB colour space structure.
 */
typedef struct libclut_rgb_colour_space
{
  /**
   * The x-component of the red colour's xyY value.
   */
  double red_x;
  
  /**
   * The y-component of the red colour's xyY value.
   */
  double red_y;
  
  /**
   * The Y-component of the red colour's xyY value.
   */
  double red_Y;
  
  /**
   * The x-component of the green colour's xyY value.
   */
  double green_x;
  
  /**
   * The y-component of the green colour's xyY value.
   */
  double green_y;
  
  /**
   * The Y-component of the green colour's xyY value.
   */
  double green_Y;
  
  /**
   * The x-component of the blue colour's xyY value.
   */
  double blue_x;
  
  /**
   * The y-component of the blue colour's xyY value.
   */
  double blue_y;
  
  /**
   * The Y-component of the blue colour's xyY value.
   */
  double blue_Y;
  
  /**
   * The x-component of the white point's xyY value.
   */
  double white_x;
  
  /**
   * The y-component of the white point's xyY value.
   */
  double white_y;
  
  /**
   * The Y-component of the white point's xyY value.
   */
  double white_Y;
} libclut_rgb_colour_space_t;



/**
 * Matrix date-type for colour space conversion.
 */
typedef double libclut_colour_space_conversion_matrix_t[3][3];



/* This is to avoid warnings about comparing double, These are only
 * used when it is safe, for example to test whether optimisations
 * are possible. { */
#if defined(__GNUC__) || defined(__clang__)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wfloat-equal"
#endif
static inline int libclut_eq__(double a, double b)  {  return a == b;  }
static inline int libclut_1__(double x)  {  return libclut_eq__(x, 1);  }
static inline int libclut_0__(double x)  {  return libclut_eq__(x, 0);  }
#if defined(__GNUC__) || defined(__clang__)
# pragma GCC diagnostic pop
#endif
/* } */


#if defined(__clang__)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wdocumentation"
#endif



/**
 * Apply contrast correction on the colour curves using sRGB.
 * 
 * In this context, contrast is a measure of difference between
 * the whitepoint and blackpoint, if the difference is 0 than
 * they are both grey.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     The contrast parameter for the red curve.
 * @param  g     The contrast parameter for the green curve.
 * @param  b     The contrast parameter for the blue curve.
 */
#define libclut_rgb_contrast(clut, max, type, r, g, b)						\
  do												\
    {												\
      const double h__ = (double)5 / 10;							\
      if (!libclut_1__(r))									\
	libclut__(clut, red,   type, (LIBCLUT_VALUE - (max) * h__) * (r) + (max) * h__);	\
      if (!libclut_1__(g))									\
	libclut__(clut, green, type, (LIBCLUT_VALUE - (max) * h__) * (g) + (max) * h__);	\
      if (!libclut_1__(b))									\
	libclut__(clut, blue,  type, (LIBCLUT_VALUE - (max) * h__) * (b) + (max) * h__);	\
    }												\
  while (0)


/**
 * Apply contrast correction on the colour curves using CIE xyY.
 * 
 * In this context, contrast is a measure of difference between
 * the whitepoint and blackpoint, if the difference is 0 than
 * they are both grey.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lclut'.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     The contrast parameter for the red curve.
 * @param  g     The contrast parameter for the green curve.
 * @param  b     The contrast parameter for the blue curve.
 */
#define libclut_cie_contrast(clut, max, type, r, g, b)						\
  do												\
    {												\
      const double h__ = (double)5 / 10;							\
      libclut_cie__(clut, max, type, libclut_eq__((r), (g)) && libclut_eq__((g), (b)), 		\
		    !libclut_1__(r), !libclut_1__(g), !libclut_1__(b),				\
		    (Y__ - h__) * (r) + h__, (Y__ - h__) * (g) + h__, (Y__ - h__) * (b) + h__);	\
    }												\
  while (0)


/**
 * Apply brightness correction on the colour curves using sRGB.
 *  
 * In this context, brightness is a measure of the whiteness of the whitepoint.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     The brightness parameter for the red curve.
 * @param  g     The brightness parameter for the green curve.
 * @param  b     The brightness parameter for the blue curve.
 */
#define libclut_rgb_brightness(clut, max, type, r, g, b)			\
  do										\
    {										\
      if (!libclut_1__(r))  libclut__(clut, red,   type, LIBCLUT_VALUE * (r));	\
      if (!libclut_1__(g))  libclut__(clut, green, type, LIBCLUT_VALUE * (g));	\
      if (!libclut_1__(b))  libclut__(clut, blue,  type, LIBCLUT_VALUE * (b));	\
    }										\
  while (0)


/**
 * Apply brightness correction on the colour curves using CIE xyY.
 *  
 * In this context, brightness is a measure of the whiteness of the whitepoint.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lclut'.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     The brightness parameter for the red curve.
 * @param  g     The brightness parameter for the green curve.
 * @param  b     The brightness parameter for the blue curve.
 */
#define libclut_cie_brightness(clut, max, type, r, g, b)				\
  libclut_cie__(clut, max, type, libclut_eq__((r), (g)) && libclut_eq__((g), (b)),	\
		!libclut_1__(r), !libclut_1__(g), !libclut_1__(b),			\
		Y__ * (r), Y__ * (g), Y__ * (b))


/**
 * Convert the curves from formatted in standard RGB to linear sRGB.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lclut', or '-lm' if
 * `libclut_model_standard_to_linear1` is not undefined.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Whether to convert the red colour curve.
 * @param  g     Whether to convert the green colour curve.
 * @param  b     Whether to convert the blue colour curve.
 */
#define libclut_linearise(clut, max, type, r, g, b)							\
  do													\
    {													\
      double m__ = (double)(max);									\
      if (r)												\
	libclut__(clut, red,   type, m__ * libclut_model_standard_to_linear1(LIBCLUT_VALUE / m__));	\
      if (g)												\
	libclut__(clut, green, type, m__ * libclut_model_standard_to_linear1(LIBCLUT_VALUE / m__));	\
      if (b)												\
	libclut__(clut, blue,  type, m__ * libclut_model_standard_to_linear1(LIBCLUT_VALUE / m__));	\
    }													\
  while (0)


/**
 * Convert the curves from formatted in linear sRGB to standard RGB.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lclut', or '-lm' if
 * `libclut_model_linear_to_standard1` is not undefined.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Whether to convert the red colour curve.
 * @param  g     Whether to convert the green colour curve.
 * @param  b     Whether to convert the blue colour curve.
 */
#define libclut_standardise(clut, max, type, r, g, b)							\
  do													\
    {													\
      double m__ = (double)(max);									\
      if (r)												\
	libclut__(clut, red,   type, m__ * libclut_model_linear_to_standard1(LIBCLUT_VALUE / m__));	\
      if (g)												\
	libclut__(clut, green, type, m__ * libclut_model_linear_to_standard1(LIBCLUT_VALUE / m__));	\
      if (b)												\
	libclut__(clut, blue,  type, m__ * libclut_model_linear_to_standard1(LIBCLUT_VALUE / m__));	\
    }													\
  while (0)


/**
 * Convert the curves between two RGB colour spaces.
 * 
 * Both RGB colour spaces must have same gamma functions as sRGB.
 * 
 * Requires that `clut->red_size`, `clut->green_size`
 * and `clut->blue_size` are equal.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lclut', or '-lm' if
 * `libclut_model_linear_to_standard1`,
 * `libclut_model_standard_to_linear1`, or
 * `libclut_model_convert_rgb` is not undefined.
 * 
 * @param  clut   Pointer to the gamma ramps, must have the arrays
 *                `red`, `green`, and `blue`, and the scalars
 *                `red_size`, `green_size`, and `blue_size`. Ramp
 *                structures from libgamma or libcoopgamma can be used.
 * @param  max    The maximum value on each stop in the ramps.
 * @param  type   The data type used for each stop in the ramps.
 * @param  m      Conversion matrix. Can be created with
 *                `libclut_model_get_rgb_conversion_matrix`.
 * @param  trunc  Truncate values that are out of gamut.
 */
#define libclut_convert_rgb_inplace(clut, max, type, m, trunc)			\
  do										\
    {										\
      double m__ = (double)(max), r__, g__, b__;				\
      size_t i__, n__ = (clut)->red_size;					\
      for (i__ = 0; i__ < n__; i__++)						\
	{									\
	  r__ = (clut)->red[i__] / m__;						\
	  g__ = (clut)->green[i__] / m__;					\
	  b__ = (clut)->blue[i__] / m__;					\
	  libclut_model_convert_rgb(r__, g__, b__, m, &r__, &g__, &b__);	\
	  r__ *= m__;								\
	  g__ *= m__;								\
	  b__ *= m__;								\
	  if (trunc)								\
	    {									\
	      if (r__ < 0)							\
		r__ = 0;							\
	      else if (r__ > m__)						\
		r__ = m__;							\
	      if (g__ < 0)							\
		g__ = 0;							\
	      else if (g__ > m__)						\
		g__ = m__;							\
	      if (b__ < 0)							\
		b__ = 0;							\
	      else if (b__ > m__)						\
		b__ = m__;							\
	    }									\
	  (clut)->red[i__] = (type)r__;						\
	  (clut)->green[i__] = (type)g__;					\
	  (clut)->blue[i__] = (type)b__;					\
	}									\
    }										\
  while (0)


/**
 * Convert the curves between two RGB colour spaces.
 * 
 * Both RGB colour spaces must have same gamma functions as sRGB.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lclut' if
 * `libclut_model_linear_to_standard1`,
 * `libclut_model_standard_to_linear1`, or
 * `libclut_model_convert_rgb` is not undefined.
 * Always requires linking with '-lm'.
 * 
 * @param  clut   Pointer to the input gamma ramps, must have the
 *                arrays `red`, `green`, and `blue`, and the scalars
 *                `red_size`, `green_size`, and `blue_size`. Ramp
 *                structures from libgamma or libcoopgamma can be used.
 * @param  max    The maximum value on each stop in the ramps.
 * @param  type   The data type used for each stop in the ramps.
 * @param  m      Conversion matrix. Can be created with
 *                `libclut_model_get_rgb_conversion_matrix`.
 * @param  trunc  Truncate values that are out of gamut.
 * @param  out    Pointer to the output gamma ramps, must have the
 *                arrays `red`, `green`, and `blue`, and the scalars
 *                `red_size`, `green_size`, and `blue_size`. Ramp
 *                structures from libgamma or libcoopgamma can be used.
 */
#define libclut_convert_rgb(clut, max, type, m, trunc, out)		\
  do									\
    {									\
      double m__ = (double)(max), r__, g__, b__, x__, y__;		\
      size_t rn__ = (clut)->red_size;					\
      size_t gn__ = (clut)->green_size;					\
      size_t bn__ = (clut)->blue_size;					\
      double w__;							\
      size_t i__, j__, jj__;						\
      for (i__ = 0; i__ < rn__; i__++)					\
	{								\
	  w__ = (double)i__ * gn__ / rn__;				\
	  j__ = (size_t)w__;						\
	  jj__ = j__ == gn__ ? j__ : (j__ + 1);				\
	  w__ = fmod(j__, (double)1);					\
	  x__ = (clut)->green[j__] / m__;				\
	  y__ = (clut)->green[jj__] / m__;				\
	  x__ = libclut_model_standard_to_linear1(x__);			\
	  y__ = libclut_model_standard_to_linear1(y__);			\
	  g__ = x__ * (1 - w__) + y__ * w__;				\
									\
	  w__ = (double)i__ * bn__ / rn__;				\
	  j__ = (size_t)w__;						\
	  jj__ = j__ == bn__ ? j__ : (j__ + 1);				\
	  w__ = fmod(j__, (double)1);					\
	  x__ = (clut)->blue[j__] / m__;				\
	  y__ = (clut)->blue[jj__] / m__;				\
	  x__ = libclut_model_standard_to_linear1(x__);			\
	  y__ = libclut_model_standard_to_linear1(y__);			\
	  b__ = x__ * (1 - w__) + y__ * w__;				\
									\
	  r__ = (M)[0][0] * r__ + (M)[0][1] * g__ + (M)[0][2] * b__;	\
	  r__ = libclut_model_linear_to_standard1(r__);			\
	  r__ *= m__;							\
	  if (trunc)							\
	    {								\
	      if (r__ < 0)						\
		r__ = 0;						\
	      else if (r__ > m__)					\
		r__ = m__;						\
	    }								\
	  (out)->red[i__] = (type)r__;					\
	}								\
      for (i__ = 0; i__ < gn__; i__++)					\
	{								\
	  w__ = (double)i__ * rn__ / gn__;				\
	  j__ = (size_t)w__;						\
	  jj__ = j__ == rn__ ? j__ : (j__ + 1);				\
	  w__ = fmod(j__, (double)1);					\
	  x__ = (clut)->red[j__] / m__;					\
	  y__ = (clut)->red[jj__] / m__;				\
	  x__ = libclut_model_standard_to_linear1(x__);			\
	  y__ = libclut_model_standard_to_linear1(y__);			\
	  r__ = x__ * (1 - w__) + y__ * w__;				\
									\
	  w__ = (double)i__ * bn__ / gn__;				\
	  j__ = (size_t)w__;						\
	  jj__ = j__ == bn__ ? j__ : (j__ + 1);				\
	  w__ = fmod(j__, (double)1);					\
	  x__ = (clut)->blue[j__] / m__;				\
	  y__ = (clut)->blue[jj__] / m__;				\
	  x__ = libclut_model_standard_to_linear1(x__);			\
	  y__ = libclut_model_standard_to_linear1(y__);			\
	  b__ = x__ * (1 - w__) + y__ * w__;				\
									\
	  g__ = (M)[1][0] * r__ + (M)[0][1] * g__ + (M)[1][2] * b__;	\
	  g__ = libclut_model_linear_to_standard1(g__);			\
	  g__ *= m__;							\
	  if (trunc)							\
	    {								\
	      if (g__ < 0)						\
		g__ = 0;						\
	      else if (g__ > m__)					\
		g__ = m__;						\
	    }								\
	  (out)->green[i__] = (type)g__;				\
	}								\
      for (i__ = 0; i__ < bn__; i__++)					\
	{								\
	  w__ = (double)i__ * rn__ / bn__;				\
	  j__ = (size_t)w__;						\
	  jj__ = j__ == rn__ ? j__ : (j__ + 1);				\
	  w__ = fmod(j__, (double)1);					\
	  x__ = (clut)->red[j__] / m__;					\
	  y__ = (clut)->red[jj__] / m__;				\
	  x__ = libclut_model_standard_to_linear1(x__);			\
	  y__ = libclut_model_standard_to_linear1(y__);			\
	  r__ = x__ * (1 - w__) + y__ * w__;				\
									\
	  w__ = (double)i__ * gn__ / bn__;				\
	  j__ = (size_t)w__;						\
	  jj__ = j__ == gn__ ? j__ : (j__ + 1);				\
	  w__ = fmod(j__, (double)1);					\
	  x__ = (clut)->green[j__] / m__;				\
	  y__ = (clut)->green[jj__] / m__;				\
	  x__ = libclut_model_standard_to_linear1(x__);			\
	  y__ = libclut_model_standard_to_linear1(y__);			\
	  g__ = x__ * (1 - w__) + y__ * w__;				\
									\
	  b__ = (M)[2][0] * r__ + (M)[2][1] * g__ + (M)[2][2] * b__;	\
	  b__ = libclut_model_linear_to_standard1(b__);			\
	  b__ *= m__;							\
	  if (trunc)							\
	    {								\
	      if (b__ < 0)						\
		b__ = 0;						\
	      else if (b__ > m__)					\
		b__ = m__;						\
	    }								\
	  (out)->blue[i__] = (type)b__;					\
	}								\
    }									\
  while (0)


/**
 * Apply gamma correction on the colour curves.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lm'.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     The gamma parameter the red colour curve.
 * @param  g     The gamma parameter the green colour curve.
 * @param  b     The gamma parameter the blue colour curve.
 */
#define libclut_gamma(clut, max, type, r, g, b)						\
  do											\
    {											\
      double m__ = (double)(max);							\
      if (!libclut_1__(r))								\
	libclut__(clut, red,   type, m__ * pow(LIBCLUT_VALUE / m__, 1 / (double)(r)));	\
      if (!libclut_1__(g))								\
	libclut__(clut, green, type, m__ * pow(LIBCLUT_VALUE / m__, 1 / (double)(g)));	\
      if (!libclut_1__(b))								\
	libclut__(clut, blue,  type, m__ * pow(LIBCLUT_VALUE / m__, 1 / (double)(b)));	\
    }											\
  while (0)


/**
 * Reverse the colour curves (negative image with gamma preservation.)
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 *               This parameter is not used, it is just a dummy, to unify
 *               the API with the other functions.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Whether to invert the red colour curve.
 * @param  g     Whether to invert the green colour curve.
 * @param  b     Whether to invert the blue colour curve.
 */
#define libclut_negative(clut, max, type, r, g, b)				\
  do										\
    {										\
      size_t i__, n__;								\
      type t__;									\
      if (r)									\
	for (i__ = 0, n__ = (clut)->red_size; i__ < (n__ >> 1); i__++)		\
	  {									\
	    t__ = (clut)->red[i__];						\
	    (clut)->red[i__] = (clut)->red[n__ - i__ - 1];			\
	    (clut)->red[n__ - i__ - 1] = t__;					\
	  }									\
      if (g)									\
	for (i__ = 0, n__ = (clut)->green_size; i__ < (n__ >> 1); i__++)	\
	  {									\
	    t__ = (clut)->green[i__];						\
	    (clut)->green[i__] = (clut)->green[n__ - i__ - 1];			\
	    (clut)->green[n__ - i__ - 1] = t__;					\
	  }									\
      if (b)									\
	for (i__ = 0, n__ = (clut)->blue_size; i__ < (n__ >> 1); i__++)		\
	  {									\
	    t__ = (clut)->blue[i__];						\
	    (clut)->blue[i__] = (clut)->blue[n__ - i__ - 1];			\
	    (clut)->blue[n__ - i__ - 1] = t__;					\
	  }									\
    }										\
  while (0)


/**
 * Invert the colour curves (negative image with gamma invertion), using sRGB.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Whether to invert the red colour curve.
 * @param  g     Whether to invert the green colour curve.
 * @param  b     Whether to invert the blue colour curve.
 */
#define libclut_rgb_invert(clut, max, type, r, g, b)			\
  do									\
    {									\
      if (r)  libclut__(clut, red,   type, (max) - LIBCLUT_VALUE);	\
      if (g)  libclut__(clut, green, type, (max) - LIBCLUT_VALUE);	\
      if (b)  libclut__(clut, blue,  type, (max) - LIBCLUT_VALUE);	\
    }									\
  while (0)


/**
 * Invert the colour curves (negative image with gamma invertion), using CIE xyY.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lclut'.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Whether to invert the red colour curve.
 * @param  g     Whether to invert the green colour curve.
 * @param  b     Whether to invert the blue colour curve.
 */
#define libclut_cie_invert(clut, max, type, r, g, b)						\
  libclut_cie__(clut, max, type, (r) && (g) && (b), r, g, b, 1 - Y__, 1 - Y__, 1 - Y__)


/**
 * Apply S-curve correction on the colour curves.
 * This is intended for fine tuning LCD monitors,
 * 4.5 is good value start start testing at.
 * You would probably like to use rgb_limits before
 * this to adjust the blackpoint as that is the
 * only way to adjust the blackpoint on many LCD
 * monitors.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lm'.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  rp    Pointer to the sigmoid parameter for the red curve. `NULL` for no adjustment.
 * @param  gp    Pointer to the sigmoid parameter for the green curve. `NULL` for no adjustment.
 * @param  bp    Pointer to the sigmoid parameter for the blue curve. `NULL` for no adjustment.
 */
#define libclut_sigmoid(clut, max, type, rp, gp, bp)		\
  do								\
    {								\
      double *gcc_6_1_1_workaround, m__ = (double)(max);	\
      const double h__ = (double)5 / 10;			\
      gcc_6_1_1_workaround = rp;				\
      if (gcc_6_1_1_workaround)					\
	libclut_sigmoid__(clut, max, type, red);		\
      gcc_6_1_1_workaround = gp;				\
      if (gcc_6_1_1_workaround)					\
	libclut_sigmoid__(clut, max, type, green);		\
      gcc_6_1_1_workaround = bp;				\
      if (gcc_6_1_1_workaround)					\
	libclut_sigmoid__(clut, max, type, blue);		\
    }								\
  while (0)


/**
 * Apply S-curve correction on the colour curves.
 * This is intended for fine tuning LCD monitors,
 * 4.5 is good value start start testing at.
 * You would probably like to use rgb_limits before
 * this to adjust the blackpoint as that is the
 * only way to adjust the blackpoint on many LCD
 * monitors.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lm'.
 * 
 * Intended for internal use.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  channel  The channel, must be either "red", "green", or "blue".
 */
#define libclut_sigmoid__(clut, max, type, channel)			\
  do									\
    {									\
      double s__ = *gcc_6_1_1_workaround, l__;				\
      size_t i__;							\
      for (i__ = 0; i__ < (clut)->channel##_size; i__++)		\
	{								\
	  l__ = log(m__ / (clut)->channel[i__] - 1);			\
	  if (isnan(l__) || isinf(l__))					\
	    l__ = 37.024483 * (isinf(l__) > 0 ? +1 : -1);		\
	  (clut)->channel[i__] = (type)(m__ * (h__ - l__ / s__));	\
	}								\
    }									\
  while (0)


/**
 * Changes the blackpoint and the whitepoint, using sRGB.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  rmin  The red component value of the blackpoint.
 * @param  rmax  The red component value of the whitepoint.
 * @param  gmin  The green component value of the blackpoint.
 * @param  gmax  The green component value of the whitepoint.
 * @param  bmin  The blue component value of the blackpoint.
 * @param  bmax  The blue component value of the whitepoint.
 */
#define libclut_rgb_limits(clut, max, type, rmin, rmax, gmin, gmax, bmin, bmax)			\
  do												\
    {												\
      double diff__;										\
      if (!libclut_0__(rmin) || !libclut_1__(rmax))						\
	{											\
	  diff__ = (double)(rmax) - (double)(rmin);						\
	  libclut__(clut, red, type, LIBCLUT_VALUE / (double)(max) * diff__ + (rmin));		\
	}											\
      if (!libclut_0__(gmin) || !libclut_1__(gmax))						\
	{											\
	  diff__ = (double)(gmax) - (double)(gmin);						\
	  libclut__(clut, green, type, LIBCLUT_VALUE / (double)(max) * diff__ + (gmin));	\
	}											\
      if (!libclut_0__(bmin) || !libclut_1__(bmax))						\
	{											\
	  diff__ = (double)(bmax) - (double)(bmin);						\
	  libclut__(clut, blue, type, LIBCLUT_VALUE / (double)(max) * diff__ + (bmin));		\
	}											\
    }												\
  while (0)


/**
 * Changes the blackpoint and the whitepoint, using CIE xyY.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lclut'.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  rmin  The red component value of the blackpoint.
 * @param  rmax  The red component value of the whitepoint.
 * @param  gmin  The green component value of the blackpoint.
 * @param  gmax  The green component value of the whitepoint.
 * @param  bmin  The blue component value of the blackpoint.
 * @param  bmax  The blue component value of the whitepoint.
 */
#define libclut_cie_limits(clut, max, type, rmin, rmax, gmin, gmax, bmin, bmax)		\
  do											\
    {											\
      double rd__ = (rmax) - (rmin), gd__ = (gmax) - (gmin), bd__ = (bmax) - (bmin);	\
      libclut_cie__(clut, max, type,							\
		    libclut_eq__((rmin), (gmin)) && libclut_eq__((gmin), (bmin)) &&	\
		    libclut_eq__((rmax), (gmax)) && libclut_eq__((gmax), (bmax)),	\
		    !libclut_0__(rmin) || !libclut_1__(rmax),				\
		    !libclut_0__(gmin) || !libclut_1__(gmax),				\
		    !libclut_0__(bmin) || !libclut_1__(bmax),				\
		    Y__ * rd__ + (rmin), Y__ * gd__ + (gmin), Y__ * bd__ + (bmin));	\
    }											\
  while (0)


/**
 * Manipulate the colour curves using a function on the sRGB colour space.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Function to manipulate the red colour curve, should either
 *               be `NULL` or map a [0, 1] `double` to a [0, 1] `double`.
 * @param  g     Function to manipulate the green colour curve, should either
 *               be `NULL` or map a [0, 1] `double` to a [0, 1] `double`.
 * @param  b     Function to manipulate the blue colour curve, should either
 *               be `NULL` or map a [0, 1] `double` to a [0, 1] `double`.
 */
#define libclut_manipulate(clut, max, type, r, g, b)						\
  do												\
    {												\
      double m__ = (double)(max);								\
      double (*gcc_6_1_1_workaround__)(double);							\
      gcc_6_1_1_workaround__ = r;								\
      if (gcc_6_1_1_workaround__)	       							\
	libclut__(clut, red,   type, m__ * (gcc_6_1_1_workaround__)(LIBCLUT_VALUE / m__));	\
      gcc_6_1_1_workaround__ = g;								\
      if (gcc_6_1_1_workaround__)								\
	libclut__(clut, green, type, m__ * (gcc_6_1_1_workaround__)(LIBCLUT_VALUE / m__));	\
      gcc_6_1_1_workaround__ = b;								\
      if (gcc_6_1_1_workaround__)								\
	libclut__(clut, blue,  type, m__ * (gcc_6_1_1_workaround__)(LIBCLUT_VALUE / m__));	\
    }												\
  while (0)


/**
 * Manipulate the colour curves using a function on the CIE xyY colour space.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lclut'.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Function to manipulate the red colour curve, should either
 *               be `NULL` or map a [0, 1] `double` to a [0, 1] `double`.
 * @param  g     Function to manipulate the green colour curve, should either
 *               be `NULL` or map a [0, 1] `double` to a [0, 1] `double`.
 * @param  b     Function to manipulate the blue colour curve, should either
 *               be `NULL` or map a [0, 1] `double` to a [0, 1] `double`.
 */
#define libclut_cie_manipulate(clut, max, type, r, g, b)					\
  libclut_cie__(clut, max, type, (r) && (g) && (b), r, g, b, (r)(Y__), (g)(Y__), (b)(Y__))


/**
 * Resets colour curvers to linear mappings.
 * (Identity mapping if imaginged to map from [0, 1] to [0, 1].)
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Whether to reset the red colour curve.
 * @param  g     Whether to reset the green colour curve.
 * @param  b     Whether to reset the blue colour curve.
 */
#define libclut_start_over(clut, max, type, r, g, b)			\
  do									\
    {									\
      size_t i__;							\
      double m__, max__ = (double)(max);				\
      if (r)								\
	{								\
	  m__ = (double)((clut)->red_size - 1);				\
	  for (i__ = 0; i__ < (clut)->red_size; i__++)			\
	    (clut)->red[i__] = (type)(((double)i__ / m__) * max__);	\
	}								\
      if (g)								\
	{								\
	  m__ = (double)((clut)->green_size - 1);			\
	  for (i__ = 0; i__ < (clut)->green_size; i__++)		\
	    (clut)->green[i__] = (type)(((double)i__ / m__) * max__);	\
	}								\
      if (b)								\
	{								\
	  m__ = (double)((clut)->blue_size - 1);			\
	  for (i__ = 0; i__ < (clut)->blue_size; i__++)			\
	    (clut)->blue[i__] = (type)(((double)i__ / m__) * max__);	\
	}								\
    }									\
  while (0)


/**
 * Clip colour curves to only map to values between the minimum and maximum.
 * This should be done, before apply the curves, and before applying changes
 * with limited domain.
 * 
 * Values below 0 are set to 0, and values above `max` are set to `max`.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Whether to clip the red colour curve.
 * @param  g     Whether to clip the green colour curve.
 * @param  b     Whether to clip the blue colour curve.
 */
#define libclut_clip(clut, max, type, r, g, b)						\
  do											\
    {											\
      if (r)  libclut__(clut, red,   type, libclut_clip__(0, LIBCLUT_VALUE, max));	\
      if (g)  libclut__(clut, green, type, libclut_clip__(0, LIBCLUT_VALUE, max));	\
      if (b)  libclut__(clut, blue,  type, libclut_clip__(0, LIBCLUT_VALUE, max));	\
    }											\
  while (0)

/**
 * Truncates a value to fit a boundary.
 * 
 * None of the parameter may have side-effects.
 * 
 * Intended for internal use.
 * 
 * @param   min  The minimum allowed value.
 * @param   val  The current value.
 * @param   max  The maximum allowed value.
 * @return       The value truncated into its boundary.
 */
#define libclut_clip__(min, val, max)							\
  (LIBCLUT_VALUE < (min) ? (min) : LIBCLUT_VALUE > (max) ? (max) : LIBCLUT_VALUE)


/**
 * Emulates low colour resolution.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  rx    The desired emulated red encoding resolution, 0 for unchanged.
 * @param  ry    The desired emulated red output resolution, 0 for unchanged.
 * @param  gx    The desired emulated green encoding resolution, 0 for unchanged.
 * @param  gy    The desired emulated green output resolution, 0 for unchanged.
 * @param  bx    The desired emulated blue encoding resolution, 0 for unchanged.
 * @param  by    The desired emulated blue output resolution, 0 for unchanged.
 */
#define libclut_lower_resolution(clut, max, type, rx, ry, gx, gy, bx, by)	\
  do										\
    {										\
      libclut_lower_resolution__(clut, red,   max, type, rx, ry);		\
      libclut_lower_resolution__(clut, green, max, type, gx, gy);		\
      libclut_lower_resolution__(clut, blue,  max, type, bx, by);		\
    }										\
  while (0)


/**
 * Emulates low colour resolution of a channel.
 * 
 * None of the parameter may have side-effects.
 * 
 * Intended for internal use.
 * 
 * @param  clut     Pointer to the gamma ramps, must have the arrays
 *                  `red`, `green`, and `blue`, and the scalars
 *                  `red_size`, `green_size`, and `blue_size`. Ramp
 *                  structures from libgamma or libcoopgamma can be used.
 * @param  channel  The channel, must be either "red", "green", or "blue".
 * @param  max      The maximum value on each stop in the ramps.
 * @param  type     The data type used for each stop in the ramps.
 * @param  x        The desired emulated encoding resolution, 0 for unchanged.
 * @param  y        The desired emulated output resolution, 0 for unchanged.
 */
#define libclut_lower_resolution__(clut, channel, max, type, x, y)			\
  do											\
    if ((x) || (y))									\
      {											\
	size_t x__, y__, i__, n__ = (clut)->channel##_size;				\
	double xm__ = (double)((x) - 1), ym__ = (double)((y) - 1);			\
	double m__ = (double)(max), nm__ = (double)(n__ - 1);				\
	type c__[n__]; /* Do not use alloca! */						\
	const double h__ = (double)5 / 10;						\
	for (i__ = 0; i__ < n__; i__++)							\
	  {										\
	    if ((x__ = i__), (x))							\
	      {										\
		x__ = (size_t)((double)i__ * (double)(x) / (double)n__);		\
		x__ = (size_t)((double)x__ * nm__ / xm__);				\
	      }										\
	    if (!(y))									\
	      c__[i__] = (clut)->channel[x__];						\
	    else									\
	      {										\
		y__ = (size_t)((double)((clut)->channel[x__]) / (max) * ym__ + h__);	\
		c__[i__] = (type)((double)y__ / ym__ * m__);				\
	      }										\
	  }										\
	memcpy((clut)->channel, c__, n__ * sizeof(type));				\
      }											\
  while (0)


/**
 * Translates a gamma ramp structure to another gamma ramp structure type.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  dclut  Pointer to the desired gamma ramps, must have the arrays
 *                `red`, `green`, and `blue`, and the scalars `red_size`,
 *                `green_size`, and `blue_size`. Ramp structures from
 *                libgamma or libcoopgamma can be used.
 * @param  dmax   The maximum value on each stop in the ramps in `dclut`.
 * @param  dtype  The data type used for each stop in the ramps in `dclut`.
 * @param  sclut  Pointer to the set gamma ramps, must have the arrays
 *                `red`, `green`, and `blue`, and the scalars `red_size`,
 *                `green_size`, and `blue_size`. Ramp structures from
 *                libgamma or libcoopgamma can be used.
 * @param  smax   The maximum value on each stop in the ramps in `sclut`.
 * @param  stype  The data type used for each stop in the ramps in `sclut`.
 *                (Not actually used.)
 */
#define libclut_translate(dclut, dmax, dtype, sclut, smax, stype)		\
  do										\
    {										\
      libclut_translate__(dclut, dmax, dtype, sclut, smax, stype, red);		\
      libclut_translate__(dclut, dmax, dtype, sclut, smax, stype, green);	\
      libclut_translate__(dclut, dmax, dtype, sclut, smax, stype, blue);	\
    }										\
  while (0)

/**
 * Translates a gamma ramp structure to another gamma ramp structure type.
 * 
 * None of the parameter may have side-effects.
 * 
 * This is intended for internal use.
 * 
 * @param  dclut    Pointer to the desired gamma ramps, must have the arrays
 *                  `red`, `green`, and `blue`, and the scalars `red_size`,
 *                  `green_size`, and `blue_size`. Ramp structures from
 *                  libgamma or libcoopgamma can be used.
 * @param  dmax     The maximum value on each stop in the ramps in `dclut`.
 * @param  dtype    The data type used for each stop in the ramps in `dclut`.
 * @param  sclut    Pointer to the set gamma ramps, must have the arrays
 *                  `red`, `green`, and `blue`, and the scalars `red_size`,
 *                  `green_size`, and `blue_size`. Ramp structures from
 *                  libgamma or libcoopgamma can be used.
 * @param  smax     The maximum value on each stop in the ramps in `sclut`.
 * @param  stype    The data type used for each stop in the ramps in `sclut`.
 *                  (Not actually used.)
 * @param  channel  The channel, must be either "red", "green", or "blue".
 */
#define libclut_translate__(dclut, dmax, dtype, sclut, smax, stype, channel)	\
  do										\
    {										\
      size_t di__, si__, sj__;							\
      size_t dn__ = (dclut)->channel##_size;					\
      size_t sn__ = (sclut)->channel##_size;					\
      double dm__ = (double)(dmax);						\
      double sm__ = (double)(smax);						\
      double dmsm__ = dm__ / sm__;						\
      double x__, y__;								\
      if (dn__ == sn__)								\
	for (di__ = 0; di__ < dn__; di__++)					\
	  {									\
	    y__ = (double)((sclut)->channel[di__]) * dmsm__;			\
	    (dclut)->channel[di__] = (dtype)y__;				\
	  }									\
      else									\
	for (di__ = 0; di__ < dn__; di__++)					\
	  {									\
	    x__ = di__ / (dn__ - 1) * (sn__ - 1);				\
	    si__ = (size_t)(x__);						\
	    sj__ = si__ + (si__ != sn__);					\
	    x__ -= (double)si__;						\
	    y__  = (double)((sclut)->channel[si__]) * (1 - x__);		\
	    y__ += (double)((sclut)->channel[sj__]) * (x__);			\
	    y__ *= dmsm__;							\
	    (dclut)->channel[di__] = (dtype)y__;				\
	  }									\
    }										\
  while (0)


/**
 * Applies a filter or calibration.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  clut    Pointer to the gamma ramps, must have the arrays
 *                 `red`, `green`, and `blue`, and the scalars
 *                 `red_size`, `green_size`, and `blue_size`. Ramp
 *                 structures from libgamma or libcoopgamma can be used.
 * @param  max     The maximum value on each stop in the ramps.
 * @param  type    The data type used for each stop in the ramps.
 * @param  filter  Same as `clut`, but for the filter to apply.
 * @param  fmax    Same as `max`, but for the filter to apply.
 * @param  ftype   Same as `type`, but for the filter to apply. (Not actually used).
 * @param  r       Whether to apply the filter for the red curve.
 * @param  g       Whether to apply the filter for the green curve.
 * @param  b       Whether to apply the filter for the blue curve.
 */
#define libclut_apply(clut, max, type, filter, fmax, ftype, r, g, b)		\
  do										\
    {										\
      if (r)  libclut_apply__(clut, max, type, filter, fmax, ftype, red);	\
      if (g)  libclut_apply__(clut, max, type, filter, fmax, ftype, green);	\
      if (b)  libclut_apply__(clut, max, type, filter, fmax, ftype, blue);	\
    }										\
  while (0)


/**
 * Applies a filter or calibration for one channel.
 * 
 * None of the parameter may have side-effects.
 * 
 * Intended for internal use.
 * 
 * @param  clut     Pointer to the gamma ramps, must have the arrays
 *                  `red`, `green`, and `blue`, and the scalars
 *                  `red_size`, `green_size`, and `blue_size`. Ramp
 *                  structures from libgamma or libcoopgamma can be used.
 * @param  max      The maximum value on each stop in the ramps.
 * @param  type     The data type used for each stop in the ramps.
 * @param  filter   Same as `clut`, but for the filter to apply.
 * @param  fmax     Same as `max`, but for the filter to apply.
 * @param  ftype    Same as `type`, but for the filter to apply. (Not actually used).
 * @param  channel  The channel, must be either "red", "green", or "blue".
 */
#define libclut_apply__(clut, max, type, filter, fmax, ftype, channel)				\
  do												\
    {												\
      size_t i__, rn__ = (clut)->channel##_size, fn__ = (filter)->channel##_size - 1;		\
      double x__, rm__ = (double)(max), m__ = (double)(max) / (double)(fmax);			\
      for (i__ = 0; i__ < rn__; i__++)								\
	{											\
	  x__ = (double)((clut)->channel[i__]) / rm__ * (double)fn__;				\
	  (clut)->channel[i__] = (type)((double)((filter)->channel[(size_t)x__]) * m__);	\
	}											\
    }												\
  while (0)


/**
 * Applies a filter or calibration, using CIE xyY.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lclut'.
 * 
 * @param  clut    Pointer to the gamma ramps, must have the arrays
 *                 `red`, `green`, and `blue`, and the scalars
 *                 `red_size`, `green_size`, and `blue_size`. Ramp
 *                 structures from libgamma or libcoopgamma can be used.
 * @param  max     The maximum value on each stop in the ramps.
 * @param  type    The data type used for each stop in the ramps.
 * @param  filter  Same as `clut`, but for the filter to apply.
 * @param  fmax    Same as `max`, but for the filter to apply.
 * @param  ftype   Same as `type`, but for the filter to apply. (Not actually used).
 * @param  r       Whether to apply the filter for the red curve.
 * @param  g       Whether to apply the filter for the green curve.
 * @param  b       Whether to apply the filter for the blue curve.
 */
#define libclut_cie_apply(clut, max, type, filter, fmax, ftype, r, g, b)				\
  do													\
    {													\
      size_t rfn__ = (filter)->red_size - 1, gfn__ = (filter)->green_size - 1;				\
      size_t bfn__ = (filter)->blue_size - 1, x__;							\
      size_t rm__ = (double)(max), fm__ = (double)(fmax);						\
      libclut_cie__(clut, max, type, 0, r, g, b,							\
		    (x__ = (size_t)(Y__ / rm__ * rfn__), (double)((filter)->red[x__])   / fm__),	\
		    (x__ = (size_t)(Y__ / rm__ * gfn__), (double)((filter)->green[x__]) / fm__),	\
		    (x__ = (size_t)(Y__ / rm__ * bfn__), (double)((filter)->blue[x__])  / fm__));	\
    }													\
  while (0)


/**
 * Modify a ramp.
 * 
 * None of the parameter may have side-effects.
 * 
 * This is intended for internal use.
 * 
 * @param  clut     Pointer to the gamma ramps, must have and array
 *                  named `channel` and a scalar named `channel` followed
 *                  by "_size".
 * @param  channel  The channel, must be either "red", "green", or "blue".
 * @param  type     The data type used for each stop in the ramps.
 * @param  expr     Expression that evalutes the value a stop should have.
 *                  It can use the variable `LIBCLUT_VALUE` to get the
 *                  current value of the stop.
 */
#define libclut__(clut, channel, type, expr)		\
  do							\
    {							\
      size_t i__, n__ = (clut)->channel##_size;		\
      type LIBCLUT_VALUE;				\
      for (i__ = 0; i__ < n__; i__++)			\
	{						\
	  LIBCLUT_VALUE = (clut)->channel[i__];		\
	  (clut)->channel[i__] = (type)(expr);		\
	}						\
    }							\
  while (0)


/**
 * Modify a ramp set in CIE xyY.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lclut'.
 * 
 * This is intended for internal use.
 * 
 * @param  clut   Pointer to the gamma ramps, must have the arrays
 *                `red`, `green`, and `blue`, and the scalars
 *                `red_size`, `green_size`, and `blue_size`. Ramp
 *                structures from libgamma or libcoopgamma can be used.
 * @param  max    The maximum value on each stop in the ramps.
 * @param  type   The data type used for each stop in the ramps.
 * @param  utest  Whether all channels can be modified at the same time.
 *                This test does not have to include the ramp size.
 * @param  rtest  Whether the red channel have to be modified.
 * @param  gtest  Whether the green channel have to be modified.
 * @param  btest  Whether the blue channel have to be modified.
 * @param  rexpr  Expression calculating the intensity of the red channel.
 *                The current value is stored in `Y__`.
 * @param  gexpr  Expression calculating the intensity of the green channel.
 *                The current value is stored in `Y__`.
 * @param  bexpr  Expression calculating the intensity of the blue channel.
 *                The current value is stored in `Y__`.
 */
#define libclut_cie__(clut, max, type, utest, rtest, gtest, btest, rexpr, gexpr, bexpr)	\
  do											\
    {											\
      size_t rn__ = (clut)->red_size;							\
      size_t gn__ = (clut)->green_size;							\
      size_t bn__ = (clut)->blue_size;							\
      size_t i__;									\
      double x__, y__, Y__, r__, g__, b__;						\
      double m__ = (double)(max);							\
      type* rs__ = (clut)->red;								\
      type* gs__ = (clut)->green;							\
      type* bs__ = (clut)->blue;							\
      if ((rn__ == gn__) && (gn__ == bn__) && (utest))					\
	{										\
	  if (!(rtest))									\
	    break;									\
	  for (i__ = 0; i__ < rn__; i__++)						\
	    {										\
	      libclut_model_srgb_to_ciexyy(rs__[i__] / m__, gs__[i__] / m__,		\
					   bs__[i__] / m__, &x__, &y__, &Y__);		\
	      libclut_model_ciexyy_to_srgb(x__, y__, rexpr, &r__, &g__, &b__);		\
	      rs__[i__] = (type)(r__ * m__);						\
	      gs__[i__] = (type)(g__ * m__);						\
	      bs__[i__] = (type)(b__ * m__);						\
	    }										\
	}										\
      else if ((rn__ == gn__) && (gn__ == bn__))					\
	{										\
	  if (!(rtest) && !(gtest) && !(btest))						\
	    break;									\
	  for (i__ = 0; i__ < rn__; i__++)						\
	    {										\
	      libclut_model_srgb_to_ciexyy(rs__[i__] / m__, gs__[i__] / m__,		\
					   bs__[i__] / m__, &x__, &y__, &Y__);		\
	      if (rtest)								\
		{									\
		  libclut_model_ciexyy_to_srgb(x__, y__, rexpr, &r__, &g__, &b__);	\
		  rs__[i__] = (type)(r__ * m__);					\
		}									\
	      if (gtest)								\
		{									\
		  libclut_model_ciexyy_to_srgb(x__, y__, gexpr, &r__, &g__, &b__);	\
		  gs__[i__] = (type)(g__ * m__);					\
		}									\
	      if (btest)								\
		{									\
		  libclut_model_ciexyy_to_srgb(x__, y__, bexpr, &r__, &g__, &b__);	\
		  bs__[i__] = (type)(b__ * m__);					\
		}									\
	    }										\
	}										\
      else										\
	{										\
	  if (rtest)									\
	    for (i__ = 0; i__ < rn__; i__++)						\
	    libclut_cie___(clut, max, type, r, rexpr, i__,				\
			   libclut_i__(i__, rn__, gn__),				\
			   libclut_i__(i__, rn__, bn__));				\
	  if (gtest)									\
	    for (i__ = 0; i__ < rn__; i__++)						\
	    libclut_cie___(clut, max, type, g, gexpr,					\
			   libclut_i__(i__, gn__, rn__), i__,				\
			   libclut_i__(i__, gn__, bn__));				\
	  if (btest)									\
	    for (i__ = 0; i__ < rn__; i__++)						\
	    libclut_cie___(clut, max, type, b, bexpr,					\
			   libclut_i__(i__, bn__, rn__),				\
			   libclut_i__(i__, bn__, gn__), i__);				\
	}										\
    }											\
  while (0)


/**
 * Modify a ramp stop in CIE xyY.
 * 
 * None of the parameter may have side-effects.
 * 
 * Requires linking with '-lclut'.
 * 
 * This is intended for internal use.
 * Assumes the existence of variables defined in `libclut_cie__`.
 * 
 * @param  clut  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma or libcoopgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  c     Either "r" for red, "g" for green, or "b" for blue.
 * @param  expr  Expression calculating the intensity of the channel.
 * @param  ri    The index of the stop translated to the red channel.
 * @param  gi    The index of the stop translated to the green channel.
 * @param  bi    The index of the stop translated to the blue channel.
 */
#define libclut_cie___(clut, max, type, c, expr, ri, gi, bi)			\
  do										\
    {										\
      for (i__ = 0; i__ < c##n__; i__++)					\
	{									\
	  libclut_model_srgb_to_ciexyy(rs__[(ri)] / m__, gs__[(gi)] / m__,	\
				       bs__[(bi)] / m__, &x__, &y__, &Y__);	\
	  libclut_model_ciexyy_to_srgb(x__, y__, expr, &r__, &g__, &b__);	\
	  c##s__[i__] = (type)(c##__ * m__);					\
	}									\
    }										\
  while (0)


/**
 * Translate an index from one channel to another.
 * 
 * @param   i    The index in the input channel.
 * @param   in   The size of the input channel.
 * @param   out  The size of the output channel.
 * @return       The index in the output channel.
 */
#define libclut_i__(i, in, out)				\
  (size_t)((double)(i) * (double)(out) / (double)(in))



#if defined(__GNUC__) && !defined(__clang__)
# define LIBCLUT_GCC_ONLY__(x)  x
#else
# define LIBCLUT_GCC_ONLY__(x)  /* do nothing */
#endif



/**
 * Convert one component from [0, 1] linear sRGB to [0, 1] sRGB.
 * 
 * If the macro variant is used, the argument must not have
 * any side-effects. The macro variant requires linking with
 * '-lm'.
 * 
 * @param   c  The linear sRGB value.
 * @return     Corresponding sRGB value.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__const__, __leaf__)))
double (libclut_model_linear_to_standard1)(double);
#define libclut_model_linear_to_standard1(c)  \
  (((double)(c) <= 0.0031308) ? (12.92 * (double)(c)) : ((1.055) * pow((double)(c), 1 / 2.4) - 0.055))


/**
 * Convert [0, 1] linear sRGB to [0, 1] sRGB.
 * 
 * The macro variant requires linking with '-lm',
 * if the 'libclut_model_linear_to_standard1' is defined,
 * otherwise it requires linking with '-lclut'.
 * 
 * @param  r  Pointer to the linear red component,
 *            and output parameter for the red component.
 * @param  g  Pointer to the linear green component,
 *            and output parameter for the green component.
 * @param  b  Pointer to the linear blue component,
 *            and output parameter for the blue component.
 */
void (libclut_model_linear_to_standard)(double*, double*, double*);
#define libclut_model_linear_to_standard(r, g, b)	\
  do							\
    {							\
      double *r__ = (r), *g__ = (g), *b__ = (b);	\
      *r__ = libclut_model_linear_to_standard1(*r__);	\
      *g__ = libclut_model_linear_to_standard1(*g__);	\
      *b__ = libclut_model_linear_to_standard1(*b__);	\
    }							\
  while (0)


/**
 * Convert one component from [0, 1] sRGB to [0, 1] linear sRGB.
 * 
 * If the macro variant is used, the argument must not have
 * any side-effects. The macro variant requires linking with
 * '-lm'.
 * 
 * @param   c  The sRGB value.
 * @return     Corresponding linear sRGB value.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__const__, __leaf__)))
double (libclut_model_standard_to_linear1)(double);
#define libclut_model_standard_to_linear1(c)  \
  (((double)(c) <= 0.04045) ? ((double)(c) / 12.92) : pow(((double)(c) + 0.055) / 1.055, 2.4))


/**
 * Convert [0, 1] sRGB to [0, 1] linear sRGB.
 * 
 * The macro variant requires linking with '-lm',
 * if the 'libclut_model_standard_to_linear1' is defined,
 * otherwise it requires linking with '-lclut'.
 * 
 * @param  r  Pointer to the red component, and output
 *            parameter for the linear red component.
 * @param  g  Pointer to the green component, and output
 *            parameter for the linear green component.
 * @param  b  Pointer to the blue component, and output
 *            parameter for the linear blue component.
 */
void (libclut_model_standard_to_linear)(double*, double*, double*);
#define libclut_model_standard_to_linear(r, g, b)	\
  do							\
    {							\
      double *r__ = (r), *g__ = (g), *b__ = (b);	\
      *r__ = libclut_model_standard_to_linear1(*r__);	\
      *g__ = libclut_model_standard_to_linear1(*g__);	\
      *b__ = libclut_model_standard_to_linear1(*b__);	\
    }							\
  while (0)


/**
 * Convert CIE xyY to CIE XYZ.
 * 
 * @param  x  The x parameter.
 * @param  y  The y parameter.
 * @param  Y  The Y parameter. This is also the Y (middle) parameter for the CIE XYZ colour.
 * @param  X  Output parameter for the X parameter.
 * @param  Z  Output parameter for the Z parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_ciexyy_to_ciexyz)(double, double, double, double*, double*);
#define libclut_model_ciexyy_to_ciexyz(x, y, Y, X, Z)			\
  do									\
    {									\
      double x__ = (x), y__ = (y), Y__ = (Y), *X__ = (X), *Z__ = (Z);	\
      *X__ = libclut_0__(y__) ? Y__ : (Y__ * x__ / y__);		\
      *Z__ = libclut_0__(y__) ? Y__ : (Y__ * (1 - x__ - y__) / y__);	\
    }									\
  while (0)


/**
 * Convert CIE XYZ to CIE xyY.
 * 
 * @param  X  The X parameter.
 * @param  Y  The Y parameter. This is also the Y (last) parameter for the CIE xyY colour.
 * @param  Z  The Z parameter.
 * @param  x  Output parameter for the x parameter.
 * @param  y  Output parameter for the y parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_ciexyz_to_ciexyy)(double, double, double, double*, double*);
#define libclut_model_ciexyz_to_ciexyy(X, Y, Z, x, y)			\
  do									\
    {									\
      double X__ = (X), Y__ = (Y), Z__ = (Z), *x__ = (x), *y__ = (y);	\
      double s__ = X__ + Y__ + Z__;					\
      if (libclut_0__(s__))						\
	*x__ = *y__ = 0;						\
      else								\
	*x__ = X__ / s__, *y__ = Y__ / s__;				\
    }									\
  while (0)


/**
 * Convert CIE XYZ to [0, 1] linear sRGB.
 * 
 * @param  X  The X parameter.
 * @param  Y  The Y parameter.
 * @param  Z  The Z parameter.
 * @param  r  Output parameter for the red component.
 * @param  g  Output parameter for the green component.
 * @param  b  Output parameter for the blue component.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_ciexyz_to_linear)(double, double, double, double*, double*, double*);
#define libclut_model_ciexyz_to_linear(X, Y, Z, r, g, b)			\
  do										\
    {										\
      double X__ = (X), Y__ = (Y), Z__ = (Z);					\
      *(r) = ( 3.2404500 * X__) + (-1.537140 * Y__) + (-0.4985320 * Z__);	\
      *(g) = (-0.9692660 * X__) + ( 1.876010 * Y__) + ( 0.0415561 * Z__);	\
      *(b) = ( 0.0556434 * X__) + (-0.204026 * Y__) + ( 1.0572300 * Z__);	\
    }										\
  while (0)


/**
 * Convert [0, 1] linear sRGB to CIE XYZ.
 * 
 * @param  r  The red component.
 * @param  g  The green component.
 * @param  b  The blue component.
 * @param  X  Output parameter for the X parameter.
 * @param  Y  Output parameter for the Y parameter.
 * @param  Z  Output parameter for the Z parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_linear_to_ciexyz)(double, double, double, double*, double*, double*);
#define libclut_model_linear_to_ciexyz(r, g, b, X, Y, Z)			\
  do										\
    {										\
      double r__ = (r), g__ = (g), b__ = (b);					\
      *(X) = (0.4124564 * r__) + (0.3575761 * g__) + (0.1804375 * b__);		\
      *(Y) = (0.2126729 * r__) + (0.7151522 * g__) + (0.0721750 * b__);		\
      *(Z) = (0.0193339 * r__) + (0.1191920 * g__) + (0.9503041 * b__);		\
    }										\
  while (0)


/**
 * Convert [0, 1] sRGB to CIE xyY.
 * 
 * The macro variant requires linking with '-lclut'
 * if any of `libclut_model_ciexyz_to_ciexyy`,
 * `libclut_model_linear_to_ciexyz`, and
 * `libclut_model_standard_to_linear` are undefined.
 * The macro variant requires linking with '-lm' if
 * neither `libclut_model_standard_to_linear` nor
 * `libclut_model_standard_to_linear1` are undefined.
 * 
 * @param  r  The red component.
 * @param  g  The green component.
 * @param  b  The blue component.
 * @param  x  Output parameter for the x parameter.
 * @param  y  Output parameter for the y parameter.
 * @param  Y  Output parameter for the Y parameter.
 */
void (libclut_model_srgb_to_ciexyy)(double, double, double, double*, double*, double*);
#define libclut_model_srgb_to_ciexyy(r, g, b, x, y, Y)				\
  do										\
    {										\
      double r___ = (r), g___ = (g), b___ = (b);				\
      double *x___ = (x), *y___ = (y), *Y___ = (Y);				\
      double X___, Z___;							\
      libclut_model_standard_to_linear(&r___, &g___, &b___);			\
      libclut_model_linear_to_ciexyz(r___, g___, b___, &X___, Y___, &Z___);	\
      libclut_model_ciexyz_to_ciexyy(X___, *Y___, Z___, x___, y___);		\
    }										\
  while (0)


/**
 * Convert CIE xyY to [0, 1] sRGB.
 * 
 * The macro variant requires linking with '-lclut'
 * if any of `libclut_model_ciexyy_to_ciexyz`,
 * `libclut_model_ciexyz_to_linear`, and
 * `libclut_model_linear_to_standard` are undefined.
 * The macro variant requires linking with '-lm' if
 * neither `libclut_model_linear_to_standard` nor
 * `libclut_model_linear_to_standard1` are undefined.
 * 
 * @param  x  The x parameter.
 * @param  y  The y parameter.
 * @param  Y  The Y parameter.
 * @param  r  Output parameter for the red component.
 * @param  g  Output parameter for the green component.
 * @param  b  Output parameter for the blue component.
 */
void (libclut_model_ciexyy_to_srgb)(double, double, double, double*, double*, double*);
#define libclut_model_ciexyy_to_srgb(x, y, Y, r, g, b)				\
  do										\
    {										\
      double x___ = (x), y___ = (y), Y___ = (Y);				\
      double *r___ = (r), *g___ = (g), *b___ = (b);				\
      double X___, Z___;							\
      libclut_model_ciexyy_to_ciexyz(x___, y___, Y___, &X___, &Z___);		\
      libclut_model_ciexyz_to_linear(X___, Y___, Z___, r___, g___, b___);	\
      libclut_model_linear_to_standard(r___, g___, b___);			\
    }										\
  while(0)


/**
 * Convert from CIE XYZ to CIE L*a*b*.
 * 
 * The macro variant requires linking with '-lm'.
 * 
 * @param  X  The X parameter.
 * @param  Y  The Y parameter.
 * @param  Z  The Z parameter.
 * @param  L  Output parameter for the L* component.
 * @param  a  Output parameter for the a* component.
 * @param  b  Output parameter for the b* component.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_ciexyz_to_cielab)(double, double, double, double*, double*, double*);
#define libclut_model_ciexyz_to_cielab(X, Y, Z, L, a, b)	\
  do								\
    {								\
      double X__ = (X), Y__ = (Y), Z__ = (Z);			\
      X__ /= 0.95047, Z__ /= 1.08883;				\
      X__ = LIBCLUT_MODEL_CIEXYZ_TO_CIELAB__(X__);		\
      Y__ = LIBCLUT_MODEL_CIEXYZ_TO_CIELAB__(Y__);		\
      Z__ = LIBCLUT_MODEL_CIEXYZ_TO_CIELAB__(Z__);		\
      *(L) = 116 * Y__ - 16;					\
      *(a) = 500 * (X__ - Y__);					\
      *(b) = 200 * (Y__ - Z__);					\
    }								\
  while (0)
#define LIBCLUT_MODEL_CIEXYZ_TO_CIELAB__(C)  \
  (((C) > 0.00885642) ? pow((C), 1.0 / 3) : ((7.78 + 703.0 / 99900) * (C) + 0.1379310))


/**
 * Convert from CIE L*a*b* to CIE XYZ.
 * 
 * @param  L  The L* component.
 * @param  a  The a* component.
 * @param  b  The b* component.
 * @param  X  Output parameter for the X parameter.
 * @param  Y  Output parameter for the Y parameter.
 * @param  Z  Output parameter for the Z parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_cielab_to_ciexyz)(double, double, double, double*, double*, double*);
#define libclut_model_cielab_to_ciexyz(L, a, b, X, Y, Z)	\
  do								\
    {								\
      double L__ = (L), a__ = (a), b__ = (b);			\
      double *X__ = (X), *Y__ = (Y), *Z__ = (Z);		\
      *Y__ = (L__ + 16) / 116;					\
      *X__ = a__ / 500 + *Y__;					\
      *Z__ = *Y__ - b__ / 200;					\
      *X__ = LIBCLUT_MODEL_CIELAB_TO_CIEXYZ__(*X__) * 0.95047;	\
      *Y__ = LIBCLUT_MODEL_CIELAB_TO_CIEXYZ__(*Y__);		\
      *Z__ = LIBCLUT_MODEL_CIELAB_TO_CIEXYZ__(*Z__) * 1.08883;	\
    }								\
  while (0)
#define LIBCLUT_MODEL_CIELAB_TO_CIEXYZ__(C)  \
  (((C)*(C)*(C) > 0.00885642) ? ((C)*(C)*(C)) : (((C) - 0.1379310) / (7.78 + 703.0 / 99900)))


/**
 * Convert from CIE XYZ to CIELUV.
 * 
 * Requires linking with `-lm`.
 * 
 * @param  X   The X component.
 * @param  Y   The Y component.
 * @param  Z   The Z component.
 * @param  Xn  The X component of the specified white object (white point).
 * @param  Yn  The Y component of the specified white object (white point).
 * @param  Zn  The Z component of the specified white object (white point).
 * @param  L   Output parameter for the L* parameter.
 * @param  u   Output parameter for the u* parameter.
 * @param  v   Output parameter for the v* parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_ciexyz_to_cieluv)(double, double, double, double, double,
				      double, double*, double*, double*);
#define libclut_model_ciexyz_to_cieluv(X, Y, Z, Xn, Yn, Zn, L, u, v)	\
  do									\
    {									\
      double x__ = (Xn), y__ = (Yn);					\
      double t__ = x__ + 15 * y__ + 3 * (Zn);				\
      double u__ = 4 * x__ / t__;					\
      double v__ = 9 * y__ / t__;					\
      x__ = (X), y__ = (Y);						\
      t__ = x__ + 15 * y__ + 3 * (Z);					\
      u__ = 4 * x__ / t__ - u__;					\
      v__ = 9 * y__ / t__ - v__;					\
      y__ = (Y) / y__;							\
      if (y__ * 24389 <= (double)216)					\
	y__ *= 24389, y__ /= 27;					\
      else								\
	y__ = cbrt(y__) * 116 - 16;					\
      *(L) = y__;							\
      y__ *= 13;							\
      *(u) = y__ * u__;							\
      *(v) = y__ * v__;							\
    }									\
  while (0)


/**
 * Convert from CIELUV to CIE XYZ.
 * 
 * @param  L   The L* component.
 * @param  u   The u* component.
 * @param  v   The v* component.
 * @param  Xn  The X component of the specified white object (white point).
 * @param  Yn  The Y component of the specified white object (white point).
 * @param  Zn  The Z component of the specified white object (white point).
 * @param  X   Output parameter for the X parameter.
 * @param  Y   Output parameter for the Y parameter.
 * @param  Z   Output parameter for the Z parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_cieluv_to_ciexyz)(double, double, double, double, double,
				      double, double*, double*, double*);
#define libclut_model_cieluv_to_ciexyz(L, u, v, Xn, Yn, Zn, X, Y, Z)	\
  do									\
    {									\
      double x__ = (Xn), y__ = (Yn), l__ = (L), l13__ = l__ * 13;	\
      double t__ = x__ + 15 * y__ + 3 * (Zn);				\
      double u__ = 4 * x__ / t__;					\
      double v__ = 9 * y__ / t__;					\
      u__ = (u) / l13__ + u__;						\
      v__ = (v) / l13__ + v__;						\
      if (l__ <= (double)8)						\
	y__ *= l__ * 27 / 24389;					\
      else								\
	{								\
	  l__ += 16, l__ /= 116;					\
	  y__ *= l__ *= l__ * l__;					\
	}								\
      *(Y) = y__;							\
      *(X) = y__ * 9 * u__ / (4 * v__);					\
      *(Z) = y__ * (12 - 3 * u__ - 20 * v__) / (4 * v__);		\
    }									\
  while (0)


/**
 * Convert from CIELCh to CIE L*u*v*.
 * 
 * Requires linking with `-lm`.
 * 
 * @param  C  The C*_uv component.
 * @param  h  The h_uv component.
 * @param  u  Output parameter for the u* parameter.
 * @param  v  Output parameter for the v* parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_cielch_to_cieluv)(double, double, double*, double*);
#define libclut_model_cielch_to_cieluv(C, h, u, v)	\
  do							\
    {							\
      double h__ = (h), C__ = (C);			\
      *(v) = sin(h__) * C__;				\
      *(u) = cos(h__) * C__;				\
    }							\
  while (0)


/**
 * Convert from CIE L*u*v* to CIELCh.
 * 
 * Requires linking with `-lm`.
 * 
 * @param  u  The u* component.
 * @param  v  The v* component.
 * @param  C  Output parameter for the C*_uv parameter.
 * @param  h  Output parameter for the h_uv parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_cieluv_to_cielch)(double, double, double*, double*);
#define libclut_model_cieluv_to_cielch(u, v, C, h)	\
  do							\
    {							\
      double u__ = (u), v__ = (v);			\
      *(C) = sqrt(u__ * u__ + v__ * v__);		\
      *(h) = atan2(v__, u__);				\
    }							\
  while (0)


/**
 * Convert from sRGB to YIQ.
 * 
 * Requires linking with '-lclut', or '-lm' if
 * `libclut_model_standard_to_linear1` is not undefined.
 * 
 * @param  r  The R component.
 * @param  g  The G component.
 * @param  b  The B component.
 * @param  y  Output parameter for the Y parameter.
 * @param  i  Output parameter for the I parameter.
 * @param  q  Output parameter for the Q parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_srgb_to_yiq)(double, double, double, double*, double*, double*);
#define libclut_model_srgb_to_yiq(r, g, b, y, i, q)							\
  do													\
    {													\
      double r__ = libclut_model_standard_to_linear1(r) / 100000000000000000ULL;			\
      double g__ = libclut_model_standard_to_linear1(g) / 10000000000000000ULL;				\
      double b__ = libclut_model_standard_to_linear1(b) / 100000000000000000ULL;			\
      *(y) = r__ * 29893602129377540ULL + g__ * 5870430744511212ULL + b__ * 11402090425510336ULL;	\
      *(i) = r__ * 59594574307079930ULL - g__ * 2743886357457892ULL - b__ * 32155710732501010ULL;	\
      *(q) = r__ * 21149734030682846ULL - g__ * 5229106903029739ULL + b__ * 31141334999614540ULL;	\
    }													\
  while (0)


/**
 * Convert from YIQ to sRGB.
 * 
 * Requires linking with '-lclut', or '-lm' if
 * `libclut_model_linear_to_standard1` is not undefined.
 * 
 * @param  y  The Y component.
 * @param  i  The I component.
 * @param  q  The Q component.
 * @param  r  Output parameter for the R parameter.
 * @param  g  Output parameter for the G parameter.
 * @param  b  Output parameter for the B parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_yiq_to_srgb)(double, double, double, double*, double*, double*);
#define libclut_model_yiq_to_srgb(y, i, q, r, g, b)		\
  do								\
    {								\
      double y__ = (y), i__ = (i), q__ = (q), r__, g__, b__;	\
      r__ = y__ + i__ *  956 / 1000 + q__ *  621 / 1000;	\
      g__ = y__ - i__ *  272 / 1000 - q__ *  647 / 1000;	\
      b__ = y__ - i__ * 1106 / 1000 + q__ * 1703 / 1000;	\
      *(r) = libclut_model_linear_to_standard1(r__);		\
      *(g) = libclut_model_linear_to_standard1(g__);		\
      *(b) = libclut_model_linear_to_standard1(b__);		\
    }								\
  while (0)


/**
 * Convert from sRGB to YDbDr.
 * 
 * Requires linking with '-lclut', or '-lm' if
 * `libclut_model_standard_to_linear1` is not undefined.
 * 
 * @param  r   The R component.
 * @param  g   The G component.
 * @param  b   The B component.
 * @param  y   Output parameter for the Y parameter.
 * @param  db  Output parameter for the Db parameter.
 * @param  dr  Output parameter for the Dr parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_srgb_to_ydbdr)(double, double, double, double*, double*, double*);
#define libclut_model_srgb_to_ydbdr(r, g, b, y, db, dr)				\
  do										\
    {										\
      double r__ = libclut_model_standard_to_linear1(r);			\
      double g__ = libclut_model_standard_to_linear1(g);			\
      double b__ = libclut_model_standard_to_linear1(b);			\
      *(y)  =  r__ *  299 / 1000 + g__ *  587 / 1000 + b__ *  114 / 1000;	\
      *(db) = -r__ *  450 / 1000 - g__ *  883 / 1000 + b__ * 1333 / 1000;	\
      *(dr) = -r__ * 1333 / 1000 + g__ * 1116 / 1000 + b__ *  217 / 1000;	\
    }										\
  while (0)


/**
 * Convert from YDbDr to sRGB.
 * 
 * Requires linking with '-lclut', or '-lm' if
 * `libclut_model_linear_to_standard1` is not undefined.
 * 
 * @param  y   The Y component.
 * @param  db  The Db component.
 * @param  dr  The Dr component.
 * @param  r   Output parameter for the R parameter.
 * @param  g   Output parameter for the G parameter.
 * @param  b   Output parameter for the B parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_ydbdr_to_srgb)(double, double, double, double*, double*, double*);
#define libclut_model_ydbdr_to_srgb(y, db, dr, r, g, b)				\
  do										\
    {										\
      double y__ = (y), db__ = (db), dr__ = (dr), r__, g__, b__;		\
      db__ /= 1000000000000000ULL;						\
      dr__ /= 1000000000000000ULL;						\
      r__ = y__ + db__ *     92303716148ULL - dr__ * 525912630661865ULL;	\
      g__ = y__ - db__ * 129132898890509ULL + dr__ * 267899328207599ULL;	\
      b__ = y__ + db__ * 664679059978955ULL - dr__ *     79202543533ULL;	\
      *(r) = libclut_model_linear_to_standard1(r__);				\
      *(g) = libclut_model_linear_to_standard1(g__);				\
      *(b) = libclut_model_linear_to_standard1(b__);				\
    }										\
  while (0)


/**
 * Convert from YUV to YDbDr.
 * 
 * @param  u   The U component.
 * @param  v   The V component.
 * @param  db  Output parameter for the Db parameter.
 * @param  dr  Output parameter for the Dr parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_yuv_to_ydbdr)(double, double, double*, double*);
#define libclut_model_yuv_to_ydbdr(u, v, db, dr)	\
  do							\
    {							\
      *(db) =  3069 * (u) / 1000;			\
      *(dr) = -2169 * (v) / 1000;			\
    }							\
  while (0)


/**
 * Convert from YDbDr to YUV.
 * 
 * @param  db  The Db component.
 * @param  dr  The Dr component.
 * @param  u   Output parameter for the U parameter.
 * @param  v   Output parameter for the V parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_ydbdr_to_yuv)(double, double, double*, double*);
#define libclut_model_ydbdr_to_yuv(db, dr, u, v)	\
  do							\
    {							\
      *(u) = (db) * 1000 /  3069;			\
      *(v) = (dr) * 1000 / -2169;			\
    }							\
  while (0)


/**
 * Convert from sRGB to YPbPr.
 * 
 * Requires linking with '-lclut', or '-lm' if
 * `libclut_model_standard_to_linear1` is not undefined.
 * 
 * @param  r   The R component.
 * @param  g   The G component.
 * @param  b   The B component.
 * @param  y   Output parameter for the Y parameter.
 * @param  pb  Output parameter for the Pb parameter.
 * @param  pr  Output parameter for the Pr parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_srgb_to_ypbpr)(double, double, double, double*, double*, double*);
#define libclut_model_srgb_to_ypbpr(r, g, b, y, pb, pr)		\
  do								\
    {								\
      double r__ = libclut_model_standard_to_linear1(r);	\
      double g__ = libclut_model_standard_to_linear1(g);	\
      double b__ = libclut_model_standard_to_linear1(b);	\
      double y__;						\
      y__  = r__ * 2126 / 10000;				\
      y__ += g__ * 7152 / 10000;				\
      y__ += b__ *  722 / 10000;				\
      *(y) = y__;						\
      *(pb) = b__ - y__;					\
      *(pr) = r__ - y__;					\
      ;								\
    }								\
  while (0)


/**
 * Convert from YPbPr to sRGB.
 * 
 * Requires linking with '-lclut', or '-lm' if
 * `libclut_model_linear_to_standard1` is not undefined.
 * 
 * @param  y   The Y component.
 * @param  pb  The Pb component.
 * @param  pr  The Pr component.
 * @param  r   Output parameter for the R parameter.
 * @param  g   Output parameter for the G parameter.
 * @param  b   Output parameter for the B parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_ypbpr_to_srgb)(double, double, double, double*, double*, double*);
#define libclut_model_ypbpr_to_srgb(y, pb, pr, r, g, b)			\
  do									\
    {									\
      double y__ = (y), r__ = (pr) + y__, g__, b__ = (pb) + y__;	\
      y__ -= r__ * 2126 / 10000;					\
      y__ -= b__ * 722 / 10000;						\
      g__ = y__ * 10000 / 7152;						\
      *(r) = libclut_model_linear_to_standard1(r__);			\
      *(g) = libclut_model_linear_to_standard1(g__);			\
      *(b) = libclut_model_linear_to_standard1(b__);			\
    }									\
  while (0)


/**
 * Convert from sRGB to YCgCo.
 * 
 * Requires linking with '-lclut', or '-lm' if
 * `libclut_model_standard_to_linear1` is not undefined.
 * 
 * @param  r   The R component.
 * @param  g   The G component.
 * @param  b   The B component.
 * @param  y   Output parameter for the Y parameter.
 * @param  cg  Output parameter for the Cg parameter.
 * @param  co  Output parameter for the Co parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_srgb_to_ycgco)(double, double, double, double*, double*, double*);
#define libclut_model_srgb_to_ycgco(r, g, b, y, cg, co)		\
  do								\
    {								\
      double r__ = libclut_model_standard_to_linear1(r);	\
      double g__ = libclut_model_standard_to_linear1(g);	\
      double b__ = libclut_model_standard_to_linear1(b);	\
      *(y)  = r__ /  4 + g__ / 2 + b__ / 4;			\
      *(cg) = r__ / -4 + g__ / 2 - b__ / 4;			\
      *(co) = r__ /  2           - b__ / 2;			\
    }								\
  while (0)


/**
 * Convert from YCgCo to sRGB.
 * 
 * Requires linking with '-lclut', or '-lm' if
 * `libclut_model_linear_to_standard1` is not undefined.
 * 
 * @param  y   The Y component.
 * @param  cg  The Cg component.
 * @param  co  The Co component.
 * @param  r   Output parameter for the R parameter.
 * @param  g   Output parameter for the G parameter.
 * @param  b   Output parameter for the B parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_ycgco_to_srgb)(double, double, double, double*, double*, double*);
#define libclut_model_ycgco_to_srgb(y, cg, co, r, g, b)	\
  do							\
    {							\
      double y__ = (y), cg__ = (cg), co__ = (co);	\
      double r__ = y__ - cg__ + co__;			\
      double g__ = y__ + cg__;				\
      double b__ = y__ - cg__ - co__;			\
      *(r) = libclut_model_linear_to_standard1(r__);	\
      *(g) = libclut_model_linear_to_standard1(g__);	\
      *(b) = libclut_model_linear_to_standard1(b__);	\
    }							\
  while (0)


/**
 * Convert from CIE 1960 UCS to CIE XYZ.
 * 
 * @param  u  The u component.
 * @param  v  The v component.
 * @param  Y  The Y component.
 * @param  x  Output parameter for the X parameter.
 * @param  y  Output parameter for the Y parameter.
 * @param  z  Output parameter for the Z parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_cie_1960_ucs_to_ciexyz)(double, double, double, double*, double*, double*);
#define libclut_model_cie_1960_ucs_to_ciexyz(u, v, Y, x, y, z)		\
  do									\
    {									\
      double u__ = (u), v__ = (v), y__ = (Y);				\
      *(y) = y__;							\
      *(x) = 3 * y__ * u__ / (2 * v__);					\
      *(z) = (4 * y__ - y__ * u__ - 10 * y__ * v__) / (2 * v__);	\
    }									\
  while (0)


/**
 * Convert from CIE XYZ to CIE 1960 UCS.
 * 
 * @param  x  The X component.
 * @param  y  The Y component.
 * @param  z  The Z component.
 * @param  u  Output parameter for the u parameter.
 * @param  v  Output parameter for the v parameter.
 * @param  Y  Output parameter for the Y parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_ciexyz_to_cie_1960_ucs)(double, double, double, double*, double*, double*);
#define libclut_model_ciexyz_to_cie_1960_ucs(x, y, z, u, v, Y)	\
  do								\
    {								\
      double x__ = (x), y__ = (y);				\
      double d__ = x__ + 15 * y__ + 3 * (z);			\
      *(u) = 4 * x__ / d__;					\
      *(v) = 6 * y__ / d__;					\
      *(Y) = y__;						\
    }								\
  while (0)


/**
 * Convert from CIEUVW to CIE 1960 UCS.
 * 
 * @param  U:double   The U* component.
 * @param  V:double   The V* component.
 * @param  W:double   The W* component.
 * @param  u0:double  The u parameter for the white point.
 * @param  v0:double  The v parameter for the white point.
 * @param  u:double*  Output parameter for the u parameter.
 * @param  v:double*  Output parameter for the v parameter.
 * @param  Y:double*  Output parameter for the Y parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_cieuvw_to_cie_1960_ucs)(double, double, double, double, double,
					    double*, double*, double*);
#define libclut_model_cieuvw_to_cie_1960_ucs(U, V, W, u0, v0, u, v, Y)	\
  do									\
    {									\
      double w__ = (W), y__ = (w__ + 17) / 25;				\
      *(Y) = y__ *= y__ * y__;						\
      w__ *= 13;							\
      *(u) = (U) / w__ + (u0);						\
      *(v) = (V) / w__ + (v0);						\
    }									\
  while (0)


/**
 * Convert from CIE 1960 UCS to CIEUVW.
 * 
 * Requires linking with `-lm`.
 * 
 * @param  u:double   The u component.
 * @param  v:double   The v component.
 * @param  Y:double   The Y component.
 * @param  u0:double  The u parameter for the white point.
 * @param  v0:double  The v parameter for the white point.
 * @param  U:double*  Output parameter for the U* parameter.
 * @param  V:double*  Output parameter for the V* parameter.
 * @param  W:double*  Output parameter for the W* parameter.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_cie_1960_ucs_to_cieuvw)(double, double, double, double, double,
					    double*, double*, double*);
#define libclut_model_cie_1960_ucs_to_cieuvw(u, v, Y, u0, v0, U, V, W)	\
  do									\
    {									\
      double w__ = 25 * cbrt(Y) - 17;					\
      *(W) = w__;							\
      w__ *= 13;							\
      *(U) = w__ * ((u) - (u0));					\
      *(V) = w__ * ((v) - (v0));					\
    }									\
  while (0)


/**
 * Create a matrix for converting values between
 * two RGB colour spaces.
 * 
 * @param   from  The input colour space, the Y-component is only necessary
 *                for the white point, `NULL` for CIE XYZ.
 * @param   to    The output colour space, the Y-component is only necessary
 *                for the white point, `NULL` for CIE XYZ.
 * @param   M     Output matrix for conversion from `from` to `to`.
 * @param   Minv  Output matrix for conversion from `to` to `from`, may be `NULL`.
 * @return        Zero on success, -1 on error.
 * 
 * @throws  EINVAL  The colour space cannot be used.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
int libclut_model_get_rgb_conversion_matrix(const libclut_rgb_colour_space_t*,
					    const libclut_rgb_colour_space_t*,
					    libclut_colour_space_conversion_matrix_t,
					    libclut_colour_space_conversion_matrix_t);


/**
 * Convert an RGB colour into another RGB colour space.
 * 
 * Both RGB colour spaces must have same gamma functions as sRGB.
 * 
 * Requires linking with '-lclut', or '-lm' if
 * `libclut_model_standard_to_linear1` or
 * `libclut_model_linear_to_standard1` is not undefined.
 * 
 * @param  r      The red component of the colour to convert.
 * @param  g      The green component of the colour to convert.
 * @param  b      The blue component of the colour to convert.
 * @param  M      Conversion matrix, create with `libclut_model_get_rgb_conversion_matrix`,
 *                must not have side-effects.
 * @param  out_r  Output parameter for the new red component.
 * @param  out_g  Output parameter for the new green component.
 * @param  out_b  Output parameter for the new blue component.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_convert_rgb)(double, double, double, libclut_colour_space_conversion_matrix_t,
				 double*, double*, double*);
#define libclut_model_convert_rgb(r, g, b, M, out_r, out_g, out_b)						\
  do														\
    {														\
      double r__ = libclut_model_standard_to_linear1(r);							\
      double g__ = libclut_model_standard_to_linear1(g);							\
      double b__ = libclut_model_standard_to_linear1(b);							\
      *(out_r) = libclut_model_linear_to_standard1((M)[0][0] * r__ + (M)[0][1] * g__ + (M)[0][2] * b__);	\
      *(out_g) = libclut_model_linear_to_standard1((M)[1][0] * r__ + (M)[1][1] * g__ + (M)[1][2] * b__);	\
      *(out_b) = libclut_model_linear_to_standard1((M)[2][0] * r__ + (M)[2][1] * g__ + (M)[2][2] * b__);	\
    }														\
  while (0)


/**
 * Convert an RGB colour of a custom RGB colour space to CIE XYZ.
 * 
 * The RGB colour space must have same gamma functions as sRGB.
 * 
 * Requires linking with '-lclut', or '-lm' if
 * `libclut_model_standard_to_linear1` is not undefined.
 * 
 * @param  r  The red component.
 * @param  g  The green component.
 * @param  b  The blue component.
 * @param  M  Conversion matrix, create with `libclut_model_get_rgb_conversion_matrix`,
 *            must not have side-effects.
 * @param  x  Output parameter for the X component.
 * @param  y  Output parameter for the Y component
 * @param  z  Output parameter for the Z component.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_rgb_to_ciexyz)(double, double, double, libclut_colour_space_conversion_matrix_t,
				   double*, double*, double*);
#define libclut_model_rgb_to_ciexyz(r, g, b, M, x, y, z)		\
  do									\
    {									\
      double r__ = libclut_model_standard_to_linear1(r);		\
      double g__ = libclut_model_standard_to_linear1(g);		\
      double b__ = libclut_model_standard_to_linear1(b);		\
      *(x) = (M)[0][0] * r__ + (M)[0][1] * g__ + (M)[0][2] * b__;	\
      *(y) = (M)[1][0] * r__ + (M)[1][1] * g__ + (M)[1][2] * b__;	\
      *(z) = (M)[2][0] * r__ + (M)[2][1] * g__ + (M)[2][2] * b__;	\
    }									\
  while (0)


/**
 * Convert a CIE XYZ colour to a custom RGB colour space.
 * 
 * The RGB colour space must have same gamma functions as sRGB.
 * 
 * Requires linking with '-lclut', or '-lm' if
 * `libclut_model_linear_to_standard1` is not undefined.
 * 
 * @param  x  The X component.
 * @param  y  The Y component.
 * @param  z  The Z component.
 * @param  M  Conversion matrix, create with `libclut_model_get_rgb_conversion_matrix`,
 *            must not have side-effects.
 * @param  r  Output parameter for the red component.
 * @param  g  Output parameter for the green component
 * @param  b  Output parameter for the blue component.
 */
LIBCLUT_GCC_ONLY__(__attribute__((__leaf__)))
void (libclut_model_ciexyz_to_rgb)(double, double, double, libclut_colour_space_conversion_matrix_t,
				   double*, double*, double*);
#define libclut_model_ciexyz_to_rgb(x, y, z, M, r, g, b)						\
  do													\
    {													\
      double x__ = (x), y__ = (y), z__ = (z);								\
      *(r) = libclut_model_linear_to_standard1((M)[0][0] * x__ + (M)[0][1] * y__ + (M)[0][2] * z__);	\
      *(g) = libclut_model_linear_to_standard1((M)[1][0] * x__ + (M)[1][1] * y__ + (M)[1][2] * z__);	\
      *(b) = libclut_model_linear_to_standard1((M)[2][0] * x__ + (M)[2][1] * y__ + (M)[2][2] * z__);	\
    }													\
  while (0)



#if defined(__clang__)
# pragma GCC diagnostic pop
#endif


#endif

