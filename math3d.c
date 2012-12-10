/** 
 * Source file for the Math3d library. The C-Runtime has math.h, this file and 
 * the accompanying math.c are meant to suppliment math.h by adding geometry
 * and math routines useful for graphics, simulation, and physics applications 
 * (3D stuff).
 * Note: This code is based on the implementation provided by Richard S. Wright 
 * Jr.
 */
#define _MATH3D_C_

#include "math3d.h"

/* 
 * Local defintions
 */
#define A(row,col)  a[(col<<2)+row]
#define B(row,col)  b[(col<<2)+row]
#define P(row,col)  product[(col<<2)+row]

/*
 * Implementation
 */

/*
 * Initializes the components of the vector as 0s.
 */
void m3dNullVector2f(M3DVector2f v)
{
    v[0] = v[1] = 0.0f;
}

void m3dNullVector3f(M3DVector3f v)
{
    v[0] = v[1] = v[2] = 0.0f;
}

void m3dNullVector4f(M3DVector4f v)
{
    v[0] = v[1] = v[2] = v[3] = 0.0f;
}

void m3dNullVector2d(M3DVector2d v)
{
    v[0] = v[1] = 0.0;
}

void m3dNullVector3d(M3DVector3d v)
{
    v[0] = v[1] = v[2] = 0.0;
}

void m3dNullVector4d(M3DVector4d v)
{
    v[0] = v[1] = v[2] = v[3] = 0.0;
}

/*
 * Returns the same number if it is a power of two. 
 * Returns a larger integer if it is not a 
 * power of two. The larger integer is the next
 * highest power of two.
 */
unsigned int m3dIsPOW2(unsigned int iValue)
{
	unsigned int nPow2 = 1;
    
	while(iValue > nPow2)
		nPow2 = (nPow2 << 1);
	return nPow2;
}

/* 
 * Load vector with (x, y, z, w).
 */
void m3dLoadVector2f(M3DVector2f v, float x, float y)
{
	v[0] = x; v[1] = y; 
}

void m3dLoadVector2d(M3DVector2d v, float x, float y)
{
	v[0] = x; v[1] = y; 
}

void m3dLoadVector3f(M3DVector3f v, float x, float y, float z)
{
	v[0] = x; v[1] = y; v[2] = z;
}

void m3dLoadVector3d(M3DVector3d v, double x, double y, double z)
{
	v[0] = x; v[1] = y; v[2] = z;
}

void m3dLoadVector4f(M3DVector4f v, float x, float y, float z, float w)
{
	v[0] = x; v[1] = y; v[2] = z; v[3] = w;
}

void m3dLoadVector4d(M3DVector4d v, double x, double y, double z, double w)
{
	v[0] = x; v[1] = y; v[2] = z; v[3] = w;
}

/*
 * Copy vector src into vector dst.
 */
void m3dCopyVector2f(M3DVector2f dst, M3DVector2f src)
{
	memcpy(dst, src, sizeof(M3DVector2f));
}

void m3dCopyVector2d(M3DVector2d dst, M3DVector2d src)
{
	memcpy(dst, src, sizeof(M3DVector2d));
}

void m3dCopyVector3f(M3DVector3f dst, M3DVector3f src)
{
	memcpy(dst, src, sizeof(M3DVector3f));
}

void m3dCopyVector3d(M3DVector3d dst, M3DVector3d src)
{
	memcpy(dst, src, sizeof(M3DVector3d));
}

void m3dCopyVector4f(M3DVector4f dst, M3DVector4f src)
{
	memcpy(dst, src, sizeof(M3DVector4f));
}

void m3dCopyVector4d(M3DVector4d dst, M3DVector4d src)
{
	memcpy(dst, src, sizeof(M3DVector4d));
}

/*
 * Add vectors (r, a, b) r = a + b.
 */
void m3dAddVectors2f(M3DVector2f r, M3DVector2f a, M3DVector2f b)
{
	r[0] = a[0] + b[0];	r[1] = a[1] + b[1]; 
}

void m3dAddVectors2d(M3DVector2d r, M3DVector2d a, M3DVector2d b)
{
	r[0] = a[0] + b[0];	r[1] = a[1] + b[1]; 
}

void m3dAddVectors3f(M3DVector3f r, M3DVector3f a, M3DVector3f b)
{
	r[0] = a[0] + b[0];	r[1] = a[1] + b[1]; r[2] = a[2] + b[2];	
}

void m3dAddVectors3d(M3DVector3d r, M3DVector3d a, M3DVector3d b)
{
	r[0] = a[0] + b[0];	r[1] = a[1] + b[1]; r[2] = a[2] + b[2];	
}

void m3dAddVectors4f(M3DVector4f r, M3DVector4f a, M3DVector4f b)
{
	r[0] = a[0] + b[0];	r[1] = a[1] + b[1]; r[2] = a[2] + b[2];	r[3] = a[3] + b[3];	
}

void m3dAddVectors4d(M3DVector4d r, M3DVector4d a, M3DVector4d b)
{
	r[0] = a[0] + b[0];	r[1] = a[1] + b[1]; r[2] = a[2] + b[2];	r[3] = a[3] + b[3];	
}

/*
 * Subtract vectors (r, a, b) r = a - b.
 */
void m3dSubtractVectors2f(M3DVector2f r, M3DVector2f a, M3DVector2f b)
{
	r[0] = a[0] - b[0];	r[1] = a[1] - b[1]; 
}

void m3dSubtractVectors2d(M3DVector2d r, M3DVector2d a, M3DVector2d b)
{
	r[0] = a[0] - b[0];	r[1] = a[1] - b[1]; 
}

void m3dSubtractVectors3f(M3DVector3f r, M3DVector3f a, M3DVector3f b)
{
	r[0] = a[0] - b[0];	r[1] = a[1] - b[1]; r[2] = a[2] - b[2];	
}

void m3dSubtractVectors3d(M3DVector3d r, M3DVector3d a, M3DVector3d b)
{
	r[0] = a[0] - b[0];	r[1] = a[1] - b[1]; r[2] = a[2] - b[2];	
}

void m3dSubtractVectors4d(M3DVector4f r, M3DVector4f a, M3DVector4f b)
{
	r[0] = a[0] - b[0];	r[1] = a[1] - b[1]; r[2] = a[2] - b[2];	r[3] = a[3] - b[3];	
}

void m3dSubtractVectors4f(M3DVector4d r, M3DVector4d a, M3DVector4d b)
{
	r[0] = a[0] - b[0];	r[1] = a[1] - b[1]; r[2] = a[2] - b[2];	r[3] = a[3] - b[3];	
}

/*
 * Scale vectors (in place).
 */
void m3dScaleVector2f(M3DVector2f v, float scale)
{
	v[0] *= scale; v[1] *= scale;
}

void m3dScaleVector2d(M3DVector2d v, double scale)
{
	v[0] *= scale; v[1] *= scale;
}

void m3dScaleVector3f(M3DVector3f v, float scale)
{
	v[0] *= scale; v[1] *= scale; v[2] *= scale;
}

void m3dScaleVector3d(M3DVector3d v, double scale)
{
	v[0] *= scale; v[1] *= scale; v[2] *= scale;
}

void m3dScaleVector4f(M3DVector4f v, float scale)
{
	v[0] *= scale; v[1] *= scale; v[2] *= scale; v[3] *= scale;
}

void m3dScaleVector4d(M3DVector4d v, double scale)
{
	v[0] *= scale; v[1] *= scale; v[2] *= scale; v[3] *= scale;
}

