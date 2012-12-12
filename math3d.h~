/** 
 * Header file for the Math3d library. The C-Runtime has math.h, this file and 
 * the accompanying math.c are meant to suppliment math.h by adding geometry
 * and math routines useful for graphics, simulation, and physics applications 
 * (3D stuff).
 * Note: This code is based on the implementation provided by Richard S. Wright 
 * Jr.
 */
#ifndef _MATH3D_H_
#define _MATH3D_H_

#include <math.h>
#include <memory.h>

/*
 * Data structures and containers
 * Much thought went into how these are declared. Many libraries declare these
 * as structures with x, y, z data members. However structure alignment issues
 * could limit the portability of code based on such structures, or the binary
 * compatibility of data files (more likely) that contain such structures across
 * compilers/platforms. Arrays are always tightly packed, and are more efficient 
 * for moving blocks of data around (usually).
 */
typedef float	M3DVector3f[3];		/* Vector of three floats (x, y, z)  */
typedef double	M3DVector3d[3];		/* Vector of three doubles (x, y, z) */

typedef float M3DVector4f[4];		/* Vector of four floats (x, y, z, w)  */
typedef double M3DVector4d[4];		/* Vector of four doubles (x, y, z, w)  */

typedef float M3DVector2f[2];	 	/* Vector of two floats (x, y)  */
typedef double M3DVector2d[2];		/* Vector of two doubles (x, y)  */

/*
 * 3x3 matrix - column major. X vector is 0, 1, 2, etc.
 *		0	3	6	
 *		1	4	7
 *		2	5	8
 */
typedef float M3DMatrix33f[9];		/* A 3 x 3 matrix, column major (floats) - OpenGL Style */
typedef double M3DMatrix33d[9];		/* A 3 x 3 matrix, column major (doubles) - OpenGL Style */

/* 
 * 4x4 matrix - column major. X vector is 0, 1, 2, etc.
 *	0	4	8	12
 *	1	5	9	13
 *	2	6	10	14
 *	3	7	11	15
 */
typedef float M3DMatrix44f[16];		/* A 4 X 4 matrix, column major (floats) - OpenGL style */
typedef double M3DMatrix44d[16];	/* A 4 x 4 matrix, column major (doubles) - OpenGL style */

/*
 * Useful constants
 */
#define M3D_PI (3.14159265358979323846)
#define M3D_2PI (2.0 * M3D_PI)
#define M3D_PI_DIV_180 (0.017453292519943296)
#define M3D_INV_PI_DIV_180 (57.2957795130823229)

/*
 * Useful shortcuts and macros
 */
#define m3dDegToRad(x)	((x)*M3D_PI_DIV_180)
#define m3dRadToDeg(x)	((x)*M3D_INV_PI_DIV_180)

#define m3dHrToDeg(x)	((x) * (1.0 / 15.0))
#define m3dHrToRad(x)	m3dDegToRad(m3dHrToDeg(x))

#define m3dDegToHr(x)	((x) * 15.0))
#define m3dRadToHr(x)	m3dDegToHr(m3dRadToDeg(x))

#define	m3dGetVectorX(v) (v[0])
#define m3dGetVectorY(v) (v[1])
#define m3dGetVectorZ(v) (v[2])
#define m3dGetVectorW(v) (v[3])

#define m3dSetVectorX(v, x)	((v)[0] = (x))
#define m3dSetVectorY(v, y)	((v)[1] = (y))
#define m3dSetVectorZ(v, z)	((v)[2] = (z))
#define m3dSetVectorW(v, w)	((v)[3] = (w))

/*
 * Prototypes
 */
unsigned int m3dIsPOW2(unsigned int iValue);

void m3dNullVector2f(M3DVector2f v);
void m3dNullVector3f(M3DVector3f v);
void m3dNullVector4f(M3DVector4f v);
void m3dNullVector2d(M3DVector2d v);
void m3dNullVector3d(M3DVector3d v);
void m3dNullVector4d(M3DVector4d v);

