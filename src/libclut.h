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
#define libclut_cie_contrast(ramp, max, type, r, g, b)							\
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
      if ((r == g) && (g == b) && (rn__ == gn__) && (gn__ == bn__))					\
	{												\
	  if (r == 1.0)											\
	    break;											\
	  for (i__ = 0; i__ < rn__; i__)								\
	    {												\
	      libclut_model_srgb_to_ciexyy(rs__[i__] / ((double)(max)), gs__[i__] / ((double)(max)),	\
					   bs__[i__] / ((double)(max)), &x__, &y__, &Y__);		\
	      libclut_model_ciexyy_to_srgb(x__, y__, (Y__ - 0.5) * r * 0.5, &r__, &g__, &b__);		\
	      rs__[i__] = (type)(r__ * (double)(max));							\
	      gs__[i__] = (type)(g__ * (double)(max));							\
	      bs__[i__] = (type)(b__ * (double)(max));							\
	    }												\
	}												\
      else												\
	{												\
	  if ((r == 1.0) && (g == 1.0) && (b == 1.0))							\
	    break;											\
	  libclut_model_srgb_to_ciexyy(rs__[i__] / ((double)(max)), gs__[i__] / ((double)(max)),	\
				       bs__[i__] / ((double)(max)), &x__, &y__, &Y__);			\
	  if (r != 1.0)											\
	    for (i__ = 0; i__ < rn__; i__)								\
	      {												\
		libclut_model_ciexyy_to_srgb(x__, y__, (Y__ - 0.5) * r + 0.5, &r__, &g__, &b__);	\
		rs__[i__] = (type)(r__ * (double)(max));						\
	      }												\
	  if (g != 1.0)											\
	    for (i__ = 0; i__ < gn__; i__)								\
	      {												\
		libclut_model_ciexyy_to_srgb(x__, y__, (Y__ - 0.5) * g + 0.5, &r__, &g__, &b__);	\
		gs__[i__] = (type)(g__ * (double)(max));						\
	      }												\
	  if (b != 1.0) 										\
	    for (i__ = 0; i__ < bn__; i__)								\
	      {												\
		libclut_model_ciexyy_to_srgb(x__, y__, (Y__ - 0.5) * b + 0.5, &r__, &g__, &b__);	\
		bs__[i__] = (type)(b__ * (double)(max));						\
	      }												\
	}												\
    }													\
  while (0)


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
#define libclut_cie_brightness(ramp, max, type, r, g, b)						\
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
      if ((r == g) && (g == b) && (rn__ == gn__) && (gn__ == bn__))					\
	{												\
	  if (r == 1.0)											\
	    break;											\
	  for (i__ = 0; i__ < rn__; i__)								\
	    {												\
	      libclut_model_srgb_to_ciexyy(rs__[i__] / ((double)(max)), gs__[i__] / ((double)(max)),	\
					   bs__[i__] / ((double)(max)), &x__, &y__, &Y__);		\
	      libclut_model_ciexyy_to_srgb(x__, y__, Y__ * r, &r__, &g__, &b__);			\
	      rs__[i__] = (type)(r__ * (double)(max));							\
	      gs__[i__] = (type)(g__ * (double)(max));							\
	      bs__[i__] = (type)(b__ * (double)(max));							\
	    }												\
	}												\
      else												\
	{												\
	  if ((r == 1.0) && (g == 1.0) && (b == 1.0))							\
	    break;											\
	  libclut_model_srgb_to_ciexyy(rs__[i__] / ((double)(max)), gs__[i__] / ((double)(max)),	\
				       bs__[i__] / ((double)(max)), &x__, &y__, &Y__);			\
	  if (r != 1.0)											\
	    for (i__ = 0; i__ < rn__; i__)								\
	      {												\
		libclut_model_ciexyy_to_srgb(x__, y__, Y__ * r, &r__, &g__, &b__);			\
		rs__[i__] = (type)(r__ * (double)(max));						\
	      }												\
	  if (g != 1.0)											\
	    for (i__ = 0; i__ < gn__; i__)								\
	      {												\
		libclut_model_ciexyy_to_srgb(x__, y__, Y__ * g, &r__, &g__, &b__);			\
		gs__[i__] = (type)(g__ * (double)(max));						\
	      }												\
	  if (b != 1.0)											\
	    for (i__ = 0; i__ < bn__; i__)								\
	      {												\
		libclut_model_ciexyy_to_srgb(x__, y__, Y__ * b, &r__, &g__, &b__);			\
		bs__[i__] = (type)(b__ * (double)(max));						\
	      }												\
	}												\
    }													\
  while (0)


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



#endif