/*
 * Cross product
 * u x v = result
 * We only need one version for floats, and one version for doubles. A 3 component
 * vector fits in a 4 component vector. If  M3DVector4d or M3DVector4f are passed
 * we will be OK because 4th component is not used.
 */
void m3dCrossProduct3f(M3DVector3f result, M3DVector3f u, M3DVector3f v)
{
	result[0] = u[1]*v[2] - v[1]*u[2];
	result[1] = -u[0]*v[2] + v[0]*u[2];
	result[2] = u[0]*v[1] - v[0]*u[1];
}

void m3dCrossProduct3d(M3DVector3d result, M3DVector3d u, M3DVector3d v)
{
	result[0] = u[1]*v[2] - v[1]*u[2];
	result[1] = -u[0]*v[2] + v[0]*u[2];
	result[2] = u[0]*v[1] - v[0]*u[1];
}

/*
 * Dot product, only for three component vectors -> return u dot v
 */
float m3dDotProduct3f(M3DVector3f u, M3DVector3f v)
{
	return u[0]*v[0] + u[1]*v[1] + u[2]*v[2]; 
}

double m3dDotProduct3d(M3DVector3d u, M3DVector3d v)
{
	return u[0]*v[0] + u[1]*v[1] + u[2]*v[2]; 
}

/*
 * Angle between vectors, only for three component vectors. 
 * Angle is in radians...
 */
float m3dGetAngleBetweenVectors3f(M3DVector3f u, M3DVector3f v)
{
    float dTemp = m3dDotProduct3f(u, v);
    return (float)(acos((double)dTemp));
}

double m3dGetAngleBetweenVectors3d(M3DVector3d u, M3DVector3d v)
{
    double dTemp = m3dDotProduct3d(u, v);
    return acos(dTemp);
}

/*
 * Get Square of a vectors length (only for three component vectors)
 */
float m3dGetVectorLengthSquared3f(M3DVector3f u)
{
	return (u[0] * u[0]) + (u[1] * u[1]) + (u[2] * u[2]);
}

double m3dGetVectorLengthSquared3d(M3DVector3d u)
{
	return (u[0] * u[0]) + (u[1] * u[1]) + (u[2] * u[2]);
}

/*
 * Get lenght of vector.
 */
float m3dGetVectorLength3f(M3DVector3f u)
{
	return (float)(sqrt(m3dGetVectorLengthSquared3f(u)));
}

double m3dGetVectorLength3d(M3DVector3d u)
{
	return sqrt(m3dGetVectorLengthSquared3d(u));
}

/*
 * Normalize a vector.
 */
void m3dNormalizeVector3f(M3DVector3f u)
{
	m3dScaleVector3f(u, 1.0f / m3dGetVectorLength3f(u));
}

void m3dNormalizeVector3d(M3DVector3d u)
{
	m3dScaleVector3d(u, 1.0 / m3dGetVectorLength3d(u));
}

/*
 * Get the distance between two points. The distance between two points is just
 * the magnitude of the difference between two vectors
 */
float m3dGetDistanceSquared3f(M3DVector3f u, M3DVector3f v)
{
	float x = u[0] - v[0];
	x = x*x;
	
	float y = u[1] - v[1];
	y = y*y;

	float z = u[2] - v[2];
	z = z*z;

	return (x + y + z);
}

double m3dGetDistanceSquared3d(M3DVector3d u, M3DVector3d v)
{
	double x = u[0] - v[0];
	x = x*x;
	
	double y = u[1] - v[1];
	y = y*y;

	double z = u[2] - v[2];
	z = z*z;

	return (x + y + z);
}

float m3dGetDistance3f(M3DVector3f u, M3DVector3f v)
{
	return (float)(sqrt(m3dGetDistanceSquared3f(u, v)));
}

double m3dGetDistance3d(M3DVector3d u, M3DVector3d v)
{
	return sqrt(m3dGetDistanceSquared3d(u, v));
}

float m3dGetMagnitudeSquared3f(M3DVector3f u)
{
	return u[0]*u[0] + u[1]*u[1] + u[2]*u[2];
}

double m3dGetMagnitudeSquared3d(M3DVector3d u)
{
	return u[0]*u[0] + u[1]*u[1] + u[2]*u[2];
}

float m3dGetMagnitude3f(M3DVector3f u)
{
	return (float)(sqrt(m3dGetMagnitudeSquared3f(u)));
}

double m3dGetMagnitude3d(M3DVector3d u)
{
	return sqrt(m3dGetMagnitudeSquared3d(u));
}

/*
 * Copy matrix
 */
void m3dCopyMatrix33f(M3DMatrix33f dst, M3DMatrix33f src)
{
	memcpy(dst, src, sizeof(M3DMatrix33f));
}

void m3dCopyMatrix33d(M3DMatrix33d dst, M3DMatrix33d src)
{
	memcpy(dst, src, sizeof(M3DMatrix33d));
}

void m3dCopyMatrix44f(M3DMatrix44f dst, M3DMatrix44f src)
{
	memcpy(dst, src, sizeof(M3DMatrix44f));
}

void m3dCopyMatrix44d(M3DMatrix44d dst, M3DMatrix44d src)
{
	memcpy(dst, src, sizeof(M3DMatrix44d));
}

/*
 * Load identity
 */
void m3dLoadIdentity33f(M3DMatrix33f m)
{
	static M3DMatrix33f	identity = { 1.0f, 0.0f, 0.0f ,
									 0.0f, 1.0f, 0.0f,
									 0.0f, 0.0f, 1.0f };

	memcpy(m, identity, sizeof(M3DMatrix33f));
}

void m3dLoadIdentity33d(M3DMatrix33d m)
{
	static M3DMatrix33d	identity = { 1.0, 0.0, 0.0 ,
									 0.0, 1.0, 0.0,
									 0.0, 0.0, 1.0 };

	memcpy(m, identity, sizeof(M3DMatrix33d));
}

void m3dLoadIdentity44f(M3DMatrix44f m)
{
	static M3DMatrix44f	identity = { 1.0f, 0.0f, 0.0f, 0.0f,
									 0.0f, 1.0f, 0.0f, 0.0f,
									 0.0f, 0.0f, 1.0f, 0.0f,
									 0.0f, 0.0f, 0.0f, 1.0f };

	memcpy(m, identity, sizeof(M3DMatrix44f));
}

void m3dLoadIdentity44d(M3DMatrix44d m)
{
	static M3DMatrix44d	identity = { 1.0, 0.0, 0.0, 0.0,
									 0.0, 1.0, 0.0, 0.0,
									 0.0, 0.0, 1.0, 0.0,
									 0.0, 0.0, 0.0, 1.0 };

	memcpy(m, identity, sizeof(M3DMatrix44d));
}

/*
 * Get/set column.
 */
void m3dGetMatrixColumn33f(M3DVector3f dst, M3DMatrix33f src, int column)
{
	memcpy(dst, src + (3 * column), sizeof(float) * 3);
}

void m3dGetMatrixColumn33d(M3DVector3d dst, M3DMatrix33d src, int column)
{
	memcpy(dst, src + (3 * column), sizeof(double) * 3); 
}

void m3dSetMatrixColumn33f(M3DMatrix33f dst, M3DVector3f src, int column)
{
	memcpy(dst + (3 * column), src, sizeof(float) * 3);
}

void m3dSetMatrixColumn33d(M3DMatrix33d dst, M3DVector3d src, int column)
{
	memcpy(dst + (3 * column), src, sizeof(double) * 3);
}

