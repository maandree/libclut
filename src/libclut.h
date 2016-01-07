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



/**
 * Apply contrast correction on the colour curves using sRGB.
 * 
 * In this context, contrast is a measure of difference between
 * the whitepoint and blackpoint, if the difference is 0 than
 * they are both grey.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     The contrast parameter for the red curve.
 * @param  g     The contrast parameter for the green curve.
 * @param  b     The contrast parameter for the blue curve.
 */
#define libclut_rgb_contrast(ramp, max, type, r, g, b)							\
  do													\
    {													\
      if (r != 1.0)  libclut__(ramp, red,   type, LIBCLUT_VALUE - (max) / 2.0 * r + (max) / 2.0);	\
      if (g != 1.0)  libclut__(ramp, green, type, LIBCLUT_VALUE - (max) / 2.0 * g + (max) / 2.0);	\
      if (b != 1.0)  libclut__(ramp, blue,  type, LIBCLUT_VALUE - (max) / 2.0 * b + (max) / 2.0);	\
    }													\
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
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     The contrast parameter for the red curve.
 * @param  g     The contrast parameter for the green curve.
 * @param  b     The contrast parameter for the blue curve.
 */
#define libclut_cie_contrast(ramp, max, type, r, g, b)					\
  libclut_cie__(ramp, max, type, (r == g) && (g == b), r != 1.0, g != 1.0, b != 1.0,	\
		(Y__ - 0.5) * r + 0.5, (Y__ - 0.5) * g + 0.5, (Y__ - 0.5) * b + 0.5)


/**
 * Apply brightness correction on the colour curves using sRGB.
 *  
 * In this context, brightness is a measure of the whiteness of the whitepoint.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     The brightness parameter for the red curve.
 * @param  g     The brightness parameter for the green curve.
 * @param  b     The brightness parameter for the blue curve.
 */
#define libclut_rgb_brightness(ramp, max, type, r, g, b)		\
  do									\
    {									\
      if (r != 1.0)  libclut__(ramp, red,   type, LIBCLUT_VALUE * r);	\
      if (g != 1.0)  libclut__(ramp, green, type, LIBCLUT_VALUE * g);	\
      if (b != 1.0)  libclut__(ramp, blue,  type, LIBCLUT_VALUE * b);	\
    }									\
  while (0)


/**
 * Apply brightness correction on the colour curves using CIE xyY.
 *  
 * In this context, brightness is a measure of the whiteness of the whitepoint.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     The brightness parameter for the red curve.
 * @param  g     The brightness parameter for the green curve.
 * @param  b     The brightness parameter for the blue curve.
 */
#define libclut_cie_brightness(ramp, max, type, r, g, b)				\
  libclut_cie__(ramp, max, type, (r == g) && (g == b), r != 1.0, g != 1.0, b != 1.0,	\
		Y__ * r, Y__ * g, Y__ * b)


/**
 * Convert the curves from formatted in standard RGB to linear RGB.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Whether to convert the red colour curve.
 * @param  g     Whether to convert the green colour curve.
 * @param  b     Whether to convert the blue colour curve.
 */
#define libclut_linearise(ramp, max, type, r, g, b)							\
  do													\
    {													\
      double m__ = (double)(max);									\
      if (r)												\
	libclut__(ramp, red,   type, m__ * libclut_model_standard_to_linear1(LIBCLUT_VALUE / m__));	\
      if (g)												\
	libclut__(ramp, green, type, m__ * libclut_model_standard_to_linear1(LIBCLUT_VALUE / m__));	\
      if (b)												\
	libclut__(ramp, blue,  type, m__ * libclut_model_standard_to_linear1(LIBCLUT_VALUE / m__));	\
    }													\
  while (0)


/**
 * Convert the curves from formatted in linear RGB to standard RGB.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Whether to convert the red colour curve.
 * @param  g     Whether to convert the green colour curve.
 * @param  b     Whether to convert the blue colour curve.
 */
