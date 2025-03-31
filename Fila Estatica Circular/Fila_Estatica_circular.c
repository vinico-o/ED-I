#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Fila_Estatica_circular.h"

void Inicializar(Fila *fila)
{
    fila->fim = 0;
    fila->inicio = 0;
}

void Imprimir(Fila *fila)
{
    if(Vazia(fila))
    {
        printf("inicio fim/n");
        return;
    }

    int i = fila->inicio;
    printf("inicio ");
    while(i != fila->fim)
    {
        printf("%d ", fila->vFila[i]);
        i = (i + 1) % MAX;
    }

    printf("fim\n");
}

bool Cheia(Fila *fila)
{
    if((fila->fim + 1) % MAX == fila->inicio)
    {
        return true;
    }

    return false;
}

bool Vazia(Fila *fila)
{
    if(fila->fim == fila->inicio)
    {
        return true;
    }

    return false;
}

void Inserir(Fila *fila, int elemento)
{
    if(Cheia(fila))
    {
        printf("Fila Cheia!\n");
        return;
    }

    fila->vFila[fila->fim] = elemento;
    fila->fim = (fila->fim + 1) % MAX;
}

void Remover(Fila *fila, int *elemento)
{
    if(Vazia(fila))
    {
        printf("Fila Vazia!\n");
        return;
    }

    *elemento = fila->vFila[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX;
}