void m3dGetMatrixColumn44f(M3DVector4f dst, M3DMatrix44f src, int column)
{
	memcpy(dst, src + (4 * column), sizeof(float) * 4);
}

void m3dGetMatrixColumn44d(M3DVector4d dst, M3DMatrix44d src, int column)
{
	memcpy(dst, src + (4 * column), sizeof(double) * 4);
}

void m3dSetMatrixColumn44f(M3DMatrix44f dst, M3DVector4f src, int column)
{
	memcpy(dst + (4 * column), src, sizeof(float) * 4);
}

void m3dSetMatrixColumn44d(M3DMatrix44d dst, M3DVector4d src, int column)
{
	memcpy(dst + (4 * column), src, sizeof(double) * 4);
}

/* 
 * Get/Set RowCol - Remember column major ordering...
 */
void m3dSetMatrixRowCol33f(M3DMatrix33f m, int row, int col, float value)
{
	m[(col * 3) + row] = value;
}

float m3dGetMatrixRowCol33f(M3DMatrix33f m, int row, int col)
{
	return m[(col * 3) + row]; 
}

void m3dSetMatrixRowCol33d(M3DMatrix33d m, int row, int col, double value)
{
	m[(col * 3) + row] = value; 
}

double m3dGetMatrixRowCol33d(M3DMatrix33d m, int row, int col)
{
	return m[(col * 3) + row];
}

void m3dSetMatrixRowCol44f(M3DMatrix44f m, int row, int col, float value)
{
	m[(col * 4) + row] = value; 
}

float m3dGetMatrixRowCol44f(M3DMatrix44f m, int row, int col)
{
	return m[(col * 4) + row];
}

void m3dSetMatrixRowCol44d(M3DMatrix44d m, int row, int col, double value)
{
	m[(col * 4) + row] = value;
}

double m3dGetMatrixRowCol44d(M3DMatrix44d m, int row, int col)
{
	return m[(col * 4) + row];
}

/*
 * Extract a rotation matrix from a 4x4 matrix
 */
void m3dExtractRotation33f(M3DMatrix33f dst, M3DMatrix44f src)
{
	memcpy(dst, src, sizeof(float) * 3);
	memcpy(dst + 3, src + 4, sizeof(float) * 3);
	memcpy(dst + 6, src + 8, sizeof(float) * 3);
}

void m3dExtractRotation33d(M3DMatrix33d dst, M3DMatrix44d src)
{
	memcpy(dst, src, sizeof(double) * 3);
	memcpy(dst + 3, src + 4, sizeof(double) * 3);
	memcpy(dst + 6, src + 8, sizeof(double) * 3);
}

/*
 * Inject Rotation (3x3) into a full 4x4 matrix...
 */
void m3dInjectRotation44f(M3DMatrix44f dst, M3DMatrix33f src)
{
	memcpy(dst, src, sizeof(float) * 4);
	memcpy(dst + 4, src + 4, sizeof(float) * 4);
	memcpy(dst + 8, src + 8, sizeof(float) * 4);
}

void m3dInjectRotation44d(M3DMatrix44d dst, M3DMatrix33d src)
{
	memcpy(dst, src, sizeof(double) * 4);
	memcpy(dst + 4, src + 4, sizeof(double) * 4);
	memcpy(dst + 8, src + 8, sizeof(double) * 4);
}

#define A(row,col)  a[(col<<2)+row]
#define B(row,col)  b[(col<<2)+row]
#define P(row,col)  product[(col<<2)+row]

/*
 * Multiply two 4x4 matricies
 */
void m3dMatrixMultiply44f(M3DMatrix44f product, M3DMatrix44f a, M3DMatrix44f b )
{
	int i;
	for (i = 0; i < 4; i++) {
		float ai0=A(i,0),  ai1=A(i,1),  ai2=A(i,2),  ai3=A(i,3);
		P(i,0) = ai0 * B(0,0) + ai1 * B(1,0) + ai2 * B(2,0) + ai3 * B(3,0);
		P(i,1) = ai0 * B(0,1) + ai1 * B(1,1) + ai2 * B(2,1) + ai3 * B(3,1);
		P(i,2) = ai0 * B(0,2) + ai1 * B(1,2) + ai2 * B(2,2) + ai3 * B(3,2);
		P(i,3) = ai0 * B(0,3) + ai1 * B(1,3) + ai2 * B(2,3) + ai3 * B(3,3);
	}
}

void m3dMatrixMultiply44d(M3DMatrix44d product, M3DMatrix44d a, M3DMatrix44d b )
{
	int i;
	for (i = 0; i < 4; i++) {
		double ai0=A(i,0),  ai1=A(i,1),  ai2=A(i,2),  ai3=A(i,3);
		P(i,0) = ai0 * B(0,0) + ai1 * B(1,0) + ai2 * B(2,0) + ai3 * B(3,0);
		P(i,1) = ai0 * B(0,1) + ai1 * B(1,1) + ai2 * B(2,1) + ai3 * B(3,1);
		P(i,2) = ai0 * B(0,2) + ai1 * B(1,2) + ai2 * B(2,2) + ai3 * B(3,2);
		P(i,3) = ai0 * B(0,3) + ai1 * B(1,3) + ai2 * B(2,3) + ai3 * B(3,3);
	}
}
#undef A
#undef B
#undef P

#define A33(row,col)  a[(col*3)+row]
#define B33(row,col)  b[(col*3)+row]
#define P33(row,col)  product[(col*3)+row]

/*
 * Multiply two 3x3 matricies
 */
void m3dMatrixMultiply33f(M3DMatrix33f product, M3DMatrix33f a, M3DMatrix33f b )
{
	int i;
	for (i = 0; i < 3; i++) {
		float ai0=A33(i,0), ai1=A33(i,1),  ai2=A33(i,2);
		P33(i,0) = ai0 * B33(0,0) + ai1 * B33(1,0) + ai2 * B33(2,0);
		P33(i,1) = ai0 * B33(0,1) + ai1 * B33(1,1) + ai2 * B33(2,1);
		P33(i,2) = ai0 * B33(0,2) + ai1 * B33(1,2) + ai2 * B33(2,2);
	}
}

void m3dMatrixMultiply33d(M3DMatrix33d product, M3DMatrix33d a, M3DMatrix33d b )
{
	int i;
	for (i = 0; i < 3; i++) {
		double ai0=A33(i,0),  ai1=A33(i,1),  ai2=A33(i,2);
		P33(i,0) = ai0 * B33(0,0) + ai1 * B33(1,0) + ai2 * B33(2,0);
		P33(i,1) = ai0 * B33(0,1) + ai1 * B33(1,1) + ai2 * B33(2,1);
		P33(i,2) = ai0 * B33(0,2) + ai1 * B33(1,2) + ai2 * B33(2,2);
	}
}

#undef A33
#undef B33
#undef P33


/*
 * Transform - Does rotation and translation via a 4x4 matrix. Transforms
 * a point or vector.
 */
void m3dTransformVector3f(M3DVector3f vOut, M3DVector3f v, M3DMatrix44f m)
{
    vOut[0] = m[0] * v[0] + m[4] * v[1] + m[8] *  v[2] + m[12];// * v[3];	 
    vOut[1] = m[1] * v[0] + m[5] * v[1] + m[9] *  v[2] + m[13];// * v[3];	
    vOut[2] = m[2] * v[0] + m[6] * v[1] + m[10] * v[2] + m[14];// * v[3];	
}

