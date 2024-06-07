#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "controleFuncionario.h"

void addFunc() {
    if (armazenamento >= MAX_ARRAY) {
        printf("\nERRO! LISTA CHEIA!\n");
        return;
    }
    printf("\nNome: "); scanf("%s",funcionario[armazenamento].nome);
    printf("Código: "); scanf("%d",&funcionario[armazenamento].cod);
    printf("Cargo: "); scanf("%s",funcionario[armazenamento].cargo);
    printf("Carga horária: "); scanf("%d",&folha[armazenamento].horatrab);
    printf("Salário-base: "); scanf("%f",&folha[armazenamento].salBase);
    armazenamento++;
    printf("\nCADASTRO CONFIRMADO!\n");
}

void delFunc() {
    if (armazenamento == 0) {
        printf("\nERRO! LISTA VAZIA!\n");
        return;
    }
    int cod, encontrado = -1;  
    printf("Digite o código do funcionário a ser excluído: "); scanf("%d", &cod);  
    for (int i = 0; i < armazenamento; i++) {
        if (funcionario[i].cod == cod) {
            encontrado = i;  
            break;  
        }
    } if (encontrado == -1) {
        printf("\nERRO: CÓDIGO INEXISTENTE NO CADASTRO!\n");
        return;
    } for (int i = encontrado; i < armazenamento - 1; i++) {
        funcionario[i] = funcionario[i + 1];
        folha[i] = folha[i + 1]; 
    } armazenamento--;
    printf("\nCONFIRMAÇÃO: FUNCIONÁRIO EXCLUÍDO COM SUCESSO!\n");
}

void listarFunc() {
    if (armazenamento == 0) {
        printf("\nERRO! Lista Vazia!\n");
        return;
    } printf("\n---RELATÓRIO DE FUNCIONÁRIOS---\n");
    for(int i = 0; i < armazenamento; i++) {
    printf("\nNome: %s\n",funcionario[i].nome);
    printf("Código: %d\n",funcionario[i].cod);
    printf("Cargo: %s\n",funcionario[i].cargo);
    printf("Carga horária: %d horas por semana\n",folha[i].horatrab);
    printf("Salário-base: R$%.2f\n",folha[i].salBase); 
    } 
}

void folhaTodos() {
    if (armazenamento == 0) {
        printf("\nERRO! Lista Vazia!\n");
        return;
    } printf("\n---FOLHA DE PAGAMENTO DE TODOS OS FUNCIONÁRIOS---\n");
    for(int i = 0; i < armazenamento; i++) {
        float salReceber = (folha[i].salBase + (folha[i].salBase * folha[i].percentGrat)) * (1 - folha[i].percentImposto);
        printf("\nNome: %s ||| ",funcionario[i].nome);
        printf("Código: %d ||| ",funcionario[i].cod);
        printf("Carga horária: %dh\n",folha[i].horatrab);
        printf("Impostos: R$%.2f ||| ",folha[i].salBase*folha[i].percentImposto); 
        printf("Gratificação: R$%.2f\n",folha[i].salBase*folha[i].percentGrat);
        printf("Salário-base: R$%.2f ||| ",folha[i].salBase); 
        printf("Salário a receber: R$%.2f\n\n",salReceber); 
    } 
}

void folhaCargo() {
    if (armazenamento == 0) {
        printf("\nERRO! Lista Vazia!\n");
        return;
    }
    char cargo[50];
    printf("Digite o cargo para listar a folha de pagamento: ");
    scanf("%s", cargo); 
    int existente = 0; 
    for (int i = 0; i < armazenamento; i++) {
        if (strcmp(funcionario[i].cargo, cargo) == 0) {
            existente = 1; 
            float salReceber = (folha[i].salBase + (folha[i].salBase * folha[i].percentGrat)) * (1 - folha[i].percentImposto);
            printf("\n---FOLHA DE PAGAMENTO POR CARGO DE %s---\n", cargo);
            printf("\nNome: %s ||| ", funcionario[i].nome);
            printf("Código: %d ||| ", funcionario[i].cod);
            printf("Carga horária: %dh\n", folha[i].horatrab);
            printf("Impostos: R$%.2f ||| ", folha[i].salBase * folha[i].percentImposto);
            printf("Gratificação: R$%.2f\n", folha[i].salBase * folha[i].percentGrat);
            printf("Salário-base: R$%.2f ||| ", folha[i].salBase);
            printf("Salário a receber: R$%.2f\n", salReceber);
        }
    } if (!existente) {
        printf("Cargo inexistente!\n");
    }
}