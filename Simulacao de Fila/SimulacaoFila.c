#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SimulacaoFila.h"

void Inicializar(Fila* fila)
{
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->qntd = 0;
}

void Imprimir(Fila *fila)
{
    No *ptr;
    ptr = fila->primeiro;

    while(ptr != NULL)
    {
        printf("%d ", ptr->elemento);
        ptr = ptr->prox;
    }
    printf("\n");
}

bool Vazia(Fila* fila)
{
    if(fila->qntd == 0)
    {
        return true;
    }

    return false;
}

void Enfileirar(Fila* fila, int n_cliente)
{
    No* novo;
    novo = malloc(sizeof(No));

    if(novo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->prox = NULL;
    novo->elemento = n_cliente;

    if(fila->ultimo == NULL)
    {
        fila->primeiro = novo;
        fila->ultimo = novo;
    }
    else
    {
        fila->ultimo->prox = novo;
        fila->ultimo = novo;
    }

    fila->qntd++;
}

void Desenfileirar(Fila *fila)
{
    if(Vazia(fila))
    {
        printf("Fila Vazia!\n");
        return;
    }

    No *temp;
    temp = fila->primeiro;

    fila->primeiro = fila->primeiro->prox;
    if(fila->primeiro == NULL)
    {
        fila->ultimo = NULL;
    }
    free(temp);
    fila->qntd--;
}