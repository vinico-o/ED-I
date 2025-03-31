#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SimulacaoFila.c"

#define TEMPO_MAX 4


int main ()
{
    srand(time(0));

    int tempo = 720, atual = 0;
    int chegada = rand() % TEMPO_MAX + 1;
    int saida = rand() % 8 + 4;
    int n_cliente = 0;

    Fila fila;
    Inicializar(&fila);

    while(atual < tempo)
    {
        if(chegada == atual)
        {
            Enfileirar(&fila, ++n_cliente);
            chegada += rand() % TEMPO_MAX + 1;
        }

        if(saida == atual)
        {
            Desenfileirar(&fila);
            saida += rand() % TEMPO_MAX + 1;
        }

        Imprimir(&fila);

        printf("\ntempo: %d\n", atual);
        atual++;
    }

    return 0;
}