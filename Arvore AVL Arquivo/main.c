#include <stdio.h>
#include <stdlib.h>
#include "arvore.c"

int main()
{
    No* raiz = NULL;

    printf("Reconstruindo árvore do arquivo (se existir)...\n");
    FILE* arquivo = fopen("avl.bin", "rb");
    if (arquivo != NULL)
    {
        raiz = CarregarDoArquivo(arquivo);
        fclose(arquivo);
        printf("Árvore carregada do arquivo:\n");
        printf("Pré-ordem: ");
        PreOrdem(raiz);
        printf("\n\n");
    }
    else
    {
        printf("Arquivo não encontrado. Criando árvore nova...\n\n");
    }

    Inserir(&raiz, 30);
    Inserir(&raiz, 20);
    Inserir(&raiz, 40);
    Inserir(&raiz, 10);
    Inserir(&raiz, 25);
    Inserir(&raiz, 35);
    Inserir(&raiz, 50);

    printf("Após inserções:\n");
    printf("Pré-ordem: ");
    PreOrdem(raiz);
    printf("\nEm ordem: ");
    EmOrdem(raiz);
    printf("\nPós-ordem: ");
    PosOrdem(raiz);
    printf("\n\n");

    Remover(&raiz, 20);
    Remover(&raiz, 30);

    printf("Após remoções:\n");
    printf("Pré-ordem: ");
    PreOrdem(raiz);
    printf("\nEm ordem: ");
    EmOrdem(raiz);
    printf("\nPós-ordem: ");
    PosOrdem(raiz);
    printf("\n");

    return 0;
}
