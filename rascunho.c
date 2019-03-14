#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
  struct nodo *esq;
  int w;
  struct nodo *dir;
} Nodo;

int main(int argc, char const *argv[]) {
  Nodo *p, *q;
  // ESTADO 1
  // ida 1
  p -> esq = p -> esq -> dir;
  // volta 1
  p -> esq -> dir = p -> esq;

  // ESTADO 2
  // ida 1
  return 0;
}

/*typedef struct nodo {
  struct nodo *esq;
  int w;
  struct nodo *dir;
} Nodo;

int main(int argc, char const *argv[]) {
  Nodo *p;
  //ida 1
  p -> esq -> dir -> esq = p -> esq;
  //volta 1
  p -> esq -> dir = p -> esq -> dir;
  //ida 2
  p -> esq -> dir -> dir = p;
  //volta 2
  p -> esq = p -> esq -> dir;
  return 0;
}*/

//pt1 -> b = pt2;
//pt2 -> b = pt3;
