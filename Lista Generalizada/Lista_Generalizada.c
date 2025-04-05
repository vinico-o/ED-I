#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Lista_Generalizada.h"

//tipo 0 = int
//tipo 1 = sublista

void Inicializar(Lista* lista)
{
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->qntd = 0;
}

void Reinicializar(Lista* lista)
{
    No* ptr = lista->ultimo;

    while(ptr != NULL)
    {
        No* temp = ptr;
        ptr = ptr->ant;

        if(ptr->tipo == 1)
        {
            Reinicializar(ptr->Elemento.sublista);
            free(ptr->Elemento.sublista);
        }

        free(temp);
    }

    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->qntd = 0;
}

bool Vazia(Lista* lista)
{
    if(lista->primeiro == NULL)
    {
        return true;
    }

    return false;
}

void Inserir_Atomo_Final(Lista* lista, int elemento)
{
    No* novo = malloc(sizeof(No));

    if(novo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->prox = NULL;
    novo->ant = NULL;
    novo->tipo = 0;
    novo->Elemento.numero = elemento;

    if(Vazia(lista))
    {
        lista->primeiro = novo;
        lista->ultimo = novo;
    }
    else
    {
        novo->ant = lista->ultimo;
        lista->ultimo->prox = novo;
        lista->ultimo = novo;
    }

    lista->qntd++;
}

void Inserir_Sublista_Final(Lista*  lista, Lista* sublista)
{
    No* novo = malloc(sizeof(No));

    if(novo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->prox = NULL;
    novo->ant = NULL;
    novo->tipo = 1;
    novo->Elemento.sublista = sublista;

    if(Vazia(lista))
    {
        lista->primeiro = novo;
        lista->ultimo = novo;
    }
    else
    {
        novo->ant = lista->ultimo;
        lista->ultimo->prox = novo;
        lista->ultimo = novo;
    }

    lista->qntd++;

}

void Imprimir_Lista(Lista* lista)
{
    No* ptr = lista->primeiro;
    printf("[");
    while(ptr != NULL)
    {
        if(ptr->tipo == 0)
        {
            printf("%d", ptr->Elemento.numero);
        }
        else
        {
            Imprimir_Lista(ptr->Elemento.sublista);
        }

        if(ptr->prox != NULL)
        {
            printf(", ");
        }

        ptr = ptr->prox;
    }
    printf("]");
}

void Remover_Final(Lista* lista)
{

    if(Vazia(lista))
    {
        printf("Lista Vazia! Impossivel remover!\n");
        return;
    }

    No* temp = lista->ultimo;

    if(lista->qntd == 1)
    {
        lista->primeiro = NULL;
        lista->ultimo = NULL;
    }
    else
    {
        No* ptr = lista->ultimo->ant;
        ptr->prox = NULL;
        temp->ant = NULL;
        lista->ultimo = ptr;
    }

    free(temp);
    lista->qntd--;

}

bool Buscar_Numero(Lista* lista, int chave)
{
    if(Vazia(lista))
    {
        return false;
    }

    No* ptr = lista->primeiro;

    while(ptr != NULL)
    {
        if(ptr->tipo == 0)
        {
            if(ptr->Elemento.numero == chave)
            {
                return true;
            }
        }
        else
        {
            if(Buscar_Numero(ptr->Elemento.sublista, chave))
            {
                return true;
            }
        }

        ptr = ptr->prox;
    }

    return false;
    
}

bool Comparar_Listas(Lista *lista1, Lista* lista2)
{
    No* ptr1 = lista1->primeiro;
    No* ptr2 = lista2->primeiro;

    if(lista1->qntd != lista2->qntd)
    {
        return false;
    }

    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->tipo != ptr2->tipo)
        {
            return false;
        }
        else
        {
            if(ptr1->tipo == 0)
            {
                if(ptr1->Elemento.numero != ptr2->Elemento.numero)
                {
                    return false;
                }
            }
            else
            {
                if(!Comparar_Listas(ptr1->Elemento.sublista, ptr2->Elemento.sublista))
                {
                    return false;
                }
            }
        }

        ptr1 = ptr1->prox;
        ptr2 = ptr2->prox;
    }

    return true;
}

int Tamanho_Principal(Lista* lista)
{
    return lista->qntd;
}

int Tamanho_Total(Lista* lista)
{
    int qntd = 0;
    No* ptr = lista->primeiro;

    while(ptr != NULL)
    {
        if(ptr->tipo == 0)
        {
            qntd++;
        }
        else
        {
            qntd += Tamanho_Total(ptr->Elemento.sublista);
        }

        ptr = ptr->prox;
    }

    return qntd;
}