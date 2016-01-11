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



/**
 * Convert one component from [0, 1] linear RGB to [0, 1] sRGB.
 * 
 * @param   c  The linear RGB value.
 * @return     Corresponding sRGB value.
 */
double (libclut_model_linear_to_standard1)(double c)
{
  return libclut_model_linear_to_standard1(c);
}


/**
 * Convert [0, 1] linear RGB to [0, 1] sRGB.
 * 
 * @param  r  Pointer to the linear red component,
 *            and output parameter for the red component.
 * @param  g  Pointer to the linear green component,
 *            and output parameter for the green component.
 * @param  b  Pointer to the linear blue component,
 *            and output parameter for the blue component.
 */
void (libclut_model_linear_to_standard)(double* r, double* g, double* b)
{
  libclut_model_linear_to_standard(r, g, b);
}


/**
 * Convert one component from [0, 1] sRGB to [0, 1] linear RGB.
 * 
 * @param   c  The sRGB value.
 * @return     Corresponding linear RGB value.
 */
double (libclut_model_standard_to_linear1)(double c)
{
  return libclut_model_standard_to_linear1(c);
}


/**
 * Convert [0, 1] sRGB to [0, 1] linear RGB.
 * 
 * @param  r  Pointer to the red component, and output
 *            parameter for the linear red component.
 * @param  g  Pointer to the green component, and output
 *            parameter for the linear green component.
 * @param  b  Pointer to the blue component, and output
 *            parameter for the linear blue component.
 */
void (libclut_model_standard_to_linear)(double* r, double* g, double* b)
{
  libclut_model_standard_to_linear(r, g, b);
}


/**
 * Convert CIE xyY to CIE XYZ.
 * 
 * @param  x  The x parameter.
 * @param  y  The y parameter.
 * @param  Y  The Y parameter. This is also the Y (middle) parameter for the CIE XYZ colour.
 * @param  X  Output parameter for the X parameter.
 * @param  Z  Output parameter for the Z parameter.
 */
void (libclut_model_ciexyy_to_ciexyz)(double x, double y, double Y, double* X, double* Z)
{
  libclut_model_ciexyy_to_ciexyz(x, y, Y, X, Z);
}


/**
 * Convert CIE XYZ to CIE xyY.
 * 
 * @param  X  The X parameter.
 * @param  Y  The Y parameter. This is also the Y (last) parameter for the CIE xyY colour.
 * @param  Z  The Z parameter.
 * @param  x  Output parameter for the x parameter.
 * @param  y  Output parameter for the y parameter.
 */
void (libclut_model_ciexyz_to_ciexyy)(double X, double Y, double Z, double* x, double* y)
{
  libclut_model_ciexyz_to_ciexyy(X, Y, Z, x, y);
}


/**
 * Convert CIE XYZ to [0, 1] linear RGB.
 * 
 * @param  X  The X parameter.
 * @param  Y  The Y parameter.
 * @param  Z  The Z parameter.
 * @param  r  Output parameter for the red component.
 * @param  g  Output parameter for the green component.
 * @param  b  Output parameter for the blue component.
 */
void (libclut_model_ciexyz_to_linear)(double X, double Y, double Z, double* r, double* g, double* b)
{
  libclut_model_ciexyz_to_linear(X, Y, Z, r, g, b);
}


/**
 * Convert [0, 1] linear RGB to CIE XYZ.
 * 
 * @param  r  The red component.
 * @param  g  The green component.
 * @param  b  The blue component.
 * @param  X  Output parameter for the X parameter.
 * @param  Y  Output parameter for the Y parameter.
 * @param  Z  Output parameter for the Z parameter.
 */
void (libclut_model_linear_to_ciexyz)(double r, double g, double b, double* X, double* Y, double* Z)
{
  libclut_model_linear_to_ciexyz(r, g, b, X, Y, Z);
}


/**
 * Convert [0, 1] linear RGB to CIE xyY.
 * 
 * @param  r  The red component.
 * @param  g  The green component.
 * @param  b  The blue component.
 * @param  x  Output parameter for the x parameter.
 * @param  y  Output parameter for the y parameter.
 * @param  Y  Output parameter for the Y parameter.
 */
void (libclut_model_srgb_to_ciexyy)(double r, double g, double b, double* x, double* y, double* Y)
{
  libclut_model_srgb_to_ciexyy(r, g, b, x, y, Y);
}


/**
 * Convert CIE xyY to [0, 1] sRGB.
 * 
 * @param  x  The x parameter.
 * @param  y  The y parameter.
 * @param  Y  The Y parameter.
 * @param  r  Output parameter for the red component.
 * @param  g  Output parameter for the green component.
 * @param  b  Output parameter for the blue component.
 */
void (libclut_model_ciexyy_to_srgb)(double x, double y, double Y, double* r, double* g, double* b)
{
  libclut_model_ciexyy_to_srgb(x, y, Y, r, g, b);
}


/**
 * Convert from CIE XYZ to CIE L*a*b*.
 * 
 * @param  X  The X parameter.
 * @param  Y  The Y parameter.
 * @param  Z  The Z parameter.
 * @param  L  Output parameter for the L* component.
 * @param  a  Output parameter for the a* component.
 * @param  b  Output parameter for the b* component.
 */
void (libclut_model_ciexyz_to_cielab)(double X, double Y, double Z, double* L, double* a, double* b)
{
  libclut_model_ciexyz_to_cielab(X, Y, Z, L, a, b);
}


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
void (libclut_model_cielab_to_ciexyz)(double L, double a, double b, double* X, double* Y, double* Z)
{
  libclut_model_cielab_to_ciexyz(L, a, b, X, Y, Z);
}

