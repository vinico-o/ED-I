#include <stdio.h>
#include <stdlib.h>
#include "ContaBancaria.c"

int main ()
{
    ContaBancaria conta1;
    Inicializar_Conta(&conta1, 100, 3200.0);
    printf("Conta antes da movimentacao: \n");
    Imprimir_Conta(&conta1);

    Depositar_Conta(&conta1, 1000.0);
    Imprimir_Conta(&conta1);

    Sacar_Conta(&conta1, 2000.0);
    Imprimir_Conta(&conta1);
}
