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

#include <errno.h>



/**
 * Convert one component from [0, 1] linear sRGB to [0, 1] sRGB.
 * 
 * @param   c  The linear sRGB value.
 * @return     Corresponding sRGB value.
 */
double (libclut_model_linear_to_standard1)(double c)
{
  return libclut_model_linear_to_standard1(c);
}


/**
 * Convert [0, 1] linear sRGB to [0, 1] sRGB.
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
 * Convert one component from [0, 1] sRGB to [0, 1] linear sRGB.
 * 
 * @param   c  The sRGB value.
 * @return     Corresponding linear sRGB value.
 */
double (libclut_model_standard_to_linear1)(double c)
{
  return libclut_model_standard_to_linear1(c);
}


/**
 * Convert [0, 1] sRGB to [0, 1] linear sRGB.
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
 * Convert CIE XYZ to [0, 1] linear sRGB.
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
 * Convert [0, 1] linear sRGB to CIE XYZ.
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
 * Convert [0, 1] linear sRGB to CIE xyY.
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


/**
 * Convert from CIE XYZ to CIE L*u*v*.
 * 
 * @param  X  The X parameter.
 * @param  Y  The Y parameter.
 * @param  Z  The Z parameter.
 * @param  Xn  The X component of the specified white object (white point).
 * @param  Yn  The Y component of the specified white object (white point).
 * @param  Zn  The Z component of the specified white object (white point).
 * @param  L  Output parameter for the L* component.
 * @param  u  Output parameter for the u* component.
 * @param  v  Output parameter for the v* component.
 */
void (libclut_model_ciexyz_to_cieluv)(double X, double Y, double Z, double Xn, double Yn, double Zn,
				      double* L, double* u, double* v)
{
  libclut_model_ciexyz_to_cieluv(X, Y, Z, Xn, Yn, Zn, L, u, v);
}


/**
 * Convert from CIE L*u*v* to CIE XYZ.
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
void (libclut_model_cieluv_to_ciexyz)(double L, double u, double v, double Xn, double Yn, double Zn,
				      double* X, double* Y, double* Z)
{
  libclut_model_cieluv_to_ciexyz(L, u, v, Xn, Yn, Zn, X, Y, Z);
}


/**
 * Convert from CIELCh to CIE L*u*v*.
 * 
 * @param  L  The L* component.
 * @param  C  The C*_uv component.
 * @param  h  The h_uv component.
 * @param  u  Output parameter for the u* parameter.
 * @param  v  Output parameter for the v* parameter.
 */
void (libclut_model_cielch_to_cieluv)(double C, double h, double* u, double* v)
{
  libclut_model_cielch_to_cieluv(C, h, u, v);
}


/**
 * Convert from CIE L*u*v* to CIELCh.
 * 
 * @param  L  The L* component.
 * @param  u  The u* component.
 * @param  v  The v* component.
 * @param  C  Output parameter for the C*_uv parameter.
 * @param  h  Output parameter for the h_uv parameter.
 */
void (libclut_model_cieluv_to_cielch)(double u, double v, double* C, double* h)
{
  libclut_model_cieluv_to_cielch(u, v, C, h);
}


/**
 * Convert from sRGB to YIQ.
 * 
 * @param  r  The R component.
 * @param  g  The G component.
 * @param  b  The B component.
 * @param  y  Output parameter for the Y parameter.
 * @param  i  Output parameter for the I parameter.
 * @param  q  Output parameter for the Q parameter.
 */
void (libclut_model_srgb_to_yiq)(double r, double g, double b, double* y, double* i, double* q)
{
  libclut_model_srgb_to_yiq(r, g, b, y, i, q);
}


/**
 * Convert from YIQ to sRGB.
 * 
 * @param  y  The Y component.
 * @param  i  The I component.
 * @param  q  The Q component.
 * @param  r  Output parameter for the R parameter.
 * @param  g  Output parameter for the G parameter.
 * @param  b  Output parameter for the B parameter.
 */
void (libclut_model_yiq_to_srgb)(double y, double i, double q, double* r, double* g, double* b)
{
  libclut_model_yiq_to_srgb(y, i, q, r, g, b);
}


