#include <stdio.h>
#include "Fila_Estatica.c"

int main()
{
    int numero;
    Fila fila;
    Inicializar(&fila);

    Inserir(&fila, 1);
    Inserir(&fila, 2);
    Inserir(&fila, 3);
    Inserir(&fila, 4);
    Inserir(&fila, 5);

    Imprimir(&fila);

    Remover(&fila, &numero);
    printf("Numero: %d\n", numero);
    Imprimir(&fila);
    Remover(&fila, &numero);
    printf("Numero: %d\n", numero);
    Imprimir(&fila);
    Remover(&fila, &numero);
    printf("Numero: %d\n", numero);
    Imprimir(&fila);
    Remover(&fila, &numero);
    printf("Numero: %d\n", numero);
    Imprimir(&fila);
    Remover(&fila, &numero);
    printf("Numero: %d\n", numero);
    Imprimir(&fila);
    Remover(&fila, &numero);
    printf("Numero: %d\n", numero);
    Imprimir(&fila);


    return 0;
}
