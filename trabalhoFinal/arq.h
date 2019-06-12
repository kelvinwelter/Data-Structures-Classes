#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *palavra;
    struct node *ant;
    struct node *prox;
} Node;

typedef struct ldde{
    Node *comeco;
    struct ldde *ant;
    struct ldde *prox;
} LDDE;

typedef struct {
    LDDE *comeco;
} Multi;

typedef struct {
    int l, c;
} Posicao;

Multi * criaMultiLista();
LDDE * insereLinha(Multi * ml);
void inserePalavra(char * p, LDDE *l);
Posicao buscaPalavra(char *p, Multi * ml);
void removerPalavra(char *p, Multi *ml);
void removerPalavraEspecifica(Posicao oc,Multi *ml);
int qtdPalavraEspecifica(char *p, Multi * ml);
int qtdPalavras(Multi * ml);
void editarPalavra(Posicao oc, char *p, Multi *ml);
int qtdPalavraCaracter(char c, Multi * ml);
