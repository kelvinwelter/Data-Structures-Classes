#include "arq.h"

int main(void) {
    FILE *p;
    p = fopen("arquivo.txt", "r");
    char *a;
    char *b;
    char c;
    char linha[1000];
    Multi * ml = criaMultiLista();
    while(!feof(p)){
        LDDE * aux = insereLinha(ml);
        a = fgets(linha, 1000, p);
        b = strtok(a, " ");
        while (b != NULL){
            inserePalavra(b, aux);
            b = strtok(NULL, " ");
        }
    }
    int respUsuario = -1;
    char caractere;
    while (respUsuario != 0){
        printf("Digite a operacao a ser realizada:\n");
        printf("Buscar palavra. (1)\n");
        printf("Remover palavra. (2)\n");
        printf("Inserir palavra. (3)\n");
        printf("Quantidade de palavras (4)\n");
        printf("Editar palavra. (5)\n");
        printf("Encerrar programa. (0)\n");
        scanf("%d", &respUsuario);
        if (respUsuario == 0){
            printf("O programa registrara as alteracoes e encerrara\n");
            return 0;
        } else if (respUsuario > 0 && respUsuario < 6){
            switch (respUsuario){
                case 1:
                    printf("Buscar palavra por posição(1)\n");
                    printf("Buscar palavra específica(2)\n");
                    scanf("%d", &respUsuario);
                    if (respUsuario == 1){
                        printf("Digite a posição que deseja buscar\n");
                        // input posição
                        // chama função
                    } else if (respUsuario == 2){
                        // input palavra
                        // chama função
                    } else {
                        printf("Operacao invalida\n");
                    }
                    break;
                case 2:
                    printf("Deseja remover uma palavra em geral(1) ou uma palavra de posição específica(2)?\n");
                    scanf("%d", &respUsuario);
                    if (respUsuario == 1){
                        // input palavra aqui
                        // chama função removePalavra
                    } else if (respUsuario == 2){
                        printf("Digite a posição que deseja buscar\n");
                        // input posição aqui
                        // chama função removePalavraEspecifica
                    } else {
                        printf("Operacao invalida\n");
                    }
                    break;
                case 3:
                    // criar a função dessa porra
                    break;
                case 4:
                    printf("Todas as palavras(1)\n");
                    printf("Palavras especificas(2)\n");
                    scanf("%d", &respUsuario);
                    if (respUsuario == 1){
                        printf("%d\n", qtdPalavras(ml));
                    } else if (respUsuario == 2){
                        printf("Digite um caractere\n");
                        fflush(stdin);
                        scanf("%s", &caractere);
                        printf("%d\n", qtdPalavraCaracter(caractere, ml));
                    } else {
                        printf("Operacao invalida\n");
                    }
                    break;
                case 5:
                    printf("Digite a posição que deseja editar\n");
                    // input posição aqui
                    printf("Digite a palavra que deseja inserir na posição digitada\n");
                    // input palavra aqui
                    // chamar função editarPalavra aqui
                    break;
            }
            respUsuario = -1;
            printf("Deseja realizar nova operacao? (S/N)\n");
            getchar();
            scanf("%c", &c);
            if (c == 'N' || c == 'n'){
                respUsuario = 0;
            }
        } else {
            printf("Operacao invalida, aperte enter para tentar novamente\n");
            getchar();
            getchar();
        }
    }
}
