#include <stdio.h>
#include "int_list.h"

int main()
{
  IntList il;
  int capacity;
  int i;

  printf("IntList\n\n");

  do {
    printf("Numero di elementi da allocare (0-100)\n");
    printf("? ");
    scanf("%d", &capacity);
  } while (capacity<0 || capacity>100);

  printf("Inizializzazione della IntList ...\n");
  intlist_init(&il, capacity);
  printf("IntList creata\n");
  intlist_dump(&il);
  putchar('\n');

  printf("Aggiunge elementi\n");
  for (i=0; i<capacity; i++) {
    intlist_push(&il, i+1);
  }
  intlist_dump(&il);
  putchar('\n');

  printf("Rimuove tutti gli elementi\n");
  intlist_clear(&il);
  intlist_dump(&il);
  putchar('\n');

  printf("Check for IntList Overflow\n");
  for (i=0; i<capacity+capacity; i++) {
    if (intlist_push(&il, i) < 0) {
      break;
    }

    printf("aggiunto elemento %3d/%d    ", i+1, capacity);
    if ((i+1)%4==0) putchar('\n');
  }
  intlist_dump(&il);

  printf("Libera la memoria ...\n");
  intlist_destroy(&il);

  return 0;
}