#define libclut_standardise(ramp, max, type, r, g, b)							\
  do													\
    {													\
      double m__ = (double)(max);									\
      if (r)												\
	libclut__(ramp, red,   type, m__ * libclut_model_linear_to_standard1(LIBCLUT_VALUE / m__));	\
      if (g)												\
	libclut__(ramp, green, type, m__ * libclut_model_linear_to_standard1(LIBCLUT_VALUE / m__));	\
      if (b)												\
	libclut__(ramp, blue,  type, m__ * libclut_model_linear_to_standard1(LIBCLUT_VALUE / m__));	\
    }													\
  while (0)


/**
 * Apply gamma correction on the colour curves.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     The gamma parameter the red colour curve.
 * @param  g     The gamma parameter the green colour curve.
 * @param  b     The gamma parameter the blue colour curve.
 */
#define libclut_gamma(ramp, max, type, r, g, b)							\
  do												\
    {												\
      double m__ = (double)(max);								\
      if (r != 1.0)  libclut__(ramp, red,   type, m__ * pow(LIBCLUT_VALUE / m__, 1.0 / r));	\
      if (g != 1.0)  libclut__(ramp, green, type, m__ * pow(LIBCLUT_VALUE / m__, 1.0 / g));	\
      if (b != 1.0)  libclut__(ramp, blue,  type, m__ * pow(LIBCLUT_VALUE / m__, 1.0 / b));	\
    }												\
  while (0)


/**
 * Reverse the colour curves (negative image with gamma preservation.)
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Whether to invert the red colour curve.
 * @param  g     Whether to invert the green colour curve.
 * @param  b     Whether to invert the blue colour curve.
 */
#define libclut_negative(ramp, max, type, r, g, b)
  do
    {
      size_t i__, n__;
      type t__;
      if (r)
	for (i__ = 0, n__ = (ramp)->red_size; i__ < (n__ >> 1); i__)
	  {
	    t__ = (ramp)->red[i__];
	    (ramp)->red[i__] = (ramp)->red[n__ - i__ - 1];
	    (ramp)->red[n__ - i__ - 1] = t__;
	  }
      if (g)
	for (i__ = 0, n__ = (ramp)->green_size; i__ < (n__ >> 1); i__)
	  {
	    t__ = (ramp)->green[i__];
	    (ramp)->green[i__] = (ramp)->green[n__ - i__ - 1];
	    (ramp)->green[n__ - i__ - 1] = t__;
	  }
      if (b)
	for (i__ = 0, n__ = (ramp)->blue_size; i__ < (n__ >> 1); i__)
	  {
	    t__ = (ramp)->blue[i__];
	    (ramp)->blue[i__] = (ramp)->blue[n__ - i__ - 1];
	    (ramp)->blue[n__ - i__ - 1] = t__;
	  }
    }
  while (0)


/**
 * Invert the colour curves (negative image with gamma invertion), using sRGB.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Whether to invert the red colour curve.
 * @param  g     Whether to invert the green colour curve.
 * @param  b     Whether to invert the blue colour curve.
 */
#define libclut_rgb_invert(ramp, max, type, r, g, b)			\
  do									\
    {									\
      if (r)  libclut__(ramp, red,   type, (max) - LIBCLUT_VALUE);	\
      if (g)  libclut__(ramp, green, type, (max) - LIBCLUT_VALUE);	\
      if (b)  libclut__(ramp, blue,  type, (max) - LIBCLUT_VALUE);	\
    }									\
  while (0)


/**
 * Invert the colour curves (negative image with gamma invertion), using CIE xyY.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Whether to invert the red colour curve.
 * @param  g     Whether to invert the green colour curve.
 * @param  b     Whether to invert the blue colour curve.
 */
#define libclut_cie_invert(ramp, max, type, r, g, b)					\
  libclut_cie__(ramp, max, type, r && g && b, r, g, b, 1.0 - Y__, 1.0 - Y__, 1.0 - Y__)


