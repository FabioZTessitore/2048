#include <stdio.h>
#include "int_list.h"

int main()
{
  IntList il;

  printf("IntList\n\n");

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
    if (intlist_push(&il, i) < 0) {
      break;
    }

    printf("aggiunto elemento %3d/%d    ", i+1, MAX_SIZE);
    if ((i+1)%4==0) putchar('\n');
  }
  intlist_dump(&il);

  return 0;
}
