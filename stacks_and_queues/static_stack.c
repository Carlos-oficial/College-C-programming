#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Static_stack {
  int sp;
  int values[MAX];
} SStack;

void initSStack(SStack *s) { s->sp = -1; }
int emptySStack(SStack *s) { return s->sp <= -1; }
int Spush(SStack *s, int n) {
  if (!(s->sp + 1 < MAX))
    return 1;
  s->values[s->sp] = n;
  s->sp++;
  return 0;
}
int Spop(SStack *s, int *n) {
  if (emptySStack(s))
    return 1;
  *n = s->values[s->sp];
  s->sp--;
  return 0;
}

int Stop (SStack* s, int *n){
  if (emptySStack(s))
    return 1;
  *n = s->values[s->sp];
  return 0;
}