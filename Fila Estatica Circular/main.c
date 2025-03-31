#include <stdio.h>
#include <stdlib.h>
#include "Fila_Estatica_circular.c"

int main()
{
    int removido;
    Fila fila;
    Inicializar(&fila);

    Inserir(&fila, 1);
    Inserir(&fila, 2);
    Inserir(&fila, 3);
    Inserir(&fila, 4);
    Inserir(&fila, 5);
    Inserir(&fila, 6);

    Imprimir(&fila);

    Remover(&fila, &removido);

    Imprimir(&fila);

    Remover(&fila, &removido);

    Imprimir(&fila);

    Inserir(&fila, 1);
    Inserir(&fila, 2);

    Imprimir(&fila);


    return 0;
}
