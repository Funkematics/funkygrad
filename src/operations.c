#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "f_matrix.h"

void f_add(mat *A, mat *B, mat *C)
{
  if(A->i != B->i || A->j != B->j || A->i != C->i || A->j != C->j) {
    fprintf(stderr, "Matrix dimensions need to be the same for addition\n");
    exit(1);
  }
  #pragma omp parallel for collapse(2)
  for(int i = 0; i < A->i; i++) {
    for(int j = 0; j < A->j; j++) {
      C->elem[i][j] = A->elem[i][j] + B->elem[i][j];
    }
  }
}
