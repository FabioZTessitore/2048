#include <stdio.h>
#include "int_list.h"

int main()
{
  IntList il;

  printf("IntList Test\n\n");

  printf("Appena creata\n");
  intlist_clear(&il);
  intlist_dump(&il);
  putchar('\n');

  printf("Aggiunge gli elementi 1, 2, 3\n");
  intlist_push(&il, 1);
  intlist_push(&il, 2);
  intlist_push(&il, 3);
  intlist_dump(&il);
  putchar('\n');

  printf("Rimuove tutti gli elementi\n");
  intlist_clear(&il);
  intlist_dump(&il);
  putchar('\n');

  printf("Check for IntList Overflow\n");
  int i;
  for (i=0; i<MAX_SIZE+MAX_SIZE; i++) {
    intlist_push(&il, i);
  }
  intlist_dump(&il);

  return 0;
}
