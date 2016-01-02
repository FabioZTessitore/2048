#ifndef INTLIST_H
#define INTLIST_H

#define MAX_SIZE 100

struct intlist {
  int values[MAX_SIZE];
  int size;
};

typedef struct intlist IntList;

int intlist_length(IntList*);
void intlist_push(IntList*, int value);
void intlist_clear(IntList*);
void intlist_dump(IntList*);

#endif
