#include <stdio.h>
#include <mpi.h>
#include <omp.h>
#include <time.h>
#include "utils.h"

int main(int argc, char** argv)
{
  //MPI Initialization stuff
  
  MPI_Init(&argc, &argv);
  int world_size, world_rank;

  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  
  clock_t tic, toc;
  tic = clock();

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

  toc = clock();
  
  printMatrix(test);
  printMatrix(B);
  printMatrix(D);
  mat* test2 = readMatrix("test.mat");
  printf("Matrix: %d %d \n", test2->i, test2->j);
  freeMatrix(test2);
  freeMatrix(D);
  freeMatrix(B);
  freeMatrix(test);
  printf("Time it takes between tic and toc = %fms\n", tictoc(tic,toc));
  return 0;

}
