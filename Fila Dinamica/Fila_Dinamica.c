#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Fila_Dinamica.h"

void Inicializar(Fila* fila)
{
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->qntd = 0;
}

bool Vazia(Fila* fila)
{
    if(fila->qntd == 0)
    {
        return true;
    }
    return false;
}

void Inserir(Fila *fila, int elemento)
{
    No* novo;
    novo = malloc(sizeof(No));

    if(novo == NULL)
    {
        printf("Erro ao alocar na memoria!\n");
        return;
    }

    novo->prox = NULL;
    novo->elemento = elemento;

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

void Remover(Fila *fila, int *elemento)
{
    if(Vazia(fila))
    {
        printf("Fila Vazia!\n");
        return;
    }

    No *temp;
    temp = fila->primeiro;

    *elemento = temp->elemento;
    fila->primeiro = fila->primeiro->prox;
    if(fila->primeiro == NULL)
    {
        fila->ultimo = NULL;
    }
    free(temp);
    fila->qntd--;
}