/**
 * Apply S-curve correction on the colour curves.
 * This is intended for fine tuning LCD monitors,
 * 4.5 is good value start start testing at.
 * You would probably like to use rgb_limits before
 * this to adjust the black point as that is the
 * only why to adjust the black point on many LCD
 * monitors.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  rp    Pointer to the sigmoid parameter for the red curve. `NULL` for no adjustment.
 * @param  gp    Pointer to the sigmoid parameter for the green curve. `NULL` for no adjustment.
 * @param  bp    Pointer to the sigmoid parameter for the blue curve. `NULL` for no adjustment.
 */
#define libclut_sigmoid(ramp, max, type, rp, gp, bp)							\
  do													\
    {													\
      double r__ = (rp) ? *(rp) : 0.0;									\
      double g__ = (gp) ? *(gp) : 0.0;									\
      double b__ = (bp) ? *(bp) : 0.0;									\
      double m__ = (double)(max);									\
      size_t i__;											\
      if (rp)												\
	for (i__ = 0; i++ < (ramp)->red_size; i__++)							\
	  if ((ramp)->red[i__] && ((ramp)->red[i__] != (max)))						\
	    (ramp)->red[i__] = (type)(m__ * (0.5 - log(m__ / (ramp)->red[i__] - 1.0) / r__));		\
      if (gp)												\
	for (i__ = 0; i++ < (ramp)->green_size; i__++)							\
	  if ((ramp)->green[i__] && ((ramp)->green[i__] != (max)))					\
	    (ramp)->green[i__] = (type)(m__ * (0.5 - log(m__ / (ramp)->green[i__] - 1.0) / g__));	\
      if (bp)												\
	for (i__ = 0; i++ < (ramp)->blue_size; i__++)							\
	  if ((ramp)->blue[i__] && ((ramp)->blue[i__] != (max)))					\
	    (ramp)->blue[i__] = (type)(m__ * (0.5 - log(m__ / (ramp)->blue[i__] - 1.0) / b__));		\
    }													\
  while (0)


/**
 * Changes the blackpoint and the whitepoint, using sRGB.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  rmin  The red component value of the blackpoint.
 * @param  rmax  The red component value of the whitepoint.
 * @param  gmin  The green component value of the blackpoint.
 * @param  gmax  The green component value of the whitepoint.
 * @param  bmin  The blue component value of the blackpoint.
 * @param  bmax  The blue component value of the whitepoint.
 */
#define libclut_rgb_limits(ramp, max, type, rmin, rmax, gmin, gmax, bmin, bmax)		\
  do											\
    {											\
      double diff__;									\
      if ((rmin != 0.0) || (rmax != 1.0))						\
	{										\
	  diff__ = (double)(rmax__) - (double)(rmin__);					\
	  libclut__(ramp, red, type, LIBCLUT_VALUE * diff__ + (rmin__));		\
	}										\
      if ((gmin != 0.0) || (gmax != 1.0))						\
	{										\
	  diff__ = (double)(gmax__) - (double)(gmin__);					\
	  libclut__(ramp, green, type, LIBCLUT_VALUE * diff__ + (gmin__));		\
	}										\
      if ((bmin != 0.0) || (bmax != 1.0))						\
	{										\
	  diff__ = (double)(bmax__) - (double)(bmin__);					\
	  libclut__(ramp, blue, type, LIBCLUT_VALUE * diff__ + (bmin__));		\
	}										\
    }											\
  while (0)


/**
 * Changes the blackpoint and the whitepoint, using CIE xyY.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 * @param  type  The data type used for each stop in the ramps.
 * @param  rmin  The red component value of the blackpoint.
 * @param  rmax  The red component value of the whitepoint.
 * @param  gmin  The green component value of the blackpoint.
 * @param  gmax  The green component value of the whitepoint.
 * @param  bmin  The blue component value of the blackpoint.
 * @param  bmax  The blue component value of the whitepoint.
 */