void m3dTransformVector3d(M3DVector3d vOut, M3DVector3d v, M3DMatrix44d m)
{
    vOut[0] = m[0] * v[0] + m[4] * v[1] + m[8] *  v[2] + m[12];// * v[3];	 
    vOut[1] = m[1] * v[0] + m[5] * v[1] + m[9] *  v[2] + m[13];// * v[3];	
    vOut[2] = m[2] * v[0] + m[6] * v[1] + m[10] * v[2] + m[14];// * v[3];	
}

void m3dTransformVector4f(M3DVector4f vOut, M3DVector4f v, M3DMatrix44f m)
{
    vOut[0] = m[0] * v[0] + m[4] * v[1] + m[8] *  v[2] + m[12] * v[3];	 
    vOut[1] = m[1] * v[0] + m[5] * v[1] + m[9] *  v[2] + m[13] * v[3];	
    vOut[2] = m[2] * v[0] + m[6] * v[1] + m[10] * v[2] + m[14] * v[3];	
	vOut[3] = m[3] * v[0] + m[7] * v[1] + m[11] * v[2] + m[15] * v[3];
}

void m3dTransformVector4d(M3DVector4d vOut, M3DVector4d v, M3DMatrix44d m)
{
    vOut[0] = m[0] * v[0] + m[4] * v[1] + m[8] *  v[2] + m[12] * v[3];	 
    vOut[1] = m[1] * v[0] + m[5] * v[1] + m[9] *  v[2] + m[13] * v[3];	
    vOut[2] = m[2] * v[0] + m[6] * v[1] + m[10] * v[2] + m[14] * v[3];	
	vOut[3] = m[3] * v[0] + m[7] * v[1] + m[11] * v[2] + m[15] * v[3];
}

/*
 * Just do the rotation, not the translation... this is usually done with a 3x3
 */
void m3dRotateVector3f(M3DVector3f vOut, M3DVector3f p, M3DMatrix33f m)
{
    vOut[0] = m[0] * p[0] + m[3] * p[1] + m[6] * p[2];	
    vOut[1] = m[1] * p[0] + m[4] * p[1] + m[7] * p[2];	
    vOut[2] = m[2] * p[0] + m[5] * p[1] + m[8] * p[2];	
}

void m3dRotateVector3d(M3DVector3d vOut, M3DVector3d p, M3DMatrix33d m)
{
    vOut[0] = m[0] * p[0] + m[3] * p[1] + m[6] * p[2];	
    vOut[1] = m[1] * p[0] + m[4] * p[1] + m[7] * p[2];	
    vOut[2] = m[2] * p[0] + m[5] * p[1] + m[8] * p[2];	
}

/*
 * Scale a matrix
 */
void m3dScaleMatrix33f(M3DMatrix33f m, float scale)
{
	int i;
	for (i = 8; i >=0; i--) m[i] *= scale;
}

void m3dScaleMatrix33d(M3DMatrix33d m, double scale)
{
	int i;
	for (i = 8; i >=0; i--) m[i] *= scale;
}

void m3dScaleMatrix44f(M3DMatrix44f m, float scale)
{
	int i;
	for (i = 15; i >=0; i--) m[i] *= scale;
}

void m3dScaleMatrix44d(M3DMatrix44d m, double scale)
{
	int i;
	for (i = 15; i >=0; i--) m[i] *= scale;
}

#define M33(row,col)  m[col*3+row]

/*
 * Creates a rotation matrix, takes radians NOT degrees
*/
void m3dRotationMatrix33f(M3DMatrix33f m, float angle, float x, float y, float z)
{
	
	float mag, s, c;
	float xx, yy, zz, xy, yz, zx, xs, ys, zs, one_c;

	s = (float)sin(angle);
	c = (float)cos(angle);

	mag = (float)sqrt( x*x + y*y + z*z );

	// Identity matrix
	if (mag == 0.0f) {
		m3dLoadIdentity33f(m);
		return;
	}

	// Rotation matrix is normalized
	x /= mag;
	y /= mag;
	z /= mag;



	xx = x * x;
	yy = y * y;
	zz = z * z;
	xy = x * y;
	yz = y * z;
	zx = z * x;
	xs = x * s;
	ys = y * s;
	zs = z * s;
	one_c = 1.0f - c;

	M33(0,0) = (one_c * xx) + c;
	M33(0,1) = (one_c * xy) - zs;
	M33(0,2) = (one_c * zx) + ys;

	M33(1,0) = (one_c * xy) + zs;
	M33(1,1) = (one_c * yy) + c;
	M33(1,2) = (one_c * yz) - xs;

	M33(2,0) = (one_c * zx) - ys;
	M33(2,1) = (one_c * yz) + xs;
	M33(2,2) = (one_c * zz) + c;
}

#undef M33

void m3dRotationMatrix44f(M3DMatrix44f m, float angle, float x, float y, float z)
{
	float mag, s, c;
	float xx, yy, zz, xy, yz, zx, xs, ys, zs, one_c;

	s = (float)sin(angle);
	c = (float)cos(angle);

	mag = (float)sqrt( x*x + y*y + z*z );

	// Identity matrix
	if (mag == 0.0f) {
		m3dLoadIdentity44f(m);
		return;
	}

	// Rotation matrix is normalized
	x /= mag;
	y /= mag;
	z /= mag;

    #define M(row,col)  m[col*4+row]

	xx = x * x;
	yy = y * y;
	zz = z * z;
	xy = x * y;
	yz = y * z;
	zx = z * x;
	xs = x * s;
	ys = y * s;
	zs = z * s;
	one_c = 1.0f - c;

	M(0,0) = (one_c * xx) + c;
	M(0,1) = (one_c * xy) - zs;
	M(0,2) = (one_c * zx) + ys;
	M(0,3) = 0.0f;

	M(1,0) = (one_c * xy) + zs;
	M(1,1) = (one_c * yy) + c;
	M(1,2) = (one_c * yz) - xs;
	M(1,3) = 0.0f;

	M(2,0) = (one_c * zx) - ys;
	M(2,1) = (one_c * yz) + xs;
	M(2,2) = (one_c * zz) + c;
	M(2,3) = 0.0f;

	M(3,0) = 0.0f;
	M(3,1) = 0.0f;
	M(3,2) = 0.0f;
	M(3,3) = 1.0f;

    #undef M
}

void m3dRotationMatrix33d(M3DMatrix33d m, double angle, double x, double y, double z)
{
	double mag, s, c;
	double xx, yy, zz, xy, yz, zx, xs, ys, zs, one_c;

	s = sin(angle);
	c = cos(angle);

	mag = sqrt( x*x + y*y + z*z );

	// Identity matrix
	if (mag == 0.0) {
		m3dLoadIdentity33d(m);
		return;
	}

	// Rotation matrix is normalized
	x /= mag;
	y /= mag;
	z /= mag;

    #define M(row,col)  m[col*3+row]

	xx = x * x;
	yy = y * y;
	zz = z * z;
	xy = x * y;
	yz = y * z;
	zx = z * x;
	xs = x * s;
	ys = y * s;
	zs = z * s;
	one_c = 1.0 - c;

	M(0,0) = (one_c * xx) + c;
	M(0,1) = (one_c * xy) - zs;
	M(0,2) = (one_c * zx) + ys;

	M(1,0) = (one_c * xy) + zs;
	M(1,1) = (one_c * yy) + c;
	M(1,2) = (one_c * yz) - xs;

	M(2,0) = (one_c * zx) - ys;
	M(2,1) = (one_c * yz) + xs;
	M(2,2) = (one_c * zz) + c;

    #undef M
}

