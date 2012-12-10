/**
 * alg.h - This module contains the definition/implementation of functions
 * to support the use of vectors and matrices (linear algebra).
 * <p>
 * In the context of this module all the elements, in both vectors and matrices, 
 * are declared as 'double' data type.
 * <p>
 * Functions that start with 'algVec' are considered as vector-related functions;
 * functions that start with 'algMat' are considered as matrix-related functions.
 */
#ifndef _ALG_H_
#define _ALG_H_

/**
 * Prototypes
 */
double* algVecCreate(int n);
double** algMatCreate(int m, int n);

void algVecDestroy(double *v);
void algMatDestroy(int m, double **A);

double algVecLength(int n, double *v); 
double* algVecCopy(int n, double *v); 
void algVecUnit(int n, double *v); 
void algVecAdd(int n, double *v, double *w, double *x);
void algVecMultiply(int m, int n, double **A, double *v, double *w);
void algVecMultiplyScalar(int n, double *v, double c);
void algVecZero(int n, double *v);

double** algMatCopy(int n, double **A);
void algMatIdentity(int n, double **A);
void algMatAdd(int m, int n, double **A, double **B, double **C);
void algMatMultiply(int m, int l, int n, double **A, double **B, double **C);
void algMatMultiplyScalar(int m, int n, double **A, double c);
void algMatZero(int m, int n, double **A);

/* End of file -------------------------------------------------------------- */

#endif