#define libclut_cie_limits(ramp, max, type, rmin, rmax, gmin, gmax, bmin, bmax)		\
  do											\
    {											\
      double rd__ = (rmax) - (rmin), gd__ = (gmax) - (gmin), bd__ = (bmax) - (bmin);	\
      libclut_cie__(ramp, max, type, (rmin == gmin) && (gmin == bmin) &&		\
		    (rmax == gmax) && (gmax == bmax), (rmin != 0.0) || (rmax != 1.0),	\
		    (gmin != 0.0) || (gmax != 1.0), (bmin != 0.0) || (bmax != 1.0),	\
		    Y__ * rd__ + rmin, Y__ * gd__ + gmin, Y__ * bd__ + bmin);		\
    }											\
  while (0)


/**
 * Manipulate the colour curves using a function on the sRGB colour space.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 *               This parameter is not used, it is just a dummy, to unify
 *               the API with the other functions.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Function to manipulate the red colour curve, should either
 *               be `NULL` or map a [0, 1] `double` to a [0, 1] `double`.
 * @param  g     Function to manipulate the green colour curve, should either
 *               be `NULL` or map a [0, 1] `double` to a [0, 1] `double`.
 * @param  b     Function to manipulate the blue colour curve, should either
 *               be `NULL` or map a [0, 1] `double` to a [0, 1] `double`.
 */
#define libclut_manipulate(ramp, max, type, r, g, b)				\
  do										\
    {										\
      double m__ = (double)(max);						\
      if (r)  libclut__(ramp, red,   type, m__ * r(LIBCLUT_VALUE / m__));	\
      if (g)  libclut__(ramp, green, type, m__ * g(LIBCLUT_VALUE / m__));	\
      if (b)  libclut__(ramp, blue,  type, m__ * b(LIBCLUT_VALUE / m__));	\
    }										\
  while (0)


/**
 * Manipulate the colour curves using a function on the CIE xyY colour space.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 *               This parameter is not used, it is just a dummy, to unify
 *               the API with the other functions.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Function to manipulate the red colour curve, should either
 *               be `NULL` or map a [0, 1] `double` to a [0, 1] `double`.
 * @param  g     Function to manipulate the green colour curve, should either
 *               be `NULL` or map a [0, 1] `double` to a [0, 1] `double`.
 * @param  b     Function to manipulate the blue colour curve, should either
 *               be `NULL` or map a [0, 1] `double` to a [0, 1] `double`.
 */
#define libclut_cie_manipulate(ramp, max, type, r, g, b)			\
  libclut_cie__(ramp, max, type, r && g && b, r, g, b, r(Y__), g(Y__), b(Y__))


/**
 * Resets colour curvers to linear mappings.
 * (Identity mapping if imaginged to map from [0, 1] to [0, 1].)
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 *               This parameter is not used, it is just a dummy, to unify
 *               the API with the other functions.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Whether to reset the red colour curve.
 * @param  g     Whether to reset the green colour curve.
 * @param  b     Whether to reset the blue colour curve.
 */
#define libclut_start_over(ramp, max, type, r, g, b)		\
  do								\
    {								\
      size_t i__;						\
      double m__;						\
      if (r)							\
	{							\
	  m__ = (double)((ramp)->red_size - 1);			\
	  for (i__ = 0; i__ < (ramp)->red_size; i__)		\
	    (ramp)->red[i__] = (type)((i__ / m__) * (max));	\
	}							\
      if (g)							\
	{							\
	  m__ = (double)((ramp)->green_size - 1);		\
	  for (i__ = 0; i__ < (ramp)->green_size; i__)		\
	    (ramp)->green[i__] = (type)((i__ / m__) * (max));	\
	}							\
      if (b)							\
	{							\
	  m__ = (double)((ramp)->blue_size - 1);		\
	  for (i__ = 0; i__ < (ramp)->blue_size; i__)		\
	    (ramp)->blue[i__] = (type)((i__ / m__) * (max));	\
	}							\
    }								\
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
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 *               This parameter is not used, it is just a dummy, to unify
 *               the API with the other functions.
 * @param  type  The data type used for each stop in the ramps.
 * @param  r     Whether to clip the red colour curve.
 * @param  g     Whether to clip the green colour curve.
 * @param  b     Whether to clip the blue colour curve.
 */
