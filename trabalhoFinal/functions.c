#include "arq.h"

//Node -> Palavra
//LDDE -> Linha de palavras
//Multi -> arquivo de texto completo

//Função para alocar a multi lista
//Não Recebe argumentos
//Retorna um endereço para a multi lista alocada
Multi * criaMultiLista(){
    Multi *aux = NULL;
    aux = (Multi *)malloc(sizeof(Multi));
    aux->comeco = NULL;
    return aux;
}

//Função para criar uma lista dentro de uma multi lista
//Recebe o endereço onde a multi lista esta alocada
//Retorna um void
LDDE * insereLinha(Multi * ml){
    LDDE *aux = NULL;
    aux = ml->comeco;
    if (aux == NULL){
        aux = (LDDE *)malloc(sizeof(LDDE));
        aux->ant = NULL;
        aux->prox = NULL;
        aux->comeco = NULL;
        ml->comeco = aux;
        return aux;
    } else {
        while (aux->prox != 0x0){
            aux = aux->prox;
        }
        LDDE * aux2 = NULL;
        aux2 = (LDDE *)malloc(sizeof(LDDE));
        aux2->ant = aux;
        aux2->prox = NULL;
        aux2->comeco = NULL;
        aux->prox = aux2;
    }
    return aux->prox;
}

//Função para inserir uma palavra no ultimo elemento de uma lista
//Recebe uma palavra p, no formato de char * e o endereço da lista l onde sera inserida
//Nao retorna nada
void inserePalavra(char * p, LDDE *l){
    Node *aux = NULL;
    aux = l->comeco;
    if ((aux == NULL) || (l->comeco ==0x0)){
        aux = (Node *)malloc(sizeof(Node));
        aux->ant = NULL;
        aux->prox = NULL;
        aux->palavra=(char *)malloc(sizeof(p));
        memcpy(aux->palavra, p, sizeof(p));
        l->comeco = aux;
    } else {
        while (aux->prox != 0x0){
            aux = aux->prox;
        }
        Node * aux2 = NULL;
        aux2 = (Node *)malloc(sizeof(Node));
        aux2->ant = aux;
        aux2->prox = NULL;
        aux2->palavra=(char *)malloc(sizeof(p));
        memcpy(aux2->palavra, p, sizeof(p));
        aux->prox = aux2;
    }
}

Posicao buscaPalavra(char *p, Multi * ml){
    Posicao oc;
    int l = 0, c;
    oc.l = -1;
    oc.c = -1;
    if (ml->comeco == NULL) return oc;
    else {
        LDDE *aux = NULL;
        Node *aux2 = NULL;
        aux = ml->comeco;
        while (aux != NULL){
            c = 0;
            aux2 = aux->comeco;
            while (aux2 != NULL){
                if (strcmp(p, aux2->palavra) == 0 || (aux2->prox == NULL && strcmp(p, aux2->palavra) == -10)){
                    oc.l = l;
                    oc.c = c;
                    printf("%s\n", aux2->palavra);
                    return oc;
                }
                c++;
                aux2 = aux2->prox;
            }
            l++;
            aux = aux->prox;
        }
    }
    oc.l = -1;
    oc.c = -1;
    return oc;
}

void removerPalavra(char *p, Multi *ml){
    removerPalavraEspecifica(buscaPalavra(p, ml), ml);
}

void removerPalavraEspecifica(Posicao oc,Multi *ml){
    if (oc.c == -1) return;
    int i;
    LDDE * aux = NULL;
    aux = ml->comeco;
    if (aux != NULL){
        for (i = 0; i < oc.l; i++){
            if (aux->prox != NULL) aux = aux->prox;
            else return;
        }
        Node *aux2 = NULL;
        aux2 = aux->comeco;
        if (aux2 != NULL){
            for (i = 0; i < oc.c; i++){
                if (aux2->prox != NULL) aux2 = aux2->prox;
                else return;
            }
            if (aux2->ant != NULL){
                if (aux2->prox != NULL){
                    aux2->ant->prox = aux2->prox;
                    if (oc.c == 0){
                        aux->comeco = aux2->prox;
                    }
                    aux2->prox->ant = aux2->ant;
                } else aux2->ant->prox = NULL;
            } else if (aux2->prox != NULL){
                if (oc.c == 0){
                    aux->comeco = aux2->prox;
                }
                aux2->prox->ant = NULL;
            }
            free(aux2);
        }
    }
}

int qtdPalavraEspecifica(char *p, Multi * ml){
    int cont = 0;
    if (ml->comeco == NULL) return 0;
    else {
        LDDE *aux = NULL;
        Node *aux2 = NULL;
        aux = ml->comeco;
        while (aux != NULL){
            aux2 = aux->comeco;
            while (aux2 != NULL){
                if (strcmp(p, aux2->palavra) == 0){
                    cont++;
                }
                aux2 = aux2->prox;
            }
            aux = aux->prox;
        }
    }
    return cont;
}

int qtdPalavras(Multi * ml){
    int cont = 0;
    if (ml->comeco == NULL) return 0;
    else {
        LDDE *aux = NULL;
        Node *aux2 = NULL;
        aux = ml->comeco;
        while (aux != NULL){
            aux2 = aux->comeco;
            while (aux2 != NULL){
                cont++;
                aux2 = aux2->prox;
            }
            aux = aux->prox;
        }
    }
    return cont;
}

void editarPalavra(Posicao oc, char *p, Multi *ml){
    int i;
    LDDE * aux = NULL;
    aux = ml->comeco;
    if (aux != NULL){
        for (i = 0; i < oc.l; i++){
            if (aux->prox != NULL) aux = aux->prox;
            else return;
        }
        Node *aux2 = NULL;
        aux2 = aux->comeco;
        if (aux2 != NULL){
            for (i = 0; i < oc.c; i++){
                if (aux2->prox != NULL) aux2 = aux2->prox;
                else return;
            }
            if (strlen(aux2->palavra) < strlen(p)){
                aux2->palavra = NULL;
                aux2->palavra = (char *)malloc((strlen(p)+1)*sizeof(char));
            }
            strcpy(aux2->palavra,p);
        }
    }
}

int qtdPalavraCaracter(char c, Multi * ml){
    int cont = 0;
    int i;
    if (ml->comeco == NULL) return 0;
    else {
        LDDE *aux = NULL;
        Node *aux2 = NULL;
        aux = ml->comeco;
        while (aux != NULL){
            aux2 = aux->comeco;
            while (aux2 != NULL){
                for (i = 0; i < strlen(aux2->palavra); i++){
                    if (aux2->palavra[i] == c){
                        cont++;
                        break;
                    }
                }
                aux2 = aux2->prox;
            }
            aux = aux->prox;
        }
    }
    return cont;
}
//TODO:
//Atualizar arquivo.txt da seguinte forma:
//  Mover todas as palavras da Multi * para arqTemp.txt
//  Renomear arquivo.txt para arquivoOLD.txt
//  Renomear arqTemp.txt para arquivo.txt
//Fazer o relatório do trabalho
//Ser um usuario