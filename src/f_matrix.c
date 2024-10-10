#include <stdio.h>
#include <stdlib.h>
#include "f_matrix.h"

#define MAX_LENGTH 1000

mat* initMatrix(int rows, int cols)
{
  //For functions that operate on any matrix, we denote the matrix with capital letters internally
  //We use A, B, C .... Z etc, this is standard in many math texts.
  mat* A = (mat*)malloc(sizeof(mat));
  if (A == NULL) {
    fprintf(stderr, "Failure to allocate memory for matrix\n");
    return NULL;
  }

  A->i = rows;
  A->j = cols;

  A->elem = (double**)malloc(rows * sizeof(double*));
  if (A->elem == NULL) {
    fprintf(stderr, "Failure to allocate memory for elements in matrix\n");
    free(A);
    return NULL;
  }

  for (int i = 0; i < rows; i++) {
    A->elem[i] = (double*)malloc(cols * sizeof(int));
    if (A->elem[i] == NULL){
      fprintf(stderr, "Memory allocation failed\n");
      for (int j = 0; j < i; j++) {                     //Can replace with freeMatrix function
        free(A->elem[j]);
      }
      free(A->elem);
      free(A);
      return NULL;
    }
  }
return A;
}

void freeMatrix(mat *A)
{
  if (A == NULL) {
    return;
   }
  // Note that A->i is the internal index for matrix
  for (int i = 0; i < A->i; i++) {
    free(A->elem[i]);
  }
  free(A->elem);
  free(A);
}

