#include <stdio.h>
#include "f_matrix.h"

int main(int argc, char* argv[])
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
  mat* test2 = readMatrix("test.mat");
  printf("Matrix: %d %d \n", test2->i, test2->j);
  freeMatrix(test2);
  freeMatrix(D);
  freeMatrix(B);
  freeMatrix(test);
  printf("Hello \n");
  return 0;

}
