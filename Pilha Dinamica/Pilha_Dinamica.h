#include <stdio.h>

typedef struct
{
    int elemento;
    struct No* prox;
}No;

typedef struct
{
    No *topo;
    int qntd;
}Pilha;

void Inicializar(Pilha* pilha);
bool Vazia(Pilha* pilha);
void Imprimir(Pilha* pilha);
void Empilhar(Pilha* pilha, int elemento);
int Desempilhar(Pilha* pilha);
void Reinicializar(Pilha* pilha);
