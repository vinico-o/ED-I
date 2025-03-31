#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string_dinamica.h"

void Criar(Lista* lista)
{
    lista->primElem = NULL;
    lista->ultElem = NULL;
    lista->qntd = 0;
}

void Inserir_Final(Lista* lista, char letra)
{
    No* novo = malloc(sizeof(No));
    if(novo == NULL)
    {
        printf("Erro ao alocar memoria!");
        return;
    }

    novo->elemento = letra;
    novo->prox = NULL;
    lista->qntd ++;

    if(lista->ultElem != NULL)
    {
        lista->ultElem->prox = novo;
    }
    else
    {
        lista->primElem = novo;
    }

    lista->ultElem = novo;

}

void Imprimir(Lista* lista)
{
    No* ptr = lista->primElem;
    while(ptr != NULL)
    {
        printf("%c", ptr->elemento);
        ptr = ptr->prox;
    }

    printf("\n");
}

void Reinicializar(Lista* lista)
{
    No* ptr = lista->primElem;
    while(ptr != NULL)
    {
        No* temp = ptr;
        ptr = ptr->prox;
        free(temp);
    }

    lista->primElem = NULL;
    lista->ultElem = NULL;
    lista->qntd = 0;
}

int Tamanho(Lista* lista)
{
    return lista->qntd;
}

void Copiar(Lista* lista1, Lista* lista2)
{
    No* ptr1 = lista1->primElem;

    while(ptr1 != NULL)
    {
        Inserir_Final(lista2, ptr1->elemento);
        ptr1 = ptr1->prox;
    }
}

void Concatenar(Lista* lista1, Lista* lista2, Lista* lista3)
{
    Copiar(lista1, lista3);
    Copiar(lista2, lista3);
}

void Comparar_Tamanho(Lista *lista1, Lista *lista2)
{
    if(Tamanho(lista1) > Tamanho(lista2))
    {
        printf("Lista 1 > Lista 2\n");
    }
    else if(Tamanho(lista2) > Tamanho(lista1))
    {
        printf("Lista 2 > Lista 1\n");
    }
    else
    {
        printf("Lista 2 = Lista 1\n");
    }
}

bool Comparar_Conteudo(Lista *lista1, Lista *lista2)
{
    No *ptr1 = lista1->primElem;
    No *ptr2 = lista2->primElem;
    if(lista1->qntd != lista2->qntd)
    {
        return false;
    }
    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->elemento != ptr2->elemento)
        {
            return false;
        }

        ptr1 = ptr1->prox;
        ptr2 = ptr2->prox;
    }

    return true;
}

void Remover_Trecho(Lista* lista1, int start, int numero)
{

    No *ptr = lista1->primElem;
    No *ant = NULL;

    for(int i = 0; i < start && ptr != NULL; i++)
    {
        ant = ptr;
        ptr = ptr->prox;
    }

    for(int i = 0; i < numero && ptr != NULL; i++)
    {
        No *temp = ptr;
        ptr = ptr->prox;
        free(temp);
        lista1->qntd--;
    }

    if(ant != NULL)
    {
        ant->prox = ptr;
    }
    else
    {
        lista1->primElem = ptr;
    }

    if(ptr == NULL)
    {
        lista1->primElem = ant;
    }

}

void Inserir_Substring(Lista* lista1, Lista* subs, int start)
{
    if(start >= lista1->qntd)
    {
        Concatenar(lista1, subs, lista1);
    }
    else
    {
        No *ptr = lista1->primElem;
        No *ant = NULL;

        for(int i = 0; i < start && ptr != NULL; i++)
        {
            ant = ptr;
            ptr = ptr->prox;
        }

        No *ptrsubs = subs->primElem;
        while(ptrsubs != NULL)
        {
            No *novo = malloc(sizeof(No));
            if(novo == NULL)
            {
                printf("Erro ao alocar na memoria!\n");
            }
            novo->elemento = ptrsubs->elemento;
            novo->prox = ptr;

            if (ant != NULL)
            {
                ant->prox = novo;
            }
            else
            {
                lista1->primElem = novo;
            }

            ant = novo;
            ptrsubs = ptrsubs->prox;
            lista1->qntd++;
        }
    }
}

int Busca_Posicao(Lista* lista1, Lista* lista2)
{
    No *ptr1 = lista1->primElem;
    int cont = 0;

    while(ptr1 != NULL)
    {
        No *temp = ptr1;
        No *ptr2 = lista2->primElem;

        while(temp != NULL && ptr2 != NULL && temp->elemento == ptr2->elemento)
        {
            temp = temp->prox;
            ptr2 = ptr2->prox;
        }

        if(ptr2 == NULL)
        {
            return cont;
        }

        ptr1 = ptr1->prox;
        cont++;
    }

    return 0;
}
