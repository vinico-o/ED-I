#include <stdio.h>
#include <stdlib.h>
#include "PIlha_Estatica.c"

int main ()
{
    Pilha pilha;
    int numero;
    Inicializar(&pilha);

    printf("%d \n", Vazia(&pilha));
    printf("%d \n", Cheia(&pilha));

    Push(&pilha, 1);
    Imprimir(&pilha);
    Push(&pilha, 10);
    Imprimir(&pilha);
    Push(&pilha, 100);
    Imprimir(&pilha);
    Push(&pilha, 1000);
    Imprimir(&pilha);

    Pop(&pilha, &numero);
    printf("Numero resgatado: %d\n", numero);
    Imprimir(&pilha);
    Pop(&pilha, &numero);
    printf("Numero resgatado: %d\n", numero);
    Imprimir(&pilha);
    Pop(&pilha, &numero);
    printf("Numero resgatado: %d\n", numero);
    Imprimir(&pilha);
    Pop(&pilha, &numero);
    printf("Numero resgatado: %d\n", numero);
    Imprimir(&pilha);

}
