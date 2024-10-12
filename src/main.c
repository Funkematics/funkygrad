#include <stdio.h>
#include "f_matrix.h"

int main(void)
{
  mat* test = initMatrix(3,4);
  mat* B = initMatrix(4,3);
  mat* D = initMatrix(10,10);
  D = fillIdentity(D);

  B = fillIdentity(B);
  if (test) {
    for (int i = 0; i < test->i; i++) {
      for (int j = 0; j < test->j; j++) {
        test->elem[i][j] = i * test->j + j;
      }
    }
    for (int i = 0; i < test->i; i++) {
      for (int j = 0; j < test->j; j++) {
        printf("%f ", test->elem[i][j]);
      }
      printf("\n");
    }
  }

  printMatrix(test);
  printMatrix(B);
  printMatrix(D);
  freeMatrix(D);
  freeMatrix(B);
  freeMatrix(test);
  printf("Hello \n");
  return 0;

}
