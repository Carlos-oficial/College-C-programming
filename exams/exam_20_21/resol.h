#include <stdio.h>

typedef struct nodo {
  int valor;
  struct nodo *prox;
} * LInt;

typedef struct AB_nodo {
int valor;
struct AB_nodo *pai, *esq, *dir;
} *ABin;