void m3dLoadVector2f(M3DVector2f v, float x, float y);
void m3dLoadVector2d(M3DVector2d v, float x, float y);
void m3dLoadVector3f(M3DVector3f v, float x, float y, float z);
void m3dLoadVector3d(M3DVector3d v, double x, double y, double z);
void m3dLoadVector4f(M3DVector4f v, float x, float y, float z, float w);
void m3dLoadVector4d(M3DVector4d v, double x, double y, double z, double w);

void m3dCopyVector2f(M3DVector2f dst, M3DVector2f src);
void m3dCopyVector2d(M3DVector2d dst, M3DVector2d src);
void m3dCopyVector3f(M3DVector3f dst, M3DVector3f src);
void m3dCopyVector3d(M3DVector3d dst, M3DVector3d src);
void m3dCopyVector4f(M3DVector4f dst, M3DVector4f src);
void m3dCopyVector4d(M3DVector4d dst, M3DVector4d src);

void m3dAddVectors2f(M3DVector2f r, M3DVector2f a, M3DVector2f b);
void m3dAddVectors2d(M3DVector2d r, M3DVector2d a, M3DVector2d b);
void m3dAddVectors3f(M3DVector3f r, M3DVector3f a, M3DVector3f b);
void m3dAddVectors3d(M3DVector3d r, M3DVector3d a, M3DVector3d b);
void m3dAddVectors4f(M3DVector4f r, M3DVector4f a, M3DVector4f b);
void m3dAddVectors4d(M3DVector4d r, M3DVector4d a, M3DVector4d b);

void m3dSubtractVectors2f(M3DVector2f r, M3DVector2f a, M3DVector2f b);
void m3dSubtractVectors2d(M3DVector2d r, M3DVector2d a, M3DVector2d b);
void m3dSubtractVectors3f(M3DVector3f r, M3DVector3f a, M3DVector3f b);
void m3dSubtractVectors3d(M3DVector3d r, M3DVector3d a, M3DVector3d b);
void m3dSubtractVectors4d(M3DVector4f r, M3DVector4f a, M3DVector4f b);
void m3dSubtractVectors4f(M3DVector4d r, M3DVector4d a, M3DVector4d b);

void m3dScaleVector2f(M3DVector2f v, float scale);
void m3dScaleVector2d(M3DVector2d v, double scale);
void m3dScaleVector3f(M3DVector3f v, float scale);
void m3dScaleVector3d(M3DVector3d v, double scale);
void m3dScaleVector4f(M3DVector4f v, float scale);
void m3dScaleVector4d(M3DVector4d v, double scale);

void m3dCrossProduct3f(M3DVector3f result, M3DVector3f u, M3DVector3f v);
void m3dCrossProduct3d(M3DVector3d result, M3DVector3d u, M3DVector3d v);

float m3dDotProduct3f(M3DVector3f u, M3DVector3f v);
double m3dDotProduct3d(M3DVector3d u, M3DVector3d v);

float m3dGetAngleBetweenVectors3f(M3DVector3f u, M3DVector3f v);
double m3dGetAngleBetweenVectors3d(M3DVector3d u, M3DVector3d v);

float m3dGetVectorLengthSquared3f(M3DVector3f u);
double m3dGetVectorLengthSquared3d(M3DVector3d u);

float m3dGetVectorLength3f(M3DVector3f u);
double m3dGetVectorLength3d(M3DVector3d u);

void m3dNormalizeVector3f(M3DVector3f u);
void m3dNormalizeVector3d(M3DVector3d u);

float m3dGetDistanceSquared3f(M3DVector3f u, M3DVector3f v);
double m3dGetDistanceSquared3d(M3DVector3d u, M3DVector3d v);

float m3dGetDistance3f(M3DVector3f u, M3DVector3f v);
double m3dGetDistance3d(M3DVector3d u, M3DVector3d v);

