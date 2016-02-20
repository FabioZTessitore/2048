/* test_random.c */

#include <stdio.h>
#include "random.h"

int main()
{
  int i;
  int N = 10; /* numeri da generare per ogni test */

  int test1_min = 30,
      test1_max = 20;

  int test2_min = 30,
      test2_max = 31;

  int test3_min = 30,
      test3_max = 32;

  int test4_min = 30,
      test4_max = 40;

  printf("Inizializza il sistema di generazione\n"
      "dei numeri pseudocasuali ...");
  random_init();
  printf("fatto\n\n");

  printf("Generazione di %d numeri compresi tra %d e %d\n", N, test1_min, test1_max);
  printf("Risultato atteso: %d volte %d\n", N, test1_min);
  for (i=0; i<N; i++) {
    printf("  %3d", random_between(test1_min, test1_max));
  }
  
  printf("\n\nGenerazione di %d numeri compresi tra %d e %d\n", N, test2_min, test2_max);
  printf("Risultato atteso: %d volte %d\n", N, test2_min);
  for (i=0; i<N; i++) {
    printf("  %3d", random_between(test2_min, test2_max));
  }

  printf("\n\nGenerazione di %d numeri compresi tra %d e %d\n", N, test3_min, test3_max);
  printf("Risultato atteso: %d numeri compresi tra %d e %d (escluso)\n", N, test3_min, test3_max);
  for (i=0; i<N; i++) {
    printf("  %3d", random_between(test3_min, test3_max));
  }

  printf("\n\nGenerazione di %d numeri compresi tra %d e %d\n", N, test4_min, test4_max);
  printf("Risultato atteso: %d numeri compresi tra %d e %d (escluso)\n", N, test4_min, test4_max);
  for (i=0; i<N; i++) {
    printf("  %3d", random_between(test4_min, test4_max));
  }

  putchar('\n');

  return 0;
}
