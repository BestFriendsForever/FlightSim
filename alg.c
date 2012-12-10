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
#define _ALG_C_
#include <stdlib.h>
#include <math.h>
#include "sll.h"

/*
 * Functions
 */

/**
 * Creates a vector with n elements.
 * @pre Number of elements is positive.
 * @param n Number of elements in the vector.
 * @return Reference to the vector.
 */
double* algVecCreate(int n)
{
    double *v;

    /* Allocate the memory for the vector */
    v = (double*)calloc(n, sizeof(double));

    return v;
}

/**
 * Creates a m by n matrix.
 * @pre Number of rows is positive (m>0).
 * @pre Number of columns is positive (n>0).
 * @param m Number of rows in the matrix.
 * @param n Number of columns in the matrix.
 * @return Reference to the matrix.
 */
double** algMatCreate(int m, int n)
{
    double **A;
    int i;

    /* Allocate the memory for the matrix */
    A = (double**)calloc(m, sizeof(double*));
    for (i=0; i<m; i++) {
        A[i] = (double*)calloc(n, sizeof(double));
    }

    return A;
}

/**
 * Destroys a vector. Note: It's not necessary to reset the original
 * pointer to NULL.
 * @pre Valid vector (non-null).
 * @param v Reference to the vector.
 */
void algVecDestroy(double *v)
{
    /* Deallocate the memory of the vector */
    free(v);
}

/**
 * Destroys a matrix. Note: It's not necessary to reset the original
 * pointer to NULL.
 * @pre Valid matrix (non-null).
 * @param m Number of rows in the matrix.
 * @param A Reference to the matrix.
 */
void algMatDestroy(int m, double **A)
{
    int i;

    /* Deallocate the memory of the matrix */
    for (i=0; i<m; i++) {
        free(A[i]);
    }
    free(A);
}

/**
 * Calculates the length of a vector.
 * @pre Valid vector (non-null).
 * @param n Number of elements in the vector.
 * @param v Reference to the vector.
 * @return Length of the vector.
 */
double algVecLength(int n, double *v)
{
    double len = 0.0;
    int i;

    /* Calculate the length */
    for (i=0; i<n; i++) {
        len += v[i]*v[i];
    }
    len = sqrt(len);
    return len;
}

/**
 * Copies the given vector. In the process of copying, a new
 * vector is created. This is the vector returned by this 
 * function.
 * @pre Valid vector (non-null).
 * @param n Number of elements in the vector.
 * @param v Reference to the vector.
 * @return A new vector that represents a copy of the original one.
 */
double* algVecCopy(int n, double *v)
{
    double *other;
    int i;

    /* Create a new vector */
    other = algVecCreate(n);

    /* Copy the original one */
    for (i=0; i<n; i++) {
        other[i] = v[i];
    }
    return other;
}

/**
 * Transforms the given vector into an unit vector.
 * @pre Valid vector (non-null).
 * @param n Number of elements in the vector.
 * @param v Reference to the vector.
 */
void algVecUnit(int n, double *v)
{
    double len;
    int i;

    /* Calculate the length */
    len = algVecLength(n, v);

    /* Transform it into an unit vector */
    for (i=0; i<n; i++) {
        v[i] /= len;
    }
}

/**
 * Adds two given vectors and, stores the result in a third one.
 * @pre Valid first vector (non-null).
 * @pre Valid second vector (non-null).
 * @pre Valid resulting vector (non-null).
 * @param n Number of elements in the vector(s).
 * @param v Reference to the first vector.
 * @param w Reference to the second vector.
 * @param v Reference to the resulting vector.
 */
void algVecAdd(int n, double *v, double *w, double *x)
{
    int i;

    /* Add... */
    for (i=0; i<n; i++) {
        x[i] = v[i] + w[i];
    }
}

/**
 * Multiplies a given vector and a given matrix and, stores the result in 
 * a second vector.
 * @pre Valid matrix (non-null).
 * @pre Valid vector (non-null).
 * @pre Valid resulting vector (non-null).
 * @param m Number of rows in the matrix.
 * @param n Number of colums in the matrix, as well as, number of 
 * elements in the vector.
 * @param A Reference to the matrix.
 * @param v Reference to the vector.
 * @param v Reference to the resulting vector.
 */
