#include <stdio.h>
#include "Pilha_Dinamica.c"

int main()
{
    Pilha pilha;
    Inicializar(&pilha);
    int numero;

    Empilhar(&pilha, 1);
    Imprimir(&pilha);
    Empilhar(&pilha, 2);
    Imprimir(&pilha);
    Empilhar(&pilha, 3);
    Imprimir(&pilha);

    numero = Desempilhar(&pilha);
    printf("Numero: %d\n", numero);
    Imprimir(&pilha);

    numero = Desempilhar(&pilha);
    printf("Numero: %d\n", numero);
    Imprimir(&pilha);

    numero = Desempilhar(&pilha);
    printf("Numero: %d\n", numero);
    Imprimir(&pilha);

    numero = Desempilhar(&pilha);
    printf("Numero: %d\n", numero);
    Imprimir(&pilha);

    Empilhar(&pilha, 1);
    Imprimir(&pilha);
    Empilhar(&pilha, 2);
    Imprimir(&pilha);
    Empilhar(&pilha, 3);
    Imprimir(&pilha);

    Reinicializar(&pilha);
    Imprimir(&pilha);

    return 0;
}
