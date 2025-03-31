#include <stdio.h>
#include <stdlib.h>
#include "Fila_Dinamica.c"

int main()
{
    int removido;
    Fila fila;
    Inicializar(&fila);

    Inserir(&fila, 1);
    Inserir(&fila, 2);
    Inserir(&fila, 3);
    Inserir(&fila, 4);
    Imprimir(&fila);
    Remover(&fila, &removido);
    Imprimir(&fila);
    Remover(&fila, &removido);
    Imprimir(&fila);
    Remover(&fila, &removido);
    Imprimir(&fila);
    Remover(&fila, &removido);
    Imprimir(&fila);
    Remover(&fila, &removido);

    return 0;
}
