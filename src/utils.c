#include <stdio.h>
#include "utils.h"

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

