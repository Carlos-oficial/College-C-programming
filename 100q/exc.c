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

void init(LInt *l) {
  while ((*l)->prox) {
    l = &(*l)->prox;
  }
  *l = NULL;
  free(*l);
}

void appendL(LInt *l, int x) {
  while (*l) {
    l = &(*l)->prox;
  }
  *l = new_node(x);
}

void concatL(LInt *a, LInt b) {
  while (*a) {
    a = &(*a)->prox;
  }
  *a = b;
}

LInt cloneL(LInt l) {
  if (!l)
    return NULL;
  LInt fst = malloc(sizeof(Node));
  fst->valor = l->valor;
  fst->prox = NULL;
  LInt prev = fst;
  l = l->prox;
  while (l) {
    LInt new = new_node(l->valor);
    prev->prox = new;
    prev = new;
    l = l->prox;
  }
  return fst;
}
LInt cloneRev(LInt l) {
  if (!l)
    return NULL;
  LInt fst = malloc(sizeof(Node));
  fst->valor = l->valor;
  fst->prox = NULL;
  LInt prev = fst;
  l = l->prox;
  if (!l)
    return NULL;
  while (l) {
    LInt new = new_node(l->valor);
    new->prox = prev;
    prev = new;
    l = l->prox;
  }
  return prev;
}

int maximo(LInt l) {
  int acc = l->valor;
  while (l) {
    if (l->valor > acc)
      acc = l->valor;
    l = l->prox;
  }
  return acc;
}

int take(int n, LInt *l) {
  while (n && *l) {
    l = &(*l)->prox;
    n -= 1;
  }
  int i = 0;
  while (*l) {
    i++;
    Node a = **l;
    free(*l);
    *l = (a).prox;
  }
  printf("%d taken\n", i);
  return i;
}

int drop(int n, LInt *l) {
  int i = 0;
  while (*l && n) {
    LInt *a = &(*l)->prox;
    //  free(l);
    *l = *a;
    n--;
    i++;
  }
  return i;
}

void cycle(LInt *l) {
  LInt fst = *l;
  while (*l) {
    l = &(*l)->prox;
  }
  *l = fst;
}

void printC(LInt l) {
  LInt fst = l;
  if (l == NULL)
    return;
  do {
    printf("%d ", l->valor);
    l = l->prox;
  } while (l != fst);
  printf("\n");
}

LInt Nforward(LInt l, int N) {
  while (N) {
    l = l->prox;
    N--;
  }
  return l;
}

LInt arrayToList(int *arr, int len) {
  LInt list = malloc(sizeof(Node));
  LInt fst = list;
  for (int i = 0; i < len - 1; i++) {
    LInt new = new_node(arr[i + 1]);
    list->valor = arr[i];
    list->prox = new;
    list = list->prox;
  }
  return fst;
}
LInt somasAcL(LInt l) {
  int soma = 0;
  if (!l)
    return NULL;
  LInt fst = malloc(sizeof(Node));
  fst->valor = soma += l->valor;
  fst->prox = NULL;
  LInt prev = fst;
  l = l->prox;
  while (l) {
    LInt new = new_node(soma += l->valor);
    prev->prox = new;
    prev = new;
    l = l->prox;
  }
  return fst;
}

void remreps(LInt l) {
  LInt prev = NULL;

  while (l) {
    if (prev && (l->valor == prev->valor)) {
      LInt a = l->prox;
      free(l);
      l = a;
      prev->prox = l;
    } else
      prev = l;
    l = l->prox;
  }
}

LInt rotateL(LInt l) {
  if (!(l || l->prox))
    return l;
  LInt initL = l->prox;
  LInt fst = l;
  while (l->prox != NULL) {
    l = l->prox;
  }
  l->prox = fst;
  fst->prox = NULL;
  return initL;
}

LInt parte(LInt l) {
  LInt output = malloc(sizeof(Node)), prev_out = NULL;
  LInt *fst = &output;
  LInt prev = NULL, aux;
  while (l) {
    if (l->valor % 2 == 1) {
      output = l;
      prev_out->prox = output;
      output->prox = NULL; //
      aux = l->prox;
      prev->prox = aux;
      l = aux;
    } else{
      prev = l;
      l = l->prox;}
  }
  return *fst;
}

int main() {
  int arr1[] = {1, 2, 3, 4, 5, 6};
  LInt l1 = malloc(sizeof(Node));
  generate_from_array(arr1, 6, &l1);
  printl(parte(l1));
}