float m3dGetMagnitudeSquared3f(M3DVector3f u);
double m3dGetMagnitudeSquared3d(M3DVector3d u);

float m3dGetMagnitude3f(M3DVector3f u);
double m3dGetMagnitude3d(M3DVector3d u);

void m3dCopyMatrix33f(M3DMatrix33f dst, M3DMatrix33f src);
void m3dCopyMatrix33d(M3DMatrix33d dst, M3DMatrix33d src);
void m3dCopyMatrix44f(M3DMatrix44f dst, M3DMatrix44f src);
void m3dCopyMatrix44d(M3DMatrix44d dst, M3DMatrix44d src);

void m3dLoadIdentity33f(M3DMatrix33f m);
void m3dLoadIdentity33d(M3DMatrix33d m);
void m3dLoadIdentity44f(M3DMatrix44f m);
void m3dLoadIdentity44d(M3DMatrix44d m);

void m3dGetMatrixColumn33f(M3DVector3f dst, M3DMatrix33f src, int column);
void m3dGetMatrixColumn33d(M3DVector3d dst, M3DMatrix33d src, int column);
void m3dSetMatrixColumn33f(M3DMatrix33f dst, M3DVector3f src, int column);
void m3dSetMatrixColumn33d(M3DMatrix33d dst, M3DVector3d src, int column);
void m3dGetMatrixColumn44f(M3DVector4f dst, M3DMatrix44f src, int column);
void m3dGetMatrixColumn44d(M3DVector4d dst, M3DMatrix44d src, int column);
void m3dSetMatrixColumn44f(M3DMatrix44f dst, M3DVector4f src, int column);
void m3dSetMatrixColumn44d(M3DMatrix44d dst, M3DVector4d src, int column);

void m3dSetMatrixRowCol33f(M3DMatrix33f m, int row, int col, float value);
float m3dGetMatrixRowCol33f(M3DMatrix33f m, int row, int col);
void m3dSetMatrixRowCol33d(M3DMatrix33d m, int row, int col, double value);
double m3dGetMatrixRowCol33d(M3DMatrix33d m, int row, int col);
void m3dSetMatrixRowCol44f(M3DMatrix44f m, int row, int col, float value);
float m3dGetMatrixRowCol44f(M3DMatrix44f m, int row, int col);
void m3dSetMatrixRowCol44d(M3DMatrix44d m, int row, int col, double value);
double m3dGetMatrixRowCol44d(M3DMatrix44d m, int row, int col);

void m3dExtractRotation33f(M3DMatrix33f dst, M3DMatrix44f src);
void m3dExtractRotation33d(M3DMatrix33d dst, M3DMatrix44d src);

void m3dInjectRotation44f(M3DMatrix44f dst, M3DMatrix33f src);
void m3dInjectRotation44d(M3DMatrix44d dst, M3DMatrix33d src);

void m3dMatrixMultiply44f(M3DMatrix44f product, M3DMatrix44f a, M3DMatrix44f b);
void m3dMatrixMultiply44d(M3DMatrix44d product, M3DMatrix44d a, M3DMatrix44d b);
void m3dMatrixMultiply33f(M3DMatrix33f product, M3DMatrix33f a, M3DMatrix33f b);
void m3dMatrixMultiply33d(M3DMatrix33d product, M3DMatrix33d a, M3DMatrix33d b);

void m3dTransformVector3f(M3DVector3f vOut, M3DVector3f v, M3DMatrix44f m);
void m3dTransformVector3d(M3DVector3d vOut, M3DVector3d v, M3DMatrix44d m);
void m3dTransformVector4f(M3DVector4f vOut, M3DVector4f v, M3DMatrix44f m);
void m3dTransformVector4d(M3DVector4d vOut, M3DVector4d v, M3DMatrix44d m);

void m3dRotateVector3f(M3DVector3f vOut, M3DVector3f p, M3DMatrix33f m);
void m3dRotateVector3d(M3DVector3d vOut, M3DVector3d p, M3DMatrix33d m);

