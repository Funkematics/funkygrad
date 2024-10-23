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
    A->elem[i] = (double*)malloc(cols * sizeof(double));
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

void printMatrix(mat *A)
{
  for (int i = 0; i < A->i; i++) {
    for (int j = 0; j < A->j; j++) {
      printf("%f ", A->elem[i][j]);
    }
    printf("\n");
  }
}

mat* fillIdentity(mat *A)
{

  if (A->i == A->j) {
    for (int i = 0; i < A->i; i++) {
      for (int j = 0; j < A->j; j++){
        if (i == j) {
          A->elem[i][j] = 1.0;
        }
        else {
          A->elem[i][j] = 0.0;
        }
      }
    }
  }
  else {
    fprintf(stderr, "Matrix must be of square dimensions\n");
    return A;
  }
  return A;
}
int count_words(const char *str) 
{
  int count = 0;
  int in_word = 0;

  while(*str) {
    if (*str == ' ') {
      in_word = 0;
    } else if (!in_word) {
      count++;
      in_word = 1;
    }
    str++;
  }
  return count;
}

mat* readMatrix(const char *filename) 
{
  FILE *file;
  char line[MAX_LENGTH];
  int rows = 0;
  int columns = 0;

  file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file");
    return NULL; 
  }

  while (fgets(line, sizeof(line), file) != NULL) {
    rows++;
    columns = count_words(line);
    if (columns > MAX_LENGTH && rows > MAX_LENGTH) {
      columns = MAX_LENGTH;
      rows = MAX_LENGTH;
      break;
    }
  }
  fclose(file);

  return initMatrix(rows, columns);
}



