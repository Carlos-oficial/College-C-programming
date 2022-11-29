#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
  int valor;
  struct lligada *prox;
} * LInt, Node;

typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} * ABin;

// 28.
int altura(ABin a) {
  if (!a) return 0;
  return 1 + ((altura(a->esq) > altura(a->dir)) ? altura(a->esq) : altura(a->dir));
}

// 29.
ABin cloneAB(ABin a) {
  if (!a)
    return NULL;
  ABin head = malloc(sizeof(struct nodo));
  head->valor = a->valor;
  head->dir = cloneAB(a->dir);
  head->esq = cloneAB(a->esq);
  return head;
}

// 30.
void swap_Abin(ABin *a, ABin *b) {
  ABin aux = *a;
  *a = *b;
  *b = aux;
}

void mirror(ABin *a) {
  if (!*a)
    return;
  swap_Abin(&(*a)->dir, &(*a)->esq);
  mirror(&(*a)->dir);
  mirror(&(*a)->esq);
}

// 31.
void new_node(int valor, LInt *l) {
  LInt new = malloc(sizeof(struct lligada));
  new->valor = valor;
  new->prox = *l;
  *l = new;
}
void inorder(ABin a, LInt *l) {
  if (!a) return;
  inorder(a->dir,l);
  new_node (a->valor,l);
  inorder(a->esq,l);
  return;
}

// 32.
