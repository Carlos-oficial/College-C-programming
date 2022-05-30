#include "resol.h"

// A
// 1.
int retiraNeg(int v[], int N) {
  for (int i = 0; i < N; i++) {
    if (v[i] < 0) {
      for (int j = i; j < N; j++) // TEM DE SER N-1 !!!!!!!!!!!
        v[j] = v[j + 1];
      N--;
    }
  }
  return N;
}

// 2.
int prefixo_dif(char s[]) {
  int i = 0;
  bool *arr = malloc(sizeof(bool) * 256);
  for (int b = 0; b < 256; b++)
    arr[b] = false;
  for (; s[i]; i++) {
    if (arr[(int)s[i]]) {
      free(arr);
      return i;
    } else
      (arr[(int)s[i]] = true);
  }
  free(arr);
  return i;
}

int difConsecutivos(char s[]) {
  int difs = 0;
  for (int i = 0; s[i]; i++) {
    difs = MAX2(difs, prefixo_dif(s + i));
  }
  return difs;
}

// 3.
int maximo(LInt l) {
  int i = l->valor;
  while (l) {
    i = MAX2(1, l->valor);
    l = l->prox;
  }
  return i;
}

// 4.
int removeAll(LInt *l, int n) {
  if (!*l)
    return (0);
  int count = 0;
  while (*l) {
    if ((*l)->valor == n) {
      LInt cpy = *l;
      *l = (*l)->prox;
      free(cpy);
      count++;
    } else
      l = &(*l)->prox;
  }
  return count;
}

// 5.
LInt new_node(int x, LInt prev) {
  LInt l = malloc(sizeof(struct nodo));
  if (prev)
    prev->prox = l;
  l->valor = x;
  l->prox = NULL;
  return l;
}

LInt arrayToList(int v[], int N) {
  if (!N)
    return NULL;
  LInt fst = new_node(v[0], NULL);
  LInt list = fst;
  for (int i = 1; i < N; i++) {
    list = new_node(v[i], list);
  }
  return fst;
}

void cons(LInt l1, LInt *l2) {
  if (!*l2)
    *l2 = l1;
  l1->prox = *l2;
  *l2 = l1;
}

int procura(LInt *l, int x) {
  LInt head = *l;
  LInt *cpy = l;
  while (*cpy && (*cpy)->valor != x)
    cpy = &(*cpy)->prox;
  if (!*cpy)
    return 0;
  LInt temp = *cpy;
  *cpy = (*cpy)->prox;
  (temp)->prox = head;
  *l = temp;
  return 1;
}

void printL(LInt l) {
  while (l) {
    printf("%d ", l->valor);
    l = l->prox;
  }
  printf("\n");
}

// B
// 1.
int minheapOK(ABin a) {
  if (a) {
    if (a->esq) {
      if (a->valor >= a->esq->valor)
        return 0;
      if (!minheapOK(a->esq))
        return 0;
    }
    if (a->dir) {
      if (a->valor >= a->dir->valor)
        return 0;
      if (!minheapOK(a->dir))
        return 0;
    }
  }
  return 1;
}

// 2.
int maxHeap(ABin a) {
  if (!a->esq && !a->dir)
    return a->valor;
  if (!a->dir)
    return maxHeap(a->esq);
  if (!a->esq)
    return maxHeap(a->dir);
  return (MAX2(maxHeap(a->esq), maxHeap(a->dir)));
}

// 3.
#define MIN2(a, b) (((*a)->valor) < ((*b)->valor) ? (a) : (b))
void removeMin(ABin *a) {
  if (!(*a)->esq && !(*a)->dir)
    *a = NULL;
  else if ((*a)->esq && !(*a)->dir)
    a = &(*a)->esq;
  else if (!(*a)->esq && (*a)->dir)
    a = &(*a)->dir;
  else {
    ABin *min = MIN2(&(*a)->esq, &(*a)->dir);
    (*a)->valor = (*min)->valor;
    removeMin(min);
  }
}

void merge(LInt *r, LInt a, LInt b) {
  while (*r)
    r = &(*r)->prox;
  if (!a && !b)
    return;
  if (a && !b) {
    *r = a;
    return;
  }
  if (!a && b) {
    *r = b;
    return;
  } else {
    if (a->valor < b->valor) {
      *r = a;
      LInt prox = a->prox;
      (*r)->prox = NULL;
      merge(r, prox, b);
    } else {
      *r = b;
      LInt prox = b->prox;
      (*r)->prox = NULL;
      merge(r, a, prox);
    }
  }
}

// 4.
void latino(int N, int m[N][N]) {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      m[i][j] = (j+i+1)%N;
}

int main() {
  int arr1[] = {1, 3, 5, 10, 11};
  int arr2[] = {2, 4, 6, 8, 12};
  LInt l1 = arrayToList(arr1, 5);
  LInt l2 = arrayToList(arr2, 5);
  printL(l1);
  printL(l2);
  LInt *l3 = malloc(sizeof(LInt));
  *l3 = NULL;
  merge(l3, l1, l2);
  printL(*l3);
  return 0;
}