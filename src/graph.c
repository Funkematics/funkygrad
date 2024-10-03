#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


Node* create_node(int value) 
{
  Node* node = (Node*)malloc(sizeof(Node));
  if (node == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
  node->value = value;
  node->children = NULL;
  node->child_count = 0;
  node->parent = NULL;
  return node;
}
