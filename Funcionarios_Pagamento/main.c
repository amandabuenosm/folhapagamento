#include<stdio.h>
#include "controleFuncionario.h"

int armazenamento=0; 
struct Funcionario funcionario[MAX_ARRAY];
struct Folha folha[MAX_ARRAY];

int main() {
    int opcao;
    do {
        printf("\n---MENU DE OPÇÕES---\n");
        printf("1 - Adicionar funcionário\n");
        printf("2 - Remover funcionário\n");
        printf("3 - Listar todos os funcionários\n");
        printf("4 - Listar folhas de todos\n");
        printf("5 - Listar folhas por cargo\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: "); scanf("%d",&opcao);
        
        switch (opcao) { 
            case 1: 
            addFunc();
            break;
            case 2: 
            delFunc();
            break;
            case 3: 
            listarFunc();
            break;
            case 4: 
            folhaTodos();
            break;
            case 5:
            folhaCargo();
            break;
            case 0:
            printf("\nENCERRANDO O PROGRAMA...\n");
            break;
            default:
            printf("\nOPÇÃO INVÁLIDA!\n");
        } 
    } while (opcao != 0);
    return 0;
}