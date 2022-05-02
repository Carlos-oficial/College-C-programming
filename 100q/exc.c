#include <stdio.h>
#include <stdlib.h>

#define eef else if
#define oof else

typedef struct lligada {
  int valor;
  struct lligada *prox;
} * LInt, Node;

int length(LInt l) {
  int i = 0;
  while (l) {
    i++;
    l = l->prox;
  }
  return i;
}
void printl(LInt l) {
  if (!l)
    printf("vazia");
  while (l) {
    printf("%d ", l->valor);
    l = l->prox;
  }
  printf("\n");
}

LInt new_node(int valor) {
  LInt new = malloc(sizeof(Node));
  new->valor = valor;
  new->prox = NULL;
  return new;
}

void generate_from_array(int *arr, int len, LInt *list) {
  for (int i = 0; i < len - 1; i++) {
    LInt new = new_node(arr[i + 1]);
    (*list)->valor = arr[i];
    (*list)->prox = new;
    list = &(*list)->prox;
  }
}

void freeL(LInt l) {
  LInt nxt;
  while (l) {
    nxt = l->prox;
    free(l);
    l = nxt;
  }
}

LInt reverseL(LInt l) {
  LInt aux = NULL, prox;
  while (l) {
    prox = l->prox;
    l->prox = aux;
    aux = l;
    l = prox;
  }
  return aux;
}

void insertL(LInt *l, int x) {
  while (*l && ((*l)->valor < x)) {
    l = &(*l)->prox;
  }
  LInt new = new_node(x);
  *l = new;
  new->prox = (*l)->prox;
}

int removeOneOrd(LInt *l, int x) {
  while (*l && ((**l).valor < x)) {
    l = &(*l)->prox;
  }
  if (x == (**l).valor) {
    *l = (**l).prox;
    return 0;
  }
  return 1;
}

void merge(LInt *r, LInt l1, LInt l2) {
  while (l1 && l2) {
    if (l1->valor <= l2->valor) {
      *r = l1;
      l1 = l1->prox;
    } else {
      *r = l2;
      l2 = l2->prox;
    }
    r = &(*r)->prox;
  }
  if (l1)
    *r = l1;
  else
    *r = l2;
}

void append_node(Node **n1, Node *n2) {
  if (!(*n1))
    (*n1) = n2;
  else {
    (*n1)->prox = n2;
  }
}

void splitQS(LInt l, int x, LInt *mx, LInt *Mx) {
  LInt prox;
  while (l) {
    prox = l->prox;
    l->prox = NULL;
    if (l->valor < x) {
      append_node(mx, l);
      mx = &(*mx)->prox;
    } else {
      append_node(Mx, l);
      Mx = &(*Mx)->prox;
    }
    l = prox;
  }
}

LInt parteAmeio(LInt *l) {
  int len = length(*l);
  LInt new = malloc(sizeof(Node));
  new = NULL;
  for (int i = 0; i < len / 2; i++) {
    append_node(&new, *l);
    l = &(*l)->prox;
  }
  return new;
}

int removeAll(LInt *l, int x) {
  int i = 0;
  while (*l) {
    if (x == (**l).valor) {
      *l = (**l).prox;
      i++;
    } else {
      l = &(*l)->prox;
    }
  }
  return i;
}

int removeDups(LInt *l) {
  int i = 0;
  while (*l) {
    i += removeAll(&(*l)->prox, (**l).valor);
    l = &(*l)->prox;
  }
  return i;
}

int removeMaiorL(LInt *l) {
  LInt *acc = l;
  while (*l) {
    if ((**l).valor > (**acc).valor) {
      acc = l;
    }
    l = &(*l)->prox;
  }
  int maior = (**acc).valor;
  (*acc) = (**acc).prox;
  return maior;
}

int main() {
  int arr1[] = {1, 3, 5, 7};
  int arr2[] = {2, 4, 6, 8};
  LInt l1 = malloc(sizeof(Node));
  LInt l2 = malloc(sizeof(Node));
  generate_from_array(arr1, 4, &l1);
  generate_from_array(arr2, 4, &l2);
  LInt l3 = NULL;
  merge(&l3, l1, l2);
  printl(l3);
  LInt *mx = malloc(sizeof(LInt));
  *mx = NULL;
  LInt *Mx = malloc(sizeof(LInt));
  *Mx = NULL;
  splitQS(l3, 5, mx, Mx);
  printl(*mx);
  printl(*Mx);
  printl(parteAmeio(&l3));
  int arr3[] = {1, 1, 3, 5, 5};
  LInt l4 = malloc(sizeof(Node));
  generate_from_array(arr3, 5, &l4);
  // removeDups(&l4);
  printf("maior: %d\n", removeMaiorL(&l4));
  printl(l4);
  removeOneOrd(&l4, 3);
  printl(l4);
}