#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

void intlist_init(IntList *il, int dimension)
{
  il->size = 0;
  il->dimension = dimension;
  il->values = (int*)malloc(sizeof(int)*dimension);
  if (!il->values) {
    fprintf(stderr, "intlist_init: impossibile allocare memoria");
    exit(-1);
  }
}

void intlist_destroy(IntList *il)
{
  il->size = 0;
  il->dimension = 0;
  if (il->values) {
    free(il->values);
    il->values = NULL;
  }
}

void intlist_clear(IntList *il)
{
  il->size = 0;
}

int intlist_push(IntList* il, int value)
{
  if (il->size >= il->dimension) {
    return -1;
  }

  il->values[il->size++] = value;

  return il->size;
}

int intlist_get(IntList *il, int index, int *value)
{
  if (index<0 || index>=il->size) {
    *value = 0;
    return 0;
  }

  *value = il->values[index];
  return 1;
}

int intlist_length(IntList *il)
{
  return il->size;
}

void intlist_dump(IntList *il)
{
  int i;

  printf("Dimensione allocata: %d\n", il->dimension);
  printf("Dimensione attuale: %d\n", il->size);
  printf("[ ");
  for (i=0; i<il->size; i++) {
    printf("%d ", il->values[i]);
  }
  printf("]\n");
}