/**
 * Convert from sRGB to YDbDr.
 * 
 * @param  r   The R component.
 * @param  g   The G component.
 * @param  b   The B component.
 * @param  y   Output parameter for the Y parameter.
 * @param  db  Output parameter for the Db parameter.
 * @param  dr  Output parameter for the Dr parameter.
 */
void (libclut_model_srgb_to_ydbdr)(double r, double g, double b, double* y, double* db, double* dr)
{
  libclut_model_srgb_to_ydbdr(r, g, b, y, db, dr);
}


/**
 * Convert from YDbDr to sRGB.
 * 
 * @param  y   The Y component.
 * @param  db  The Db component.
 * @param  dr  The Dr component.
 * @param  r   Output parameter for the R parameter.
 * @param  g   Output parameter for the G parameter.
 * @param  b   Output parameter for the B parameter.
 */
void (libclut_model_ydbdr_to_srgb)(double y, double db, double dr, double* r, double* g, double* b)
{
  libclut_model_ydbdr_to_srgb(y, db, dr, r, g, b);
}

/**
 * Convert from YUV to YDbDr.
 * 
 * @param  u   The U component.
 * @param  v   The V component.
 * @param  db  Output parameter for the Db parameter.
 * @param  dr  Output parameter for the Dr parameter.
 */
void (libclut_model_yuv_to_ydbdr)(double u, double v, double* db, double* dr)
{
  libclut_model_yuv_to_ydbdr(u, v, db, dr);
}


/**
 * Convert from YDbDr to YUV.
 * 
 * @param  db  The Db component.
 * @param  dr  The Dr component.
 * @param  u   Output parameter for the U parameter.
 * @param  v   Output parameter for the V parameter.
 */
void (libclut_model_ydbdr_to_yuv)(double db, double dr, double* u, double* v)
{
  libclut_model_ydbdr_to_yuv(db, dr, u, v);
}


/**
 * Convert from sRGB to YPbPr.
 * 
 * @param  r   The R component.
 * @param  g   The G component.
 * @param  b   The B component.
 * @param  y   Output parameter for the Y parameter.
 * @param  pb  Output parameter for the Pb parameter.
 * @param  pr  Output parameter for the Pr parameter.
 */
void (libclut_model_srgb_to_ypbpr)(double r, double g, double b, double* y, double* pb, double* pr)
{
  libclut_model_srgb_to_ypbpr(r, g, b, y, pb, pr);
}


/**
 * Convert from YPbPr to sRGB.
 * 
 * @param  y   The Y component.
 * @param  pb  The Pb component.
 * @param  pr  The Pr component.
 * @param  r   Output parameter for the R parameter.
 * @param  g   Output parameter for the G parameter.
 * @param  b   Output parameter for the B parameter.
 */
void (libclut_model_ypbpr_to_srgb)(double y, double pb, double pr, double* r, double* g, double* b)
{
  libclut_model_ypbpr_to_srgb(y, pb, pr, r, g, b);
}


/**
 * Convert from sRGB to YCgCo.
 * 
 * @param  r   The R component.
 * @param  g   The G component.
 * @param  b   The B component.
 * @param  y   Output parameter for the Y parameter.
 * @param  cg  Output parameter for the Cg parameter.
 * @param  co  Output parameter for the Co parameter.
 */
void (libclut_model_srgb_to_ycgco)(double r, double g, double b, double* y, double* cg, double* co)
{
  libclut_model_srgb_to_ycgco(r, g, b, y, cg, co);
}


/**
 * Convert from YCgCo to sRGB.
 * 
 * @param  y   The Y component.
 * @param  cg  The Cg component.
 * @param  co  The Co component.
 * @param  r   Output parameter for the R parameter.
 * @param  g   Output parameter for the G parameter.
 * @param  b   Output parameter for the B parameter.
 */
void (libclut_model_ycgco_to_srgb)(double y, double cg, double co, double* r, double* g, double* b)
{
  libclut_model_ycgco_to_srgb(y, cg, co, r, g, b);
}


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
void (libclut_model_cie_1960_ucs_to_ciexyz)(double u, double v, double Y, double* x, double* y, double* z)
{
  libclut_model_cie_1960_ucs_to_ciexyz(u, v, Y, x, y, z);
}


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
void (libclut_model_ciexyz_to_cie_1960_ucs)(double x, double y, double z, double* u, double* v, double* Y)
{
  libclut_model_ciexyz_to_cie_1960_ucs(x, y, z, u, v, Y);
}


