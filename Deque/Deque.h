#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
   int elemento;
   struct No* prox;
   struct No* ant;
}No;

typedef struct 
{
    int qntd;
    No* inicio;
    No* fim;
}Deque;

void Inicializar(Deque* deque);
void Reinicializar(Deque* deque);
bool Vazio(Deque* deque);
void Imprimir(Deque* deque);
void InserirInicio(Deque* deque, int elemento);
void InserirFinal(Deque* deque, int elemento);
void RemoverInicio(Deque* deque, int* elemento);
void RemoverFinal(Deque* deque, int* elemento);