#include <stdio.h>
#include "f_matrix.h"

int main(void)
{
  mat* test = initMatrix(3,4);

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
    freeMatrix(test);
  }
  printf("Hello \n");
  return 0;

}