void m3dRotationMatrix44d(M3DMatrix44d m, double angle, double x, double y, double z)
{
	double mag, s, c;
	double xx, yy, zz, xy, yz, zx, xs, ys, zs, one_c;

	s = sin(angle);
	c = cos(angle);

	mag = sqrt( x*x + y*y + z*z );

	// Identity matrix
	if (mag == 0.0) {
		m3dLoadIdentity44d(m);
		return;
	}

	// Rotation matrix is normalized
	x /= mag;
	y /= mag;
	z /= mag;

    #define M(row,col)  m[col*4+row]

	xx = x * x;
	yy = y * y;
	zz = z * z;
	xy = x * y;
	yz = y * z;
	zx = z * x;
	xs = x * s;
	ys = y * s;
	zs = z * s;
	one_c = 1.0f - c;

	M(0,0) = (one_c * xx) + c;
	M(0,1) = (one_c * xy) - zs;
	M(0,2) = (one_c * zx) + ys;
	M(0,3) = 0.0;

	M(1,0) = (one_c * xy) + zs;
	M(1,1) = (one_c * yy) + c;
	M(1,2) = (one_c * yz) - xs;
	M(1,3) = 0.0;

	M(2,0) = (one_c * zx) - ys;
	M(2,1) = (one_c * yz) + xs;
	M(2,2) = (one_c * zz) + c;
	M(2,3) = 0.0;

	M(3,0) = 0.0;
	M(3,1) = 0.0;
	M(3,2) = 0.0;
	M(3,3) = 1.0;

    #undef M
}

/*
 * Create a Translation matrix. Only 4x4 matrices have translation components
 */
void m3dTranslationMatrix44f(M3DMatrix44f m, float x, float y, float z)
{
	m3dLoadIdentity44f(m); m[12] = x; m[13] = y; m[14] = z;
}

void m3dTranslationMatrix44d(M3DMatrix44d m, double x, double y, double z)
{
	m3dLoadIdentity44d(m); m[12] = x; m[13] = y; m[14] = z;
}

/*
 * Translate matrix. Only 4x4 matrices supported
 */
void m3dTranslateMatrix44f(M3DMatrix44f m, float x, float y, float z)
{
	m[12] += x; m[13] += y; m[14] += z;
}

void m3dTranslateMatrix44d(M3DMatrix44d m, double x, double y, double z)
{
	m[12] += x; m[13] += y; m[14] += z;
}

/*
 * Scale matrix. Only 4x4 matrices supported
 */
void m3dScaleMatrix443f(M3DMatrix44f m, float x, float y, float z)
{
	m[0] *= x; m[5] *= y; m[10] *= z; 
}

void m3dScaleMatrix443d(M3DMatrix44d m, double x, double y, double z)
{
	m[0] *= x; m[5] *= y; m[10] *= z;
}

/* Transpose/Invert - Only 4x4 matricies supported */
#define TRANSPOSE44(dst, src)            \
{                                        \
	int i, j;							 \
    for (j = 0; j < 4; j++)				 \
    {                                    \
        for (i = 0; i < 4; i++)			 \
        {                                \
            dst[(j*4)+i] = src[(i*4)+j]; \
        }                                \
    }                                    \
}

/* 
 * Transpose
 */
void m3dTransposeMatrix44f(M3DMatrix44f dst, M3DMatrix44f src)
{
	TRANSPOSE44(dst, src); 
}

void m3dTransposeMatrix44d(M3DMatrix44d dst, M3DMatrix44d src)
{
	TRANSPOSE44(dst, src);
}

/*
 * Compute inverse of 4x4 transformation matrix.
 * Code contributed by Jacques Leroy jle@star.be
 * Return GL_TRUE for success, GL_FALSE for failure (singular matrix)
 */
int m3dInvertMatrix44f(M3DMatrix44f dst, M3DMatrix44f src)
   {
    #define SWAP_ROWS(a, b) { float *_tmp = a; (a)=(b); (b)=_tmp; }
    #define MAT(m,r,c) (m)[(c)*4+(r)]

	float wtmp[4][8];
	float m0, m1, m2, m3, s;
	float *r0, *r1, *r2, *r3;

	r0 = wtmp[0], r1 = wtmp[1], r2 = wtmp[2], r3 = wtmp[3];

	r0[0] = MAT(src,0,0), r0[1] = MAT(src,0,1),
	r0[2] = MAT(src,0,2), r0[3] = MAT(src,0,3),
	r0[4] = 1.0, r0[5] = r0[6] = r0[7] = 0.0,

	r1[0] = MAT(src,1,0), r1[1] = MAT(src,1,1),
	r1[2] = MAT(src,1,2), r1[3] = MAT(src,1,3),
	r1[5] = 1.0, r1[4] = r1[6] = r1[7] = 0.0,

	r2[0] = MAT(src,2,0), r2[1] = MAT(src,2,1),
	r2[2] = MAT(src,2,2), r2[3] = MAT(src,2,3),
	r2[6] = 1.0, r2[4] = r2[5] = r2[7] = 0.0,

	r3[0] = MAT(src,3,0), r3[1] = MAT(src,3,1),
	r3[2] = MAT(src,3,2), r3[3] = MAT(src,3,3),
	r3[7] = 1.0, r3[4] = r3[5] = r3[6] = 0.0;

	/* choose pivot - or die */
	if (fabs(r3[0])>fabs(r2[0])) SWAP_ROWS(r3, r2);
	if (fabs(r2[0])>fabs(r1[0])) SWAP_ROWS(r2, r1);
	if (fabs(r1[0])>fabs(r0[0])) SWAP_ROWS(r1, r0);
	if (0.0 == r0[0])  return 0;

	/* eliminate first variable     */
	m1 = r1[0]/r0[0]; m2 = r2[0]/r0[0]; m3 = r3[0]/r0[0];
	s = r0[1]; r1[1] -= m1 * s; r2[1] -= m2 * s; r3[1] -= m3 * s;
	s = r0[2]; r1[2] -= m1 * s; r2[2] -= m2 * s; r3[2] -= m3 * s;
	s = r0[3]; r1[3] -= m1 * s; r2[3] -= m2 * s; r3[3] -= m3 * s;
	s = r0[4];
	if (s != 0.0) { r1[4] -= m1 * s; r2[4] -= m2 * s; r3[4] -= m3 * s; }
	s = r0[5];
	if (s != 0.0) { r1[5] -= m1 * s; r2[5] -= m2 * s; r3[5] -= m3 * s; }
	s = r0[6];
	if (s != 0.0) { r1[6] -= m1 * s; r2[6] -= m2 * s; r3[6] -= m3 * s; }
	s = r0[7];
	if (s != 0.0) { r1[7] -= m1 * s; r2[7] -= m2 * s; r3[7] -= m3 * s; }

	/* choose pivot - or die */
	if (fabs(r3[1])>fabs(r2[1])) SWAP_ROWS(r3, r2);
	if (fabs(r2[1])>fabs(r1[1])) SWAP_ROWS(r2, r1);
	if (0.0 == r1[1])  return 0;

	/* eliminate second variable */
	m2 = r2[1]/r1[1]; m3 = r3[1]/r1[1];
	r2[2] -= m2 * r1[2]; r3[2] -= m3 * r1[2];
	r2[3] -= m2 * r1[3]; r3[3] -= m3 * r1[3];
	s = r1[4]; if (0.0 != s) { r2[4] -= m2 * s; r3[4] -= m3 * s; }
	s = r1[5]; if (0.0 != s) { r2[5] -= m2 * s; r3[5] -= m3 * s; }
	s = r1[6]; if (0.0 != s) { r2[6] -= m2 * s; r3[6] -= m3 * s; }
	s = r1[7]; if (0.0 != s) { r2[7] -= m2 * s; r3[7] -= m3 * s; }

	/* choose pivot - or die */
	if (fabs(r3[2])>fabs(r2[2])) SWAP_ROWS(r3, r2);
	if (0.0 == r2[2])  return 0;

	/* eliminate third variable */
	m3 = r3[2]/r2[2];
	r3[3] -= m3 * r2[3], r3[4] -= m3 * r2[4],
	r3[5] -= m3 * r2[5], r3[6] -= m3 * r2[6],
	r3[7] -= m3 * r2[7];

	/* last check */
	if (0.0 == r3[3]) return 0;

	s = 1.0f/r3[3];              /* now back substitute row 3 */
	r3[4] *= s; r3[5] *= s; r3[6] *= s; r3[7] *= s;

	m2 = r2[3];                 /* now back substitute row 2 */
	s  = 1.0f/r2[2];
	r2[4] = s * (r2[4] - r3[4] * m2), r2[5] = s * (r2[5] - r3[5] * m2),
	r2[6] = s * (r2[6] - r3[6] * m2), r2[7] = s * (r2[7] - r3[7] * m2);
	m1 = r1[3];
	r1[4] -= r3[4] * m1, r1[5] -= r3[5] * m1,
	r1[6] -= r3[6] * m1, r1[7] -= r3[7] * m1;
	m0 = r0[3];
	r0[4] -= r3[4] * m0, r0[5] -= r3[5] * m0,
	r0[6] -= r3[6] * m0, r0[7] -= r3[7] * m0;

	m1 = r1[2];                 /* now back substitute row 1 */
	s  = 1.0f/r1[1];
	r1[4] = s * (r1[4] - r2[4] * m1), r1[5] = s * (r1[5] - r2[5] * m1),
	r1[6] = s * (r1[6] - r2[6] * m1), r1[7] = s * (r1[7] - r2[7] * m1);
	m0 = r0[2];
	r0[4] -= r2[4] * m0, r0[5] -= r2[5] * m0,
	r0[6] -= r2[6] * m0, r0[7] -= r2[7] * m0;

	m0 = r0[1];                 /* now back substitute row 0 */
	s  = 1.0f/r0[0];
	r0[4] = s * (r0[4] - r1[4] * m0), r0[5] = s * (r0[5] - r1[5] * m0),
	r0[6] = s * (r0[6] - r1[6] * m0), r0[7] = s * (r0[7] - r1[7] * m0);

	MAT(dst,0,0) = r0[4]; MAT(dst,0,1) = r0[5],
	MAT(dst,0,2) = r0[6]; MAT(dst,0,3) = r0[7],
	MAT(dst,1,0) = r1[4]; MAT(dst,1,1) = r1[5],
	MAT(dst,1,2) = r1[6]; MAT(dst,1,3) = r1[7],
	MAT(dst,2,0) = r2[4]; MAT(dst,2,1) = r2[5],
	MAT(dst,2,2) = r2[6]; MAT(dst,2,3) = r2[7],
	MAT(dst,3,0) = r3[4]; MAT(dst,3,1) = r3[5],
	MAT(dst,3,2) = r3[6]; MAT(dst,3,3) = r3[7]; 

	return 1;

	#undef MAT
	#undef SWAP_ROWS
}

