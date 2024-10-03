#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
  int value;
  struct node** children;
  int child_count;
  struct Node* parent;
} Node;
