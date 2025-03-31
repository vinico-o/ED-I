#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PIlha_Estatica.h"

void Inicializar(Pilha *pilha)
{
    pilha->topo = 0;
}

void Imprimir(Pilha *pilha)
{
    if(Vazia(pilha))
    {
        printf("Pilha Vazia!\n");
        return;
    }

    printf("Pilha atual:\n");
    for(int i = 0; i < pilha->topo; i++)
    {
        printf("%d ", pilha->vPilha[i]);
    }

    printf("\n");
}

bool Vazia(Pilha *pilha)
{
    if(pilha->topo == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Cheia(Pilha *pilha)
{
    if(pilha->topo == MAX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Push(Pilha *pilha, int elemento)
{
    if(Cheia(pilha))
    {
        printf("Pilha Cheia!\n");
        return;
    }
    else
    {
        pilha->vPilha[pilha->topo] = elemento;
        pilha->topo++;
    }
}

void Pop(Pilha* pilha, int* elemento)
{
    if(Vazia(pilha))
    {
        printf("Pilha Vazia!\n");
    }
    else
    {
        pilha->topo--;
        *elemento = pilha->vPilha[pilha->topo];
    }
}