int m3dInvertMatrix44d(M3DMatrix44d dst, M3DMatrix44d src)
{
    #define SWAP_ROWS(a, b) { double *_tmp = a; (a)=(b); (b)=_tmp; }
    #define MAT(m,r,c) (m)[(c)*4+(r)]

	double wtmp[4][8];
	double m0, m1, m2, m3, s;
	double *r0, *r1, *r2, *r3;

	r0 = wtmp[0], r1 = wtmp[1], r2 = wtmp[2], r3 = wtmp[3];

	r0[0] = MAT(src,0,0), r0[1] = MAT(src,0,1),
	r0[2] = MAT(src,0,2), r0[3] = MAT(src,0,3),
	r0[4] = 1.0, r0[5] = r0[6] = r0[7] = 0.0,

	r1[0] = MAT(src,1,0), r1[1] = MAT(src,1,1),
	r1[2] = MAT(src,1,2), r1[3] = MAT(src,1,3),
	r1[5] = 1.0, r1[4] = r1[6] = r1[7] = 0.0,

	r2[0] = MAT(src,2,0), r2[1] = MAT(src,2,1),
	r2[2] = MAT(src,2,2), r2[3] = MAT(src,2,3),
	r2[6] = 1.0, r2[4] = r2[5] = r2[7] = 0.0,

	r3[0] = MAT(src,3,0), r3[1] = MAT(src,3,1),
	r3[2] = MAT(src,3,2), r3[3] = MAT(src,3,3),
	r3[7] = 1.0, r3[4] = r3[5] = r3[6] = 0.0;

	// choose pivot - or die 
	if (fabs(r3[0])>fabs(r2[0])) SWAP_ROWS(r3, r2);
	if (fabs(r2[0])>fabs(r1[0])) SWAP_ROWS(r2, r1);
	if (fabs(r1[0])>fabs(r0[0])) SWAP_ROWS(r1, r0);
	if (0.0 == r0[0])  return 0;

	// eliminate first variable     
	m1 = r1[0]/r0[0]; m2 = r2[0]/r0[0]; m3 = r3[0]/r0[0];
	s = r0[1]; r1[1] -= m1 * s; r2[1] -= m2 * s; r3[1] -= m3 * s;
	s = r0[2]; r1[2] -= m1 * s; r2[2] -= m2 * s; r3[2] -= m3 * s;
	s = r0[3]; r1[3] -= m1 * s; r2[3] -= m2 * s; r3[3] -= m3 * s;
	s = r0[4];
	if (s != 0.0) { r1[4] -= m1 * s; r2[4] -= m2 * s; r3[4] -= m3 * s; }
	s = r0[5];
	if (s != 0.0) { r1[5] -= m1 * s; r2[5] -= m2 * s; r3[5] -= m3 * s; }
	s = r0[6];
	if (s != 0.0) { r1[6] -= m1 * s; r2[6] -= m2 * s; r3[6] -= m3 * s; }
	s = r0[7];
	if (s != 0.0) { r1[7] -= m1 * s; r2[7] -= m2 * s; r3[7] -= m3 * s; }

	// choose pivot - or die 
	if (fabs(r3[1])>fabs(r2[1])) SWAP_ROWS(r3, r2);
	if (fabs(r2[1])>fabs(r1[1])) SWAP_ROWS(r2, r1);
	if (0.0 == r1[1])  return 0;

	// eliminate second variable 
	m2 = r2[1]/r1[1]; m3 = r3[1]/r1[1];
	r2[2] -= m2 * r1[2]; r3[2] -= m3 * r1[2];
	r2[3] -= m2 * r1[3]; r3[3] -= m3 * r1[3];
	s = r1[4]; if (0.0 != s) { r2[4] -= m2 * s; r3[4] -= m3 * s; }
	s = r1[5]; if (0.0 != s) { r2[5] -= m2 * s; r3[5] -= m3 * s; }
	s = r1[6]; if (0.0 != s) { r2[6] -= m2 * s; r3[6] -= m3 * s; }
	s = r1[7]; if (0.0 != s) { r2[7] -= m2 * s; r3[7] -= m3 * s; }

	// choose pivot - or die 
	if (fabs(r3[2])>fabs(r2[2])) SWAP_ROWS(r3, r2);
	if (0.0 == r2[2])  return 0;

	// eliminate third variable 
	m3 = r3[2]/r2[2];
	r3[3] -= m3 * r2[3], r3[4] -= m3 * r2[4],
	r3[5] -= m3 * r2[5], r3[6] -= m3 * r2[6],
	r3[7] -= m3 * r2[7];

	// last check 
	if (0.0 == r3[3]) return 0;

	s = 1.0f/r3[3];              // now back substitute row 3 
	r3[4] *= s; r3[5] *= s; r3[6] *= s; r3[7] *= s;

	m2 = r2[3];                 // now back substitute row 2 
	s  = 1.0f/r2[2];
	r2[4] = s * (r2[4] - r3[4] * m2), r2[5] = s * (r2[5] - r3[5] * m2),
	r2[6] = s * (r2[6] - r3[6] * m2), r2[7] = s * (r2[7] - r3[7] * m2);
	m1 = r1[3];
	r1[4] -= r3[4] * m1, r1[5] -= r3[5] * m1,
	r1[6] -= r3[6] * m1, r1[7] -= r3[7] * m1;
	m0 = r0[3];
	r0[4] -= r3[4] * m0, r0[5] -= r3[5] * m0,
	r0[6] -= r3[6] * m0, r0[7] -= r3[7] * m0;

	m1 = r1[2];                 // now back substitute row 1 
	s  = 1.0f/r1[1];
	r1[4] = s * (r1[4] - r2[4] * m1), r1[5] = s * (r1[5] - r2[5] * m1),
	r1[6] = s * (r1[6] - r2[6] * m1), r1[7] = s * (r1[7] - r2[7] * m1);
	m0 = r0[2];
	r0[4] -= r2[4] * m0, r0[5] -= r2[5] * m0,
	r0[6] -= r2[6] * m0, r0[7] -= r2[7] * m0;

	m0 = r0[1];                 // now back substitute row 0 
	s  = 1.0f/r0[0];
	r0[4] = s * (r0[4] - r1[4] * m0), r0[5] = s * (r0[5] - r1[5] * m0),
	r0[6] = s * (r0[6] - r1[6] * m0), r0[7] = s * (r0[7] - r1[7] * m0);

	MAT(dst,0,0) = r0[4]; MAT(dst,0,1) = r0[5],
	MAT(dst,0,2) = r0[6]; MAT(dst,0,3) = r0[7],
	MAT(dst,1,0) = r1[4]; MAT(dst,1,1) = r1[5],
	MAT(dst,1,2) = r1[6]; MAT(dst,1,3) = r1[7],
	MAT(dst,2,0) = r2[4]; MAT(dst,2,1) = r2[5],
	MAT(dst,2,2) = r2[6]; MAT(dst,2,3) = r2[7],
	MAT(dst,3,0) = r3[4]; MAT(dst,3,1) = r3[5],
	MAT(dst,3,2) = r3[6]; MAT(dst,3,3) = r3[7]; 

	return 1;

	#undef MAT
	#undef SWAP_ROWS

	return 1;
}