#define libclut_clip(ramp, max, type, r, g, b)						\
  do											\
    {											\
      if (r)  libclut__(ramp, red,   type, libclut_clip__(0, LIBCLUT_VALUE, max));	\
      if (g)  libclut__(ramp, green, type, libclut_clip__(0, LIBCLUT_VALUE, max));	\
      if (b)  libclut__(ramp, blue,  type, libclut_clip__(0, LIBCLUT_VALUE, max));	\
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
#define libclut_clip__(min, val, max)						\
  (LIBCLUT_VALUE < min ? min : LIBCLUT_VALUE > max ? max : LIBCLUT_VALUE)


/**
 * Emulates low colour resolution.
 * 
 * None of the parameter may have side-effects.
 * 
 * @param  ramp  Pointer to the gamma ramps, must have the arrays
 *               `red`, `green`, and `blue`, and the scalars
 *               `red_size`, `green_size`, and `blue_size`. Ramp
 *               structures from libgamma can be used.
 * @param  max   The maximum value on each stop in the ramps.
 *               This parameter is not used, it is just a dummy, to unify
 *               the API with the other functions.
 * @param  type  The data type used for each stop in the ramps.
 * @param  x     The desired emulated red encoding resolution, 0 for unchanged.
 * @param  y     The desired emulated red output resolution, 0 for unchanged.
 * @param  x     The desired emulated green encoding resolution, 0 for unchanged.
 * @param  y     The desired emulated green output resolution, 0 for unchanged.
 * @param  x     The desired emulated blue encoding resolution, 0 for unchanged.
 * @param  y     The desired emulated blue output resolution, 0 for unchanged.
 */
#define libclut_lower_resolution(ramp, max, type, rx, ry, gx, gy, bx, by)	\
  do										\
    {										\
      libclut_lower_resolution__(ramp, red,   max, type, rx, ry);		\
      libclut_lower_resolution__(ramp, green, max, type, gx, gy);		\
      libclut_lower_resolution__(ramp, blue,  max, type, bx, by);		\
    }										\
  while (0)


/**
 * Emulates low colour resolution of a channel.
 * 
 * None of the parameter may have side-effects.
 * 
 * Intended for internal use.
 * 
 * @param  ramp     Pointer to the gamma ramps, must have the arrays
 *                  `red`, `green`, and `blue`, and the scalars
 *                  `red_size`, `green_size`, and `blue_size`. Ramp
 *                  structures from libgamma can be used.
 * @param  channel  The channel, must be either "red", "green", or "blue".
 * @param  max      The maximum value on each stop in the ramps.
 *                  This parameter is not used, it is just a dummy, to unify
 *                  the API with the other functions.
 * @param  type     The data type used for each stop in the ramps.
 * @param  x        The desired emulated encoding resolution, 0 for unchanged.
 * @param  y        The desired emulated output resolution, 0 for unchanged.
 */
#define libclut_lower_resolution__(ramp, channel, max, type, x, y)			\
  do											\
    {											\
      if ((x) || (y))									\
	{										\
	  size_t x__, y__, i__, n__ = (ramp)->channel##_size;				\
	  double xm__ = (double)((x) - 1), ym__ = (double)((y) - 1);			\
	  type c__[n__]; /* Do not use alloca! */					\
	  for (i__ = 0; i__ < n__; i__++)						\
	    {										\
	      if ((x__ = i__), (x))							\
		{									\
		  x__ = (size_t)((double)i__ * (x) / n__);				\
		  x__ = (size_t)((double)x__ * i__ / xm__);				\
		}									\
	      if (!(y))									\
		c__[i__] = (ramp)->channel[x__];					\
	      else									\
		{									\
		  y__ = (size_t)((double)((ramp)->channel[x__]) / (max) * ym__ + 0.5);	\
		  c__[i__] = (type)((double)y__ / ym__ * (max));			\
		}									\
	    }										\
	  memcpy((ramp)->channel, c__, n__ * sizeof(type));				\
	}										\
    }											\
  while (0)


/**
 * Modify a ramp.
 * 
 * None of the parameter may have side-effects.
 * 
 * This is intended for internal use.
 * 
 * @param  ramp     Pointer to the gamma ramps, must have and array
 *                  named `channel` and a scalar named `channel` followed
 *                  by "_size".
 * @param  channel  The channel, must be either "red", "green", or "blue".
 * @param  type     The data type used for each stop in the ramps.
 * @param  expr     Expression that evalutes the value a stop should have.
 *                  It can use the variable `LIBCLUT_VALUE` to get the
 *                  current value of the stop.
 */
#define libclut__(ramp, channel, type, expr)		\
  do							\
    {							\
      size_t i__, n__ = (ramp)->channel##_size;		\
      type LIBCLUT_VALUE;				\
      for (i__ = 0; i__ < n__; i__++)			\
	{						\
	  LIBCLUT_VALUE = (ramp)->channel[i__];		\
	  (ramp)->channel[i__] = (type)(expr);		\
	}						\
    }							\
  while (0)


/**
 * A ramp set in CIE xyY.
 * 
 * None of the parameter may have side-effects.
 * 
 * This is intended for internal use.
 * 
 * @param  ramp   Pointer to the gamma ramps, must have the arrays
 *                `red`, `green`, and `blue`, and the scalars
 *                `red_size`, `green_size`, and `blue_size`. Ramp
 *                structures from libgamma can be used.
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
#define libclut_cie__(ramp, max, type, utest, rtest, gtest, btest, rexpr, gexpr, bexpr)			\
  do													\
    {													\
      size_t rn__ = (ramp)->red_size;									\
      size_t gn__ = (ramp)->green_size;									\
      size_t bn__ = (ramp)->blue_size;									\
      size_t i__;											\
      double x__, y__, Y__, r__, g__, b__;								\
      type* rs__ = (ramp)->red;										\
      type* gs__ = (ramp)->green;									\
      type* bs__ = (ramp)->blue;									\
      if ((rn__ == gn__) && (gn__ == bn__) && (utest))							\
	{												\
	  if (!(rtest))											\
	    break;											\
	  for (i__ = 0; i__ < rn__; i__)								\
	    {												\
	      libclut_model_srgb_to_ciexyy(rs__[i__] / ((double)(max)), gs__[i__] / ((double)(max)),	\
					   bs__[i__] / ((double)(max)), &x__, &y__, &Y__);		\
	      libclut_model_ciexyy_to_srgb(x__, y__, rexpr, &r__, &g__, &b__);				\
	      rs__[i__] = (type)(r__ * (double)(max));							\
	      gs__[i__] = (type)(g__ * (double)(max));							\
	      bs__[i__] = (type)(b__ * (double)(max));							\
	    }												\
	}												\
      else												\
	{												\
	  if (!(rtest) && !(gtest) && !(btest))								\
	    break;											\
	  libclut_model_srgb_to_ciexyy(rs__[i__] / ((double)(max)), gs__[i__] / ((double)(max)),	\
				       bs__[i__] / ((double)(max)), &x__, &y__, &Y__);			\
	  if (rtest)											\
	    for (i__ = 0; i__ < rn__; i__)								\
	      {												\
		libclut_model_ciexyy_to_srgb(x__, y__, rexpr, &r__, &g__, &b__);			\
		rs__[i__] = (type)((r__ * (double)(max));						\
	      }												\
	  if (gtest)											\
	    for (i__ = 0; i__ < gn__; i__)								\
	      {												\
		libclut_model_ciexyy_to_srgb(x__, y__, gexpr, &r__, &g__, &b__);			\
		gs__[i__] = (type)(g__ * (double)(max));						\
	      }												\
	  if (btest)											\
	    for (i__ = 0; i__ < bn__; i__)								\
	      {												\
		libclut_model_ciexyy_to_srgb(x__, y__, nexpr, &r__, &g__, &b__);			\
		bs__[i__] = (type)(b__ * (double)(max));						\
	      }												\
	}												\
    }													\
  while (0)



#endif

