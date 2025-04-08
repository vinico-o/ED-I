#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Lista_Cruzada.h"

void Inicializar_Matriz(Matriz* matriz)
{
    for(int i = 0; i < LINHA; i++)
    {
        matriz->linha[i] = NULL;
    }

    for(int j = 0; j < COLUNA; j++)
    {
        matriz->coluna[j] = NULL;
    }
}

void Inserir(Matriz* matriz, int linha, int coluna, int elemento)
{
    No* novo;
    novo = malloc(sizeof(No));

    No *ant = NULL;
    No *ptrColuna = matriz->coluna[coluna];
    No *ptrLinha = matriz->linha[linha];

    novo->baixo = NULL;
    novo->direita = NULL;
    novo->numero = elemento;
    novo->linha = linha;
    novo->coluna = coluna;

    if(ptrLinha == NULL)
    {
        matriz->linha[linha] = novo;
    }
    else
    {
        //marcação das posições anterior e atual de inserção
        while(ptrLinha != NULL && ptrLinha->coluna < coluna)
        {
            ant = ptrLinha;
            ptrLinha = ptrLinha->direita;
        }

        if(ptrLinha != NULL)
        {
            if(ptrColuna->linha == linha)
            {
                printf("Elemento ja existente nessa Coluna!\n");
                return;
            }
            //inserção no inicio, já que ant é nulo
            if(ant == NULL)
            {
                matriz->linha[linha] = novo;
                novo->direita = ptrLinha;
            }
            //inserção no meio
            else
            {
                ant->direita = novo;
                novo->direita = ptrLinha;
            }
        }
        //inserção no final
        else
        {
            ant->direita = novo;
        }

    }

    if(ptrColuna == NULL)
    {
        matriz->coluna[coluna] = novo;
    }
    else
    {
        //posicionando os ponteiros
        while(ptrColuna != NULL && ptrColuna->linha < linha)
        {
            ant = ptrColuna;
            ptrColuna = ptrColuna->baixo;
        }

        if(ptrColuna != NULL)
        {
            if(ptrLinha->coluna == coluna)
            {
                printf("Elemento já existente nessa Linha!");
                free(novo);
                return;
            }

            if(ant == NULL)
            {
                matriz->coluna[coluna] = novo;
                novo->baixo = ptrColuna;
            }
            else
            {
                ant->baixo = novo;
                novo->baixo = ptrColuna;
            }
        }
        else
        {
            ant->baixo = novo;
        }
    }
}

void Remover(Matriz* matriz, int linha, int coluna)
{
    No* ptrLinha = matriz->linha[linha]; //utilizado para ajustar os ponteiros
    No* ptrColuna = matriz->coluna[coluna]; //utilizado para ajustar os ponteiros
    No* temp; //utilizado para marcar o elemento e dar free depois
    No* ant = NULL; //utilizado para ajustar os ponteiros

    //posicionando os ponteiros
    while(ptrLinha != NULL && ptrLinha->coluna < coluna)
    {
        ant = ptrLinha;
        ptrLinha = ptrLinha->direita;
    }
    
    if(ant == NULL && ptrLinha == NULL)
    {
        printf("Nao existe elemento para remover!\n");
        return;
    }

    //se estiver no inicio da lista
    if(ant == NULL)
    {
        matriz->linha[linha] = ptrLinha->direita;
    }
    else //se estiver no meio ou no fim
    {
        ant->direita = ptrLinha->direita; //ajustando o ponteiro para o proximo do atual
        ptrLinha->direita = NULL; //removendo o ponteiro do atual
    }

    ant = NULL; //"resetando ant"

    while(ptrColuna != NULL && ptrColuna->linha < linha)
    {
        ant = ptrColuna;
        ptrColuna = ptrColuna->baixo;
    }

    if(ant == NULL && ptrColuna == NULL)
    {
        printf("Nao existe elemento para remover!\n");
        return;
    }

    //se estiver no inicio da lista
    if(ant == NULL)
    {
        matriz->coluna[coluna] = ptrColuna->baixo;
    }
    else //se estiver no meio ou no fim
    {
        ant->baixo = ptrColuna->baixo; //ajustando o ponteiro para o proximo do atual
        ptrColuna->baixo = NULL; //removendo o ponteiro do atual

        temp = ptrColuna;
    }

    free(temp);
}

void Imprimir(Matriz *matriz)
{
    No* ptr;
    ptr = matriz->linha[0];//posicionando na primeira linha

    for(int i = 0; i < LINHA; i++)
    {
        ptr = matriz->linha[i]; //passando o ponteiro para proxima linha

        for(int j = 0; j < COLUNA; j++) //iterando j para comparar com a coluna do elemento
        {
            if(ptr != NULL && ptr->coluna == j)//se houver alguem na coluna e coincidir j com a coluna do elemento
            {
                printf("%d ", ptr->numero); //imprimimos o elemento
                ptr = ptr->direita; //passanos para o proximo
            }
            else
            {
                printf("%d ", 0); //se as colunas nao coincidirem, nao ha ninguem, entao imprimimos 0
            }
        }
        printf("\n");
    }

    printf("\n");
}

void Somar_Linha(Matriz* matriz, int linha, int constante)
{
    No* ptr;
    ptr = matriz->linha[linha];

    while(ptr != NULL)
    {
        ptr->numero += constante;
        ptr = ptr->direita;
    }
}