/*
 * Find a normal from three points
 */
void m3dFindNormal3f(M3DVector3f result, M3DVector3f point1, M3DVector3f point2, M3DVector3f point3)
{
	M3DVector3f v1,v2;		// Temporary vectors

	// Calculate two vectors from the three points. Assumes counter clockwise
	// winding!
	v1[0] = point1[0] - point2[0];
	v1[1] = point1[1] - point2[1];
	v1[2] = point1[2] - point2[2];

	v2[0] = point2[0] - point3[0];
	v2[1] = point2[1] - point3[1];
	v2[2] = point2[2] - point3[2];

	// Take the cross product of the two vectors to get
	// the normal vector.
	m3dCrossProduct3f(result, v1, v2);	
}

void m3dFindNormal3d(M3DVector3d result, M3DVector3d point1, M3DVector3d point2, M3DVector3d point3)
{
	M3DVector3d v1,v2;		// Temporary vectors

	// Calculate two vectors from the three points. Assumes counter clockwise
	// winding!
	v1[0] = point1[0] - point2[0];
	v1[1] = point1[1] - point2[1];
	v1[2] = point1[2] - point2[2];

	v2[0] = point2[0] - point3[0];
	v2[1] = point2[1] - point3[1];
	v2[2] = point2[2] - point3[2];

	// Take the cross product of the two vectors to get
	// the normal vector.
	m3dCrossProduct3d(result, v1, v2);
}

/*
 * Calculates the signed distance of a point to a plane
 */
float m3dGetDistanceToPlane3f(M3DVector3f point, M3DVector4f plane)
{
	return point[0]*plane[0] + point[1]*plane[1] + point[2]*plane[2] + plane[3];
}

double m3dGetDistanceToPlane3d(M3DVector3d point, M3DVector4d plane)
{
	return point[0]*plane[0] + point[1]*plane[1] + point[2]*plane[2] + plane[3]; 
}

/*
 * Calculate the plane equation of the plane that the three specified points lay in. The
 * points are given in clockwise winding order, with normal pointing out of clockwise face
 * planeEq contains the A,B,C, and D of the plane equation coefficients
 */
void m3dGetPlaneEquation4f(M3DVector4f planeEq, M3DVector3f p1, M3DVector3f p2, M3DVector3f p3)
{
    // Get two vectors... do the cross product
    M3DVector3f v1, v2;

    // V1 = p3 - p1
    v1[0] = p3[0] - p1[0];
    v1[1] = p3[1] - p1[1];
    v1[2] = p3[2] - p1[2];

    // V2 = P2 - p1
    v2[0] = p2[0] - p1[0];
    v2[1] = p2[1] - p1[1];
    v2[2] = p2[2] - p1[2];

    // Unit normal to plane - Not sure which is the best way here
    m3dCrossProduct3f(planeEq, v1, v2);
    m3dNormalizeVector3f(planeEq);
    // Back substitute to get D
    planeEq[3] = -(planeEq[0] * p3[0] + planeEq[1] * p3[1] + planeEq[2] * p3[2]);
}

void m3dGetPlaneEquation4d(M3DVector4d planeEq, M3DVector3d p1, M3DVector3d p2, M3DVector3d p3)
{
    // Get two vectors... do the cross product
    M3DVector3d v1, v2;

    // V1 = p3 - p1
    v1[0] = p3[0] - p1[0];
    v1[1] = p3[1] - p1[1];
    v1[2] = p3[2] - p1[2];

    // V2 = P2 - p1
    v2[0] = p2[0] - p1[0];
    v2[1] = p2[1] - p1[1];
    v2[2] = p2[2] - p1[2];

    // Unit normal to plane - Not sure which is the best way here
    m3dCrossProduct3d(planeEq, v1, v2);
    m3dNormalizeVector3d(planeEq);
    // Back substitute to get D
    planeEq[3] = -(planeEq[0] * p3[0] + planeEq[1] * p3[1] + planeEq[2] * p3[2]);
}

/*
 * Determine if the ray (starting at point) intersects the sphere centered at
 * sphereCenter with radius sphereRadius
 * Return value is < 0 if the ray does not intersect
 * Return value is 0.0 if ray is tangent
 * Positive value is distance to the intersection point
 * Algorithm from "3D Math Primer for Graphics and Game Development"
 */