/**
 * Convert from CIEUVW to CIE 1960 UCS.
 * 
 * @param  U   The U* component.
 * @param  V   The V* component.
 * @param  W   The W* component.
 * @param  u0  The u parameter for the white point.
 * @param  v0  The v parameter for the white point.
 * @param  u   Output parameter for the u parameter.
 * @param  v   Output parameter for the v parameter.
 * @param  Y   Output parameter for the Y parameter.
 */
void (libclut_model_cieuvw_to_cie_1960_ucs)(double U, double V, double W, double u0, double v0,
					    double* u, double* v, double* Y)
{
  libclut_model_cieuvw_to_cie_1960_ucs(U, V, W, u0, v0, u, v, Y);
}


/**
 * Convert from CIE 1960 UCS to CIEUVW.
 * 
 * Requires linking with `-lm`.
 * 
 * @param  u   The u component.
 * @param  v   The v component.
 * @param  Y   The Y component.
 * @param  u0  The u parameter for the white point.
 * @param  v0  The v parameter for the white point.
 * @param  U   Output parameter for the U* parameter.
 * @param  V   Output parameter for the V* parameter.
 * @param  W   Output parameter for the W* parameter.
 */
void (libclut_model_cie_1960_ucs_to_cieuvw)(double u, double v, double Y, double u0, double v0,
					    double* U, double* V, double* W)
{
  libclut_model_cie_1960_ucs_to_cieuvw(u, v, Y, u0, v0, U, V, W);
}



/**
 * Divide all values in a row by a divisor.
 * 
 * @param  m  The first part of the row.
 * @param  a  The second part of the row.
 * @param  d  The divisor.
 */
static void divrow(double m[3], double a[3], double d)
{
  m[0] /= d, m[1] /= d, m[2] /= d;
  a[0] /= d, a[1] /= d, a[2] /= d;
}

/**
 * Subtract all values in a row by corresponding value
 * in another row multiplied by a common value.
 * 
 * @param  a1  The first part of the minuend/difference row.
 * @param  a2  The second part of the minuend/difference row.
 * @param  b1  The first part of the subtrahend row.
 * @param  b2  The second part of the subtrahend row.
 * @param  m   The multiplier.
 */
static void subrow(double a1[3], double a2[3], double b1[3], double b2[3], double m)
{
  a1[0] -= b1[0] * m, a1[1] -= b1[1] * m, a1[2] -= b1[2] * m;
  a2[0] -= b2[0] * m, a2[1] -= b2[1] * m, a2[2] -= b2[2] * m;
}


/**
 * Invert a matrix.
 * 
 * @param   M  The matrix to invert, will be modified to an
 *             identity matrix, possibly with reordered rows.
 * @param   A  The inversion of M (as input).
 * @return     1 on success, 0 if the matrix is not invertible.
 */
static int invert(libclut_colour_space_conversion_matrix_t M, libclut_colour_space_conversion_matrix_t A)
{
  int r0 = 0, r1 = 1, r2 = 2, t, swapped = 0;
  libclut_colour_space_conversion_matrix_t T;
  
  A[0][0] = A[1][1] = A[2][2] = 1;
  A[0][1] = A[0][2] = A[1][0] = A[1][2] = A[2][0] = A[2][1] = 0;
  
  if (libclut_0__(M[r0][0]))
    {
      if (libclut_0__(M[r1][0]))
	{
	  if (libclut_0__(M[r2][0]))
	    return 0;
	  t = r0, r0 = r2, r2 = t;
	}
      else
	t = r0, r0 = r1, r1 = t;
      swapped = 1;
    }
  
  divrow(M[r0], A[r0], M[r0][0]);
  subrow(M[r1], A[r1], M[r0], A[r0], M[r1][0]);
  subrow(M[r2], A[r2], M[r0], A[r0], M[r2][0]);
  
  if (libclut_0__(M[r1][1]))
    {
      if (libclut_0__(M[r2][1]))
	return 0;
      t = r1, r1 = r2, r2 = t;
      swapped = 1;
    }
  
  divrow(M[r1], A[r1], M[r1][1]);
  subrow(M[r2], A[r2], M[r1], A[r1], M[r2][1]);
  
  if (libclut_0__(M[r2][2]))
    return 0;
  
  divrow(M[r2], A[r2], M[r2][2]);
  
  subrow(M[r1], A[r1], M[r2], A[r2], M[r1][2]);
  subrow(M[r0], A[r0], M[r2], A[r2], M[r0][2]);
  
  subrow(M[r0], A[r0], M[r1], A[r1], M[r0][1]);
  
  if (swapped)
    {
      memcpy(T, A, sizeof(T));
      memcpy(A[0], T[r0], sizeof(*T));
      memcpy(A[1], T[r1], sizeof(*T));
      memcpy(A[2], T[r2], sizeof(*T));
    }
  
  return 1;
}


