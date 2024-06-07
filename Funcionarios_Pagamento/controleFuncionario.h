#ifndef CONTROLEFUNCIONARIO_H
#define CONTROLEFUNCIONARIO_H

#define MAX_ARRAY 10

struct Funcionario {
    int cod;
    char nome[50];
    char cargo[20];
};
struct Folha {
    int horatrab;
    float percentImposto=0.08;
    float percentGrat=0.06;
    float salBase;
    float salReceber;
};

extern struct Funcionario funcionario[MAX_ARRAY];
extern struct Folha folha[MAX_ARRAY];
extern int armazenamento;

void addFunc();
void delFunc();
void listarFunc();
void folhaTodos();
void folhaCargo();
#endif