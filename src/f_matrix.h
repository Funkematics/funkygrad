typedef struct mat {
  double **elem;
  int i;
  int j;
} mat;

mat* initMatrix(int rows, int cols);
void freeMatrix(mat *A);
void printMatrix(mat *A);
mat* fillIdentity(mat *A);