/**
 * Create an RGB to CIE XYZ conversion matrix.
 * 
 * @param   cs  The colour space.
 * @param   M   The output matrix.
 * @return      Zero on success, -1 on error.
 * 
 * @throws  EINVAL  The colour space cannot be used.
 */
static int get_conversion_matrix(const libclut_rgb_colour_space_t* cs, libclut_colour_space_conversion_matrix_t M)
{
#define XYY_TO_XYZ(x, y, Y, Xp, Yp, Zp)		\
  (libclut_0__(Y)) ?				\
    (*(Xp) = *(Zp) = *(Yp) = (Y)) :		\
    (*(Xp) = (x) * (Y) / (y),			\
     *(Yp) = (Y),				\
     *(Zp) = (1 - (x) - (y)) * (Y) / (y))
  
  double Xr, Yr, Zr, Xg, Yg, Zg, Xb, Yb, Zb, Xw, Yw, Zw, Sr, Sg, Sb;
  libclut_colour_space_conversion_matrix_t M2;
  
  XYY_TO_XYZ(cs->red_x,   cs->red_y,   1,           &Xr, &Yr, &Zr);
  XYY_TO_XYZ(cs->green_x, cs->green_y, 1,           &Xg, &Yg, &Zg);
  XYY_TO_XYZ(cs->blue_x,  cs->blue_y,  1,           &Xb, &Yb, &Zb);
  XYY_TO_XYZ(cs->white_x, cs->white_y, cs->white_Y, &Xw, &Yw, &Zw);
  
  M2[0][0] = Xr, M2[0][1] = Xg, M2[0][2] = Xb;
  M2[1][0] = Yr, M2[1][1] = Yg, M2[1][2] = Yb;
  M2[2][0] = Zr, M2[2][1] = Zg, M2[2][2] = Zb;
  
  if (!invert(M2, M))
    return errno = EINVAL, -1;
  
  Sr = M[0][0] * Xw + M[0][1] * Yw + M[0][2] * Zw;
  Sg = M[1][0] * Xw + M[1][1] * Yw + M[1][2] * Zw;
  Sb = M[2][0] * Xw + M[2][1] * Yw + M[2][2] * Zw;
  
  M[0][0] = Sr * Xr, M[0][1] = Sg * Xg, M[0][2] = Sb * Xb;
  M[1][0] = Sr * Yr, M[1][1] = Sg * Yg, M[1][2] = Sb * Yb;
  M[2][0] = Sr * Zr, M[2][1] = Sg * Zg, M[2][2] = Sb * Zb;
  
  return 0;
  
#undef XYY_TO_XYZ
}


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
int libclut_model_get_rgb_conversion_matrix(const libclut_rgb_colour_space_t* from,
					    const libclut_rgb_colour_space_t* to,
					    libclut_colour_space_conversion_matrix_t M,
					    libclut_colour_space_conversion_matrix_t Minv)
{
  libclut_colour_space_conversion_matrix_t A, B;

  if (from != NULL)
    {
      if (get_conversion_matrix(from, A))
	return -1;
    }
  else
    {
      A[0][0] = A[1][1] = A[2][2] = 1;
      A[0][1] = A[1][0] = A[2][0] = 0;
      A[0][2] = A[1][2] = A[2][1] = 0;
    }
  
  if (to != NULL)
    {
      if (get_conversion_matrix(to, M))
	return -1;
      if (!invert(M, B))
	return errno = EINVAL, -1;
      
      if (from != NULL)
	{
	  M[0][0] = B[0][0] * A[0][0] + B[0][1] * A[1][0] + B[0][2] * A[2][0];
	  M[0][1] = B[0][0] * A[0][1] + B[0][1] * A[1][1] + B[0][2] * A[2][1];
	  M[0][2] = B[0][0] * A[0][2] + B[0][1] * A[1][2] + B[0][2] * A[2][2];
	  
	  M[1][0] = B[1][0] * A[0][0] + B[1][1] * A[1][0] + B[1][2] * A[2][0];
	  M[1][1] = B[1][0] * A[0][1] + B[1][1] * A[1][1] + B[1][2] * A[2][1];
	  M[1][2] = B[1][0] * A[0][2] + B[1][1] * A[1][2] + B[1][2] * A[2][2];
	  
	  M[2][0] = B[2][0] * A[0][0] + B[2][1] * A[1][0] + B[2][2] * A[2][0];
	  M[2][1] = B[2][0] * A[0][1] + B[2][1] * A[1][1] + B[2][2] * A[2][1];
	  M[2][2] = B[2][0] * A[0][2] + B[2][1] * A[1][2] + B[2][2] * A[2][2];
	}
      else
	memcpy(M, B, sizeof(B));
    }
  else
    memcpy(M, A, sizeof(A));
  
  if (Minv != NULL)
    {
      memcpy(A, M, sizeof(A));
      if (!invert(A, Minv))
	return errno = EINVAL, -1;
    }
  
  return 0;
}