float m3dRaySphereTest3f(M3DVector3f point, M3DVector3f ray, M3DVector3f sphereCenter, float sphereRadius)
{
	//m3dNormalizeVector(ray);	// Make sure ray is unit length

	M3DVector3f rayToCenter;	// Ray to center of sphere
	rayToCenter[0] =  sphereCenter[0] - point[0];	
	rayToCenter[1] =  sphereCenter[1] - point[1];
	rayToCenter[2] =  sphereCenter[2] - point[2];
	
	// Project rayToCenter on ray to test
	double a = m3dDotProduct3f(rayToCenter, ray);
	
	// Distance to center of sphere
	double distance2 = m3dDotProduct3f(rayToCenter, rayToCenter);	// Or length

	
	double dRet = (sphereRadius * sphereRadius) - distance2 + (a*a);
	
	if(dRet > 0.0)			// Return distance to intersection
		dRet = a - sqrt(dRet);
	
	return dRet;
}

double m3dRaySphereTest3d(M3DVector3d point, M3DVector3d ray, M3DVector3d sphereCenter, double sphereRadius)
{
	//m3dNormalizeVectorf(ray);	// Make sure ray is unit length

	M3DVector3d rayToCenter;	// Ray to center of sphere
	rayToCenter[0] =  sphereCenter[0] - point[0];	
	rayToCenter[1] =  sphereCenter[1] - point[1];
	rayToCenter[2] =  sphereCenter[2] - point[2];
	
	// Project rayToCenter on ray to test
	float a = m3dDotProduct3d(rayToCenter, ray);
	
	// Distance to center of sphere
	float distance2 = m3dDotProduct3d(rayToCenter, rayToCenter);	// Or length
	
	float dRet = (sphereRadius * sphereRadius) - distance2 + (a*a);
	
	if(dRet > 0.0)			// Return distance to intersection
		dRet = a - sqrtf(dRet);
	
	return dRet;
}

/*
 * Compare floats and doubles... 
 */
int m3dCloseEnoughf(float fCandidate, float fCompare, float fEpsilon)
{
	return (fabs(fCandidate - fCompare) < fEpsilon);
}

int m3dCloseEnoughd(double dCandidate, double dCompare, double dEpsilon)
{
	return (fabs(dCandidate - dCompare) < dEpsilon);
}

/*
 * Smoothly step between 0 and 1 between edge1 and edge 2
 */
float m3dSmoothStepf(float edge1, float edge2, float x)
{
    double t;
    t = (x - edge1) / (edge2 - edge1);
    if(t > 1.0)
        t = 1.0;
        
    if(t < 0.0)
        t = 0.0f;
        
    return t * t * ( 3.0 - 2.0 * t);
}

double m3dSmoothStepd(double edge1, double edge2, double x)
{
    float t;
    t = (x - edge1) / (edge2 - edge1);
    if(t > 1.0f)
        t = 1.0f;
        
    if(t < 0.0)
        t = 0.0f;
        
    return t * t * ( 3.0f - 2.0f * t);
}

/*
 * Creates a projection to "squish" an object into the plane.
 * Use m3dGetPlaneEquationd(planeEq, point1, point2, point3);
 * to get a plane equation.
 */
void m3dMakePlanarShadowMatrix4f(M3DMatrix44f proj, M3DVector4f planeEq, M3DVector3f vLightPos)
{
	// These just make the code below easier to read. They will be 
	// removed by the optimizer.	
	float a = planeEq[0];
	float b = planeEq[1];
	float c = planeEq[2];
	float d = planeEq[3];

	float dx = -vLightPos[0];
	float dy = -vLightPos[1];
	float dz = -vLightPos[2];

	// Now build the projection matrix
	proj[0] = b * dy + c * dz;
	proj[1] = -a * dy;
	proj[2] = -a * dz;
	proj[3] = 0.0;

	proj[4] = -b * dx;
	proj[5] = a * dx + c * dz;
	proj[6] = -b * dz;
	proj[7] = 0.0;

	proj[8] = -c * dx;
	proj[9] = -c * dy;
	proj[10] = a * dx + b * dy;
	proj[11] = 0.0;

	proj[12] = -d * dx;
	proj[13] = -d * dy;
	proj[14] = -d * dz;
	proj[15] = a * dx + b * dy + c * dz;
	// Shadow matrix ready
}

void m3dMakePlanarShadowMatrix4d(M3DMatrix44d proj, M3DVector4d planeEq, M3DVector3d vLightPos)
{
	// These just make the code below easier to read. They will be 
	// removed by the optimizer.	
	double a = planeEq[0];
	double b = planeEq[1];
	double c = planeEq[2];
	double d = planeEq[3];

	double dx = -vLightPos[0];
	double dy = -vLightPos[1];
	double dz = -vLightPos[2];

	// Now build the projection matrix
	proj[0] = b * dy + c * dz;
	proj[1] = -a * dy;
	proj[2] = -a * dz;
	proj[3] = 0.0;

	proj[4] = -b * dx;
	proj[5] = a * dx + c * dz;
	proj[6] = -b * dz;
	proj[7] = 0.0;

	proj[8] = -c * dx;
	proj[9] = -c * dy;
	proj[10] = a * dx + b * dy;
	proj[11] = 0.0;

	proj[12] = -d * dx;
	proj[13] = -d * dy;
	proj[14] = -d * dz;
	proj[15] = a * dx + b * dy + c * dz;
	// Shadow matrix ready
}

/*
 * I want to know the point on a ray, closest to another given point in space.
 * As a bonus, return the distance squared of the two points.
 * In: vRayOrigin is the origin of the ray.
 * In: vUnitRayDir is the unit vector of the ray
 * In: vPointInSpace is the point in space
 * Out: vPointOnRay is the poing on the ray closest to vPointInSpace
 * Return: The square of the distance to the ray
 */
float m3dClosestPointOnRay3f(M3DVector3f vPointOnRay, M3DVector3f vRayOrigin, M3DVector3f vUnitRayDir, M3DVector3f vPointInSpace)
{
	M3DVector3f v;
	m3dSubtractVectors3f(v, vPointInSpace, vRayOrigin);
	
	double t = m3dDotProduct3f(vUnitRayDir, v);
	
	// This is the point on the ray
	vPointOnRay[0] = vRayOrigin[0] + (t * vUnitRayDir[0]);
	vPointOnRay[1] = vRayOrigin[1] + (t * vUnitRayDir[1]);
	vPointOnRay[2] = vRayOrigin[2] + (t * vUnitRayDir[2]);
	
	return m3dGetDistanceSquared3f(vPointOnRay, vPointInSpace);
}

double m3dClosestPointOnRay3d(M3DVector3d vPointOnRay, M3DVector3d vRayOrigin, M3DVector3d vUnitRayDir, M3DVector3d vPointInSpace)
{
	M3DVector3d v;
	m3dSubtractVectors3d(v, vPointInSpace, vRayOrigin);
	
	float t = m3dDotProduct3d(vUnitRayDir, v);
	
	// This is the point on the ray
	vPointOnRay[0] = vRayOrigin[0] + (t * vUnitRayDir[0]);
	vPointOnRay[1] = vRayOrigin[1] + (t * vUnitRayDir[1]);
	vPointOnRay[2] = vRayOrigin[2] + (t * vUnitRayDir[2]);
	
	return m3dGetDistanceSquared3d(vPointOnRay, vPointInSpace);
}

/*
 * Determinant of a 3x3 matrix.
 */
float m3dDeterminant33f(M3DMatrix33f src)
{
	float det = 0.0;

	det  = src[0]*(src[4]*src[8] - src[5]*src[7]);
	det -= src[1]*(src[3]*src[8] - src[5]*src[6]);
	det += src[2]*(src[3]*src[7] - src[4]*src[6]);

	return det;
}

/*
 * 3x3 matrix - column major. X vector is 0, 1, 2, etc.
 *		0	3	6	
 *		1	4	7
 *		2	5	8
 */

