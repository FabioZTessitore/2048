#include <stdio.h>
#include "int_list.h"

void intlist_clear(IntList* il)
{
  il->size = 0;
}

int intlist_push(IntList* il, int value)
{
  if (il->size >= MAX_SIZE) {
    return -1;
  }

  il->values[il->size] = value;
  il->size += 1;

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

int intlist_length(IntList* il)
{
  return il->size;
}

void intlist_dump(IntList* il)
{
  int i;

  printf("(%d) [ ", il->size);
  for (i=0; i<il->size; i++) {
    printf("%d ", il->values[i]);
  }
  printf("]\n");
}
