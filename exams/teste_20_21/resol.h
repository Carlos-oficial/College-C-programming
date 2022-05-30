#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
  int valor;
  struct nodo *pai, *esq, *dir;
} * ABin;