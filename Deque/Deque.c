#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Deque.h"

void Inicializar(Deque* deque)
{
    deque->fim = NULL;
    deque->inicio = NULL;
    deque->qntd = 0;
}

void Reinicializar(Deque* deque)
{
    while(deque->qntd != 0)
    {
        No* temp;
        temp = deque->inicio;
        deque->inicio = deque->inicio->prox;
        free(temp);
        deque->qntd--;
    }

    deque->inicio = NULL;
    deque->fim = NULL;
}

bool Vazio(Deque* deque)
{
    if(deque->qntd == 0)
    {
        return true;
    }

    return false;
}

void Imprimir(Deque* deque)
{
    No* ptr;
    ptr = deque->inicio;

    printf("inicio ");
    while(ptr != NULL)
    {
        printf("%d ", ptr->elemento);
        ptr = ptr->prox;
    }
    printf("fim\n");
}

void InserirInicio(Deque* deque, int elemento)
{
    No* novo;
    novo = malloc(sizeof(No));

    if(novo == NULL)
    {
        printf("Erro ao alocar na memoria!\n");
        return;
    }

    if(Vazio(deque))
    {
        novo->prox = NULL;
        novo->ant = NULL;
        deque->fim = novo;
        deque->inicio = novo;
    }
    else
    {
        novo->prox = deque->inicio;
        deque->inicio->ant = novo;
        deque->inicio = novo;
        novo->ant = NULL;
    }

    novo->elemento = elemento;
    deque->qntd++;

}

void InserirFinal(Deque* deque, int elemento)
{
    No* novo;
    novo = malloc(sizeof(No));

    if(novo == NULL)
    {
        printf("Erro ao alocar na memoria!\n");
        return;
    }

    if(Vazio(deque))
    {
        novo->prox = NULL;
        novo->ant = NULL;
        deque->fim = novo;
        deque->inicio = novo;
    }
    else
    {
        novo->ant = deque->fim;
        deque->fim->prox = novo;
        deque->fim = novo;
        novo->prox = NULL;
    }

    novo->elemento = elemento;
    deque->qntd++;

}

void RemoverInicio(Deque* deque, int* elemento)
{
    if(Vazio(deque))
    {
        printf("Deque Vazio!\n");
        return;
    }

    No* temp;
    temp = deque->inicio;
    *elemento = temp->elemento;

    if(deque->qntd == 1)
    {
        deque->inicio = NULL;
        deque->fim = NULL;
    }
    else
    {
        deque->inicio = deque->inicio->prox;
        deque->inicio->ant = NULL;
        temp->prox = NULL;
    }

    free(temp);
    deque->qntd--;
}

void RemoverFinal(Deque* deque, int* elemento)
{
    if(Vazio(deque))
    {
        printf("Deque Vazio!\n");
        return;
    }

    No* temp;
    temp = deque->fim;
    *elemento = temp->elemento;

    if(deque->qntd == 1)
    {
        deque->inicio = NULL;
        deque->fim = NULL;
    }
    else
    {
        deque->fim = deque->fim->ant;
        deque->fim->prox = NULL;
        temp->ant = NULL;
    }

    free(temp);
    deque->qntd--;
}