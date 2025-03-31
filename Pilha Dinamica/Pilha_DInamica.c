#include <stdio.h>
#include <stdbool.h>
#include "Pilha_Dinamica.h"

void Inicializar(Pilha *pilha)
{
    pilha->topo = NULL;
    pilha->qntd = 0;
}

bool Vazia(Pilha *pilha)
{
    if(pilha->qntd == 0)
        return true;

    return false;
}

void Imprimir(Pilha* pilha)
{
    if(Vazia(pilha))
    {
        printf("Pilha vazia!\n");
        return;
    }
    No* ptr = pilha->topo;
    while(ptr != NULL)
    {
        printf("%d ", ptr->elemento);
        ptr = ptr->prox;
    }

    printf("\n");
}

void Empilhar(Pilha *pilha, int numero)
{
    No *novo;
    novo = malloc(sizeof(No));
    if(novo == NULL)
    {
        printf("Erro ao alocar na memoria!\n");
        return;
    }

    novo->elemento = numero;
    novo->prox = NULL;
    pilha->qntd++;

    if(Vazia(pilha))
    {
        pilha->topo = novo;
    }
    else
    {
        No *temp;
        temp = pilha->topo;
        pilha->topo = novo;
        novo->prox = temp;
    }
}

int Desempilhar(Pilha *pilha)
{
    int elemento;

    if(Vazia(pilha))
    {
        printf("Pilha vazia! Impossivel desempilhar!\n");
        return;
    }

    elemento = pilha->topo->elemento;
    pilha->qntd--;

    No* temp;
    temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    temp->prox = NULL;
    free(temp);

    return elemento;
}

void Reinicializar(Pilha* pilha)
{
    No* temp;
    No* ptr = pilha->topo;

    while(ptr != NULL)
    {
        pilha->qntd--;
        temp = ptr;
        ptr = ptr->prox;
        free(temp);
    }

    pilha->topo = NULL;
}