void m3dScaleMatrix33f(M3DMatrix33f m, float scale);
void m3dScaleMatrix33d(M3DMatrix33d m, double scale);
void m3dScaleMatrix44f(M3DMatrix44f m, float scale);
void m3dScaleMatrix44d(M3DMatrix44d m, double scale);

void m3dRotationMatrix33f(M3DMatrix33f m, float angle, float x, float y, float z);
void m3dRotationMatrix33d(M3DMatrix33d m, double angle, double x, double y, double z);
void m3dRotationMatrix44f(M3DMatrix44f m, float angle, float x, float y, float z);
void m3dRotationMatrix44d(M3DMatrix44d m, double angle, double x, double y, double z);

void m3dTranslationMatrix44f(M3DMatrix44f m, float x, float y, float z);
void m3dTranslationMatrix44d(M3DMatrix44d m, double x, double y, double z);

void m3dTranslateMatrix44f(M3DMatrix44f m, float x, float y, float z);
void m3dTranslateMatrix44d(M3DMatrix44d m, double x, double y, double z);

void m3dScaleMatrix443f(M3DMatrix44f m, float x, float y, float z);
void m3dScaleMatrix443d(M3DMatrix44d m, double x, double y, double z);

void m3dTransposeMatrix44f(M3DMatrix44f dst, M3DMatrix44f src);
void m3dTransposeMatrix44d(M3DMatrix44d dst, M3DMatrix44d src);
int m3dInvertMatrix44f(M3DMatrix44f dst, M3DMatrix44f src);
int m3dInvertMatrix44d(M3DMatrix44d dst, M3DMatrix44d src);

int m3dInvertMatrix44d(M3DMatrix44d dst, M3DMatrix44d src);
void m3dFindNormal3f(M3DVector3f result, M3DVector3f point1, M3DVector3f point2, M3DVector3f point3);
void m3dFindNormal3d(M3DVector3d result, M3DVector3d point1, M3DVector3d point2, M3DVector3d point3);

float m3dGetDistanceToPlane3f(M3DVector3f point, M3DVector4f plane);
double m3dGetDistanceToPlane3d(M3DVector3d point, M3DVector4d plane);

void m3dGetPlaneEquation4f(M3DVector4f planeEq, M3DVector3f p1, M3DVector3f p2, M3DVector3f p3);
void m3dGetPlaneEquation4d(M3DVector4d planeEq, M3DVector3d p1, M3DVector3d p2, M3DVector3d p3);

float m3dRaySphereTest3f(M3DVector3f point, M3DVector3f ray, M3DVector3f sphereCenter, float sphereRadius);
double m3dRaySphereTest3d(M3DVector3d point, M3DVector3d ray, M3DVector3d sphereCenter, double sphereRadius);

int m3dCloseEnoughf(float fCandidate, float fCompare, float fEpsilon);
int m3dCloseEnoughd(double dCandidate, double dCompare, double dEpsilon);

float m3dSmoothStepf(float edge1, float edge2, float x);
double m3dSmoothStepd(double edge1, double edge2, double x);

void m3dMakePlanarShadowMatrix4f(M3DMatrix44f proj, M3DVector4f planeEq, M3DVector3f vLightPos);
void m3dMakePlanarShadowMatrix4d(M3DMatrix44d proj, M3DVector4d planeEq, M3DVector3d vLightPos);

float m3dClosestPointOnRay3f(M3DVector3f vPointOnRay, M3DVector3f vRayOrigin, M3DVector3f vUnitRayDir, M3DVector3f vPointInSpace);
double m3dClosestPointOnRay3d(M3DVector3d vPointOnRay, M3DVector3d vRayOrigin, M3DVector3d vUnitRayDir, M3DVector3d vPointInSpace);

float m3dDeterminant33f(M3DMatrix33f src);

#endif