void algVecMultiply(int m, int n, double **A, double *v, double *w)
{
    int i, j;

    /* Multiply... */
    for (i=0; i<m; i++) {
        w[i] = 0;
        for (j=0; j<n; j++) {
            w[i] += A[i][j]*v[j];
        }
    }
}

/**
 * Multiplies a given vector by a given scalar.
 * @pre Valid vector (non-null).
 * @param n Number of elements in the vector.
 * @param v Reference to the vector.
 * @param c Scalar.
 */
void algVecMultiplyScalar(int n, double *v, double c)
{
    int i;

    /* Multiply... */
    for (i=0; i<n; i++) {
        v[i] *= c;
    }
}

/**
 * Transforms the given vector into a zero vector.
 * @pre Valid vector (non-null).
 * @param m Number of elements in the vector.
 * @param v Reference to the vector.
 */
void algVecZero(int n, double *v)
{
    int i;

    /* Make it 0 */
    for (i=0; i<n; i++) {
        v[i] = 0;
    }
}

/**
 * Copies the given matrix. In the process of copying, a new
 * matrix is created. This is the matrix returned by this 
 * function.
 * @pre Valid matrix (non-null).
 * @param m Number of rows in the matrix.
 * @param n Number of columns in the matrix.
 * @param A Reference to the matrix.
 * @return A new matrix that represents a copy of the original one.
 */
double** algMatCopy(int m, int n, double **A)
{
    double **other;
    int i, j;

    /* Create a new matrix */
    other = algMatCreate(m, n);

    /* Copy the original one */
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            other[i][j] = A[i][j];
        }
    }
    return other;
}

/**
 * Transforms the given matrix into an identity matrix.
 * @pre Valid matrix (non-null).
 * @param n Number of rows and columns in the matrix.
 * @param A Reference to the matrix.
 */
void algMatIdentity(int n, double **A)
{
    int i, j;

    /* Transform it into an identity matrix */
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            A[i][j] = i == j ? 1 : 0;
        }
    }
}

/**
 * Adds two given matrices and stores the result in a third one.
 * @pre Valid matrices (non-null).
 * @param m Number of rows of the matrices.
 * @param n Number of columns of the matrices.
 * @param A Reference to the first matrix.
 * @param B Reference to the second matrix.
 * @param C Reference to the third (resulting) matrix.
 */
void algMatAdd(int m, int n, double **A, double **B, double **C)
{
    int i, j;

    /* Add... */
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

/**
 * Multiplies two given matrices and stores the result in a third one.
 * @pre Valid matrices (non-null).
 * @param m Number of rows of the first matrix.
 * @param l Number of columns of the first matrix and, as well a, number of rows 
 * of the second matrix.
 * @param n Number of columns of the second matrix.
 * @param A Reference to the first matrix.
 * @param B Reference to the second matrix.
 * @param C Reference to the third (resulting) matrix.
 */
void algMatMultiply(int m, int l, int n, double **A, double **B, double **C)
{
    int i, j;

    /* Transform it into an identity matrix */
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            A[i][j] = i == j ? 1 : 0;
        }
    }
}

/**
 * Multiplies a given matrix by a given scalar.
 * @pre Valid matrix (non-null).
 * @param m Number of rows in the matrix.
 * @param n Number of columns in the matrix.
 * @param A Reference to the matrix.
 * @param c Scalar.
 */
void algMatMultiplyScalar(int m, int n, double **A, double c)
{
    int i, j;

    /* Multiply... */
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            A[i][j] *= c;
        }
    }
}

/**
 * Transforms the given matrix into a zero matrix.
 * @pre Valid matrix (non-null).
 * @param m Number of rows in the matrix.
 * @param n Number of columns in the matrix.
 * @param A Reference to the matrix.
 */
void algMatZero(int m, int n, double **A)
{
    int i, j;

    /* Make it 0 */
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            A[i][j] = 0;
        }
    }
}

/* End of file -------------------------------------------------------------- */



