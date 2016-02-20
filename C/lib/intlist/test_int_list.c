/* test_int_list.c */

#include <stdio.h>
#include "int_list.h"

int main()
{
  IntList il;
  int capacity = 10;

  int i;

  printf("IntList\n\n");

  printf("Crea una IntList di %d elementi\n", capacity);
  printf("Inizializzazione della IntList ...\n");
  intlist_init(&il, capacity);
  printf("IntList creata\n");
  intlist_dump(&il);
  putchar('\n');

  printf("Aggiunge elementi da 1 a %d\n", capacity);
  for (i=0; i<capacity; i++) {
    intlist_push(&il, i+1);
  }
  intlist_dump(&il);
  putchar('\n');

  printf("Rimuove tutti gli elementi\n");
  intlist_clear(&il);
  intlist_dump(&il);
  putchar('\n');

  printf("IntList Overflow\n");
  for (i=0; i<capacity+capacity; i++) {
    if (intlist_push(&il, i) < 0) {
      break;
    }
    printf("aggiunto elemento %3d/%d    ", i+1, capacity);
    if ((i+1)%4==0) putchar('\n');
  }
  intlist_dump(&il);

  printf("Libera la memoria ...");
  intlist_destroy(&il);
  printf(" fatto\n\n");

  return 0;
}
