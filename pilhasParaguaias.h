#include <stdio.h>
#include <stdlib.h>

#define MaxPilha 100
#define ErroPilhaVazia -1
#define ErroPilhaCheia -2

typedef struct pilha {
  int dados[MaxPilha];
  int topo;
} pilhaTeste;

void inicializaPilha(pilhaTeste *p);
bool pilhaVazia(pilhaTeste *p);
bool pilhaCheia(pilhaTeste *p);
int empilha(pilhaTeste *p, int n);
int desempilha(pilhaTeste *p);
int elementoNoTopo(pilhaTeste *p);

void inicializaPilha(pilhaTeste *p) {
  p -> topo = -1;
}

bool pilhaVazia(pilhaTeste *p){
  if (p -> topo == -1) {
    return true;
  } else{
    return false;
  }
}

bool pilhaCheia(pilhaTeste *p){
  if (p -> topo == MaxPilha - 1) {
    return true;
  } else {
    return false;
  }
}

int empilha(pilhaTeste *p, int n){
  if (pilhaCheia(p)) {
    return -2;
  } else {
    p -> topo = p -> topo + 1;
    p -> dados[p -> topo] = n;
    return p -> topo;
  }
}

int desempilha(pilhaTeste *p){
  if (pilhaVazia(p)) {
    return -1;
  } else {
    p -> topo = p -> topo - 1;
    return p -> dados[p -> topo + 1];
  }
}

int elementoNoTopo(pilhaTeste *p){
  if (pilhaVazia(p)) {
    return -1;
  } else {
    return p -> dados[p -> topo];
  }
}
