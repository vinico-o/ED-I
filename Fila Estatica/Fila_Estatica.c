#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Fila_Estatica.h"

void Inicializar(Fila* fila)
{
    fila->inicio = 0;
    fila->fim = 0;
    fila->qntd = 0;
}

void Imprimir(Fila* fila)
{
    printf("inicio ");

    for(int i = fila->inicio; i < fila->fim; i++)
    {
        printf("%d ", fila->vFila[i]);
    }

    printf("fim \n");
}

bool Cheia(Fila* fila)
{
    if(fila->fim > MAX)
    {
        return true;
    }

    return false;
}

bool Vazia(Fila* fila)
{
    if(fila->qntd == 0)
    {
        return true;
    }

    return false;
}

void Inserir(Fila* fila, int elemento)
{
    if(Cheia(fila))
    {
        printf("Fila Cheia!\n");
        return;
    }

    fila->vFila[fila->fim] = elemento;
    fila->qntd++;
    fila->fim++;
}

void Remover(Fila *fila, int *elemento)
{
    if(Vazia(fila))
    {
        printf("Fila Vazia!\n");
        return;
    }

    *elemento = fila->vFila[fila->inicio];
    fila->inicio++;
    fila->qntd--;
}
