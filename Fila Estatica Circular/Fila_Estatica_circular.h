#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef struct
{
    int vFila[MAX];
    int fim;
    int inicio;
}Fila;

void Inicializar(Fila *fila);
void Imprimir(Fila *fila);
bool Cheia(Fila *fila);
bool Vazia(Fila *fila);
void Inserir(Fila *fila, int elemento);
void Remover(Fila *fila, int *elemento);
