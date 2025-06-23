#include <stdio.h>

typedef struct No
{
    int elemento;
    struct No* direita;
    struct No* esquerda;
} No;

void InicializarArvore(No** raiz);
No* CriarNo(int elemento);
void Inserir(No** raiz, int elemento);
void Remover(No** raiz, int elemento);
void PreOrdem(No* raiz);
void EmOrdem(No* raiz);
void PosOrdem(No* raiz);
int Altura(No* raiz);
int CalcularFatorBalanceamento(No* raiz);
void RotacaoEsquerda(No** raiz);
void RotacaoDireita(No** raiz);
void SalvarEmArquivo(No* raiz, FILE* arquivo);
void AtualizarArquivo(No* raiz);
No* CarregarDoArquivo(FILE* arquivo);