/**
 * Convert an RGB colour into another RGB colour space.
 * 
 * Both RGB colour spaces must have same gamma functions as sRGB.
 * 
 * @param  r      The red component of the colour to convert.
 * @param  g      The green component of the colour to convert.
 * @param  b      The blue component of the colour to convert.
 * @param  M      Conversion matrix, create with `libclut_model_get_rgb_conversion_matrix`.
 * @param  out_r  Output parameter for the new red component.
 * @param  out_g  Output parameter for the new green component.
 * @param  out_b  Output parameter for the new blue component.
 */
void (libclut_model_convert_rgb)(double r, double g, double b, libclut_colour_space_conversion_matrix_t M,
				  double* out_r, double* out_g, double* out_b)
{
  libclut_model_convert_rgb(r, g, b, M, out_r, out_g, out_b);
}


/**
 * Convert an RGB colour of a custom RGB colour space to CIE XYZ.
 * 
 * The RGB colour space must have same gamma functions as sRGB.
 * 
 * @param  r  The red component.
 * @param  g  The green component.
 * @param  b  The blue component.
 * @param  M  Conversion matrix, create with `libclut_model_get_rgb_conversion_matrix`.
 * @param  x  Output parameter for the X component.
 * @param  y  Output parameter for the Y component.
 * @param  z  Output parameter for the Z component.
 */
void (libclut_model_rgb_to_ciexyz)(double r, double g, double b, libclut_colour_space_conversion_matrix_t M,
				   double* x, double* y, double* z)
{
  libclut_model_rgb_to_ciexyz(r, g, b, M, x, y, z);
}


/**
 * Convert a CIE XYZ colour to a custom RGB colour space.
 * 
 * The RGB colour space must have same gamma functions as sRGB.
 * 
 * @param  x  The X component.
 * @param  y  The Y component.
 * @param  z  The Z component.
 * @param  M  Conversion matrix, create with `libclut_model_get_rgb_conversion_matrix`.
 * @param  r  Output parameter for the red component.
 * @param  g  Output parameter for the green component
 * @param  b  Output parameter for the blue component.
 */
void (libclut_model_ciexyz_to_rgb)(double x, double y, double z, libclut_colour_space_conversion_matrix_t M,
				   double* r, double* g, double* b)
{
  libclut_model_ciexyz_to_rgb(x, y, z, M, r, g, b);
}

