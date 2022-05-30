#include "resol.h"

int freeAB(ABin a) {
  int count = 0;
  if (a) {
    ABin cpy_esq = a->esq;
    ABin cpy_dir = a->dir;
    free(a);
    count++;
    count += freeAB(cpy_esq);
    count += freeAB(cpy_dir);
  }
  return count;
}

void caminho(ABin a) {
  ABin target = a;
  while (a->pai) a = a->pai;
  while (a != target) {
    if (a->valor > target->valor) {
      printf("esq\n");
      a = a->esq;
    } else {
      printf("dir\n");
      a = a->dir;
    }
  }
}