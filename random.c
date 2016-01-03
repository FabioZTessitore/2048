#include <time.h>
#include <stdlib.h>
#include "random.h"

void random_init()
{
  srand((unsigned int)time(NULL));
}

int random_between(int min, int max)
{
  return rand()%(max-min)+min;
}
