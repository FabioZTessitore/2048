/* int_list.c */

#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

void intlist_init(IntList *il, int capacity)
{
  if (il==NULL) {
    fprintf(stderr, "intlist_init: puntatore a IntList non valido\n");
    exit(-1);
  }
  if (capacity <= 0) {
    fprintf(stderr, "intlist_init: capacity deve essere positivo\n");
    exit(-1);
  }

  il->size = 0;
  il->capacity = capacity;
  il->values = (int*)malloc(sizeof(int)*capacity);
  if (!il->values) {
    fprintf(stderr, "intlist_init: impossibile allocare memoria\n");
    exit(-1);
  }
}

void intlist_destroy(IntList *il)
{
  il->size = 0;
  il->capacity = 0;
  if (il->values!=NULL) {
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
  if (il->size >= il->capacity) {
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

int intlist_capacity(IntList *il)
{
  return il->capacity;
}

void intlist_dump(IntList *il)
{
  int i;

  printf("Dimensione allocata: %d\n", intlist_capacity(il));
  printf("Dimensione attuale: %d\n", intlist_length(il));
  printf("[ ");
  for (i=0; i<il->size; i++) {
    printf("%d ", il->values[i]);
  }
  printf("]\n");
}
