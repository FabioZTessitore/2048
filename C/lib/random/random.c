/* random.c */

#include <time.h>
#include <stdlib.h>
#include "random.h"

void random_init()
{
  srand((unsigned int)time(NULL));
}

int random_between(int min, int max)
{
  if (max <= min) {
    max = min+1;
  }

  return rand()%(max-min)+min;
}
