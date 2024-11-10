#ifndef F_MATRIX_H
#define F_MATRIX_H

#define MAX_LENGTH 1000

typedef struct mat {
  double **elem;
  int i;
  int j;
} mat;


mat* initMatrix(int rows, int cols);
void freeMatrix(mat *A);
void printMatrix(mat *A);
mat* fillIdentity(mat *A);
int count_words(const char *str);

#endif
