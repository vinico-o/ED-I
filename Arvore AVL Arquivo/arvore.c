#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void InicializarArvore(No** raiz)
{
    (*raiz) = NULL;
}

No* CriarNo(int elemento)
{
    No* novo = malloc(sizeof(No));
    if(novo == NULL)
    {
        return NULL;
    }

    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->elemento = elemento;

    return novo;
}

int Altura(No* raiz)
{
    if(raiz == NULL)
    {
        return -1;
    }

    int direita = Altura(raiz->direita);
    int esquerda = Altura(raiz->esquerda);

    if(direita > esquerda)
    {
        return direita + 1;
    }
    else
    {
        return esquerda + 1;
    }

}

int CalcularFatorBalanceamento(No* raiz)
{
    int fatorBalanceamento = Altura(raiz->esquerda) - Altura(raiz->direita);
    return fatorBalanceamento;
}

void PreOrdem(No* raiz)
{
    if(raiz != NULL)
    {
        printf("%d ", raiz->elemento);
        PreOrdem(raiz->esquerda);
        PreOrdem(raiz->direita);
    }
}

void EmOrdem(No* raiz)
{
    if(raiz != NULL)
    {
        EmOrdem(raiz->esquerda);
        printf("%d ", raiz->elemento);
        EmOrdem(raiz->direita);
    }
}

void PosOrdem(No* raiz)
{
    if(raiz != NULL)
    {
        PosOrdem(raiz->esquerda);
        printf("%d ", raiz->elemento);
        PosOrdem(raiz->direita);
    }
}

void RotacaoEsquerda(No** raiz)
{ 
    No* aux = (*raiz)->direita;
    (*raiz)->direita = aux->esquerda;
    aux->esquerda = (*raiz);
    *raiz = aux;
}

void RotacaoDireita(No** raiz)
{ 
    No* aux = (*raiz)->esquerda;
    (*raiz)->esquerda = aux->direita;
    aux->direita = (*raiz);
    *raiz = aux;
}

void Inserir(No** raiz, int elemento)
{
    //Arvore nula
    if((*raiz) == NULL)
    {
        No* novo = CriarNo(elemento);
        if(novo == NULL)
        {
            printf("Erro ao alocar na memoria!");
            return;
        }

        *raiz = novo;
        return;
    }
    else
    {
        //Caminha ate o no folha
        if(elemento > (*raiz)->elemento)
        {
            Inserir(&((*raiz)->direita), elemento);
        }
        else if(elemento < (*raiz)->elemento)
        {
            Inserir(&((*raiz)->esquerda), elemento);
        }
        else
        {
            printf("O no ja existe!\n");
            return;
        }

        //Balanceamento
        int fatorBalanceamento = CalcularFatorBalanceamento(*raiz);

        //Arvore desbalanceada para a direita
        if(fatorBalanceamento >= 2)
        {
            //Fator de Balanceamento com o mesmo sinal do pai
            if(CalcularFatorBalanceamento((*raiz)->direita) > 0) 
            {
                RotacaoEsquerda(&(*raiz));
            }
            //Fator de Balanceamento diferente do sinal do pai
            else
            {
                RotacaoDireita(&(*raiz)->direita);
                RotacaoEsquerda(&(*raiz));
            }
        }
        //Arvore desbalanceada para a esquerda
        else if(fatorBalanceamento <= -2)
        {
            //Fator de Balanceamento com o mesmo sinal do pai
            if(CalcularFatorBalanceamento((*raiz)->esquerda) < 0)
            {
                RotacaoDireita(&(*raiz));
            }
            //Fator de Balanceamento diferente do sinal do pai
            else
            {
                RotacaoEsquerda(&(*raiz)->esquerda);
                RotacaoDireita(&(*raiz));
            }
        }

    }

    AtualizarArquivo(*raiz);
}

No* MaiorDosMenores(No* raiz)
{
    No* aux = raiz->esquerda;
    while(aux->direita != NULL)
    {
        aux = aux->direita;
    }

    return aux;
}

void Remover(No** raiz, int elemento)
{
    if((*raiz) == NULL)
    {
        printf("Impossivel remover de Arvore Vazia");
        return;
    }

    if(elemento > (*raiz)->elemento)
    {
        Remover(&(*raiz)->direita, elemento);
    }
    else if(elemento < (*raiz)->elemento)
    {
        Remover(&((*raiz)->esquerda), elemento);
    }
    else //encontramos o no a ser removido
    {
        //Balanceamento caso a remocao gere desbalanceamento
        if(CalcularFatorBalanceamento((*raiz)) >= 2)
        {
            if(CalcularFatorBalanceamento((*raiz)->direita) > 0)
            {
                RotacaoEsquerda(&(*raiz));
            }
            else
            {
                RotacaoDireita(&(*raiz)->direita);
                RotacaoEsquerda(&(*raiz));
            }
        }
        else if(CalcularFatorBalanceamento((*raiz)) <= -2)
        {
            if(CalcularFatorBalanceamento((*raiz)->esquerda) < 0)
            {
                RotacaoDireita(&(*raiz));
            }
            else
            {
                RotacaoEsquerda(&((*raiz)->esquerda));
                RotacaoDireita(&(*raiz));
            }
        }

        //Elemento encoontrado
        if((*raiz)->elemento == elemento)
        {
            No* aux;
            //Se o no possuir duas subarvores
            if((*raiz)->direita != NULL && (*raiz)->esquerda != NULL)
            {
                aux = MaiorDosMenores((*raiz));
                (*raiz)->elemento = aux->elemento;
                Remover(&(*raiz)->esquerda, aux->elemento);
            }
            //Nso ha uma subarvore ou ha em algum dos lados
            else
            {
                aux = *raiz;
                if((*raiz)->esquerda == NULL)
                {
                    *raiz = (*raiz)->direita;
                }
                else if((*raiz)->direita == NULL)
                {
                    *raiz = (*raiz)->esquerda;
                }
                
                free(aux);
            }

        }
    }

    AtualizarArquivo(*raiz);
}

void SalvarEmArquivo(No* raiz, FILE* arquivo)
{
    if(raiz == NULL)
    {
        int nulo = -1; //marcacao para nos nulos
        fwrite(&nulo, sizeof(int), 1, arquivo);
        return;
    }
    else
    {
        fwrite(&(raiz->elemento), sizeof(int), 1, arquivo);
        SalvarEmArquivo(raiz->esquerda, arquivo);
        SalvarEmArquivo(raiz->direita, arquivo);
    }
}

void AtualizarArquivo(No* raiz)
{   
    FILE* arquivo = fopen("avl.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    SalvarEmArquivo(raiz, arquivo);
    fclose(arquivo);
}

// Função para carregar árvore de arquivo binário
No* CarregarDoArquivo(FILE* arquivo)
{
    int valor;
    if(fread(&valor, sizeof(int), 1, arquivo) != 1)
    {
        return NULL;
    }

    //se houver o marcador -1, o no eh nulo
    if(valor == -1)
    {
        return NULL;
    }

    No* novo = CriarNo(valor);
    novo->esquerda = CarregarDoArquivo(arquivo);
    novo->direita = CarregarDoArquivo(arquivo);
    return novo;
}