#include "resol.h"

// 1.
void swapM(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

int paresImpares(int v[], int N) {
  int i = 0, j = N - 1;
  while (i <= j) {
    if (v[i] % 2)
      swapM(v + i, v + j--);
    else
      i++;
  }
  return i;
}
// 2.
void append(LInt *a, LInt b) {
  while (*a)
    a = &(*a)->prox;
  *a = b;
}

void merge(LInt *r, LInt a, LInt b) {
  while (*r) r = &(*r)->prox;
  if (!a && !b) return;
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
      merge(r,prox,b);
    } else {
      *r = b;
      LInt prox = b->prox; 
      (*r)->prox = NULL;
      merge(r,a,prox);
    }
  }
}

// 4. 
ABin next (ABin a){
  if(a->dir) return a->dir;
  if(a->pai) return a->pai;
  return NULL; 
}

// 5.


int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (int i = 0; i < 10; i++)
    printf("%d ", arr[i]);
  printf("\n");
  printf("pares: %d\n", paresImpares(arr, 10));
  for (int i = 0; i < 10; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}