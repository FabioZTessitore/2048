#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

int intlist_length(IntList* il)
{
  return il->size;
}

void intlist_push(IntList* il, int value)
{
  if (il->size < MAX_SIZE) {
    il->values[il->size] = value;
    il->size += 1;
  } else {
    fprintf(stderr, "Int List overflow\n");
    exit(-1);
  }
}

void intlist_clear(IntList* il)
{
  il->size = 0;
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

int intlist_get(IntList *il, int index)
{
  if (index<0 || index>=il->size) {
    fprintf(stderr, "intlist: index of ouf bound\n");
    exit(-1);
  }

  return il->values[index];
}
