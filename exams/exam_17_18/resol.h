#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX2(a, b) ((a) > (b) ? (a) : (b))

typedef struct slists *LInt;
struct slists {
  int valor;
  LInt prox;
};
typedef struct nodo *ABin;
struct nodo {
  int valor;
  ABin esq, dir;
};