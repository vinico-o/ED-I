#include <stdio.h>
#include <stdlib.h>
#include "Lista_Generalizada.c"

int main ()
{
    Lista lista, lista2, sublista;
    int encontrado, iguais;
    
    Inicializar(&lista);
    Inicializar(&lista2);
    Inicializar(&sublista);

    Inserir_Atomo_Final(&lista, 1);
    Inserir_Atomo_Final(&lista, 2);
    Inserir_Atomo_Final(&lista2, 1);
    Inserir_Atomo_Final(&lista2, 2);
    Imprimir_Lista(&lista);
    printf("\n");

    Inserir_Atomo_Final(&sublista, 4);
    Inserir_Atomo_Final(&sublista, 5);
    Inserir_Atomo_Final(&sublista, 6);
    Imprimir_Lista(&sublista);
    printf("\n");

    Inserir_Sublista_Final(&lista, &sublista);
    Inserir_Sublista_Final(&lista2, &sublista);
    Imprimir_Lista(&lista);
    printf("\n");

    Inserir_Atomo_Final(&lista, 3);
    Inserir_Atomo_Final(&lista2, 4);
    Imprimir_Lista(&lista);
    printf("\n");

    encontrado = Buscar_Numero(&lista, 10);
    if(encontrado)
    {
        printf("Numero Encontrado!\n");
    }
    else
    {
        printf("Numero nao Encontrado!\n");
    }

    iguais = Comparar_Listas(&lista, &lista2);
    if(iguais)
    {
        printf("Listas Iguais!\n");
    }
    else
    {
        printf("Listas Diferentes!\n");
    }

    printf("Tamanho da Lista Principal: %d\n", Tamanho_Principal(&lista));
    printf("Tamanho Total da Lista: %d\n", Tamanho_Total(&lista));

    Remover_Final(&lista);
    Imprimir_Lista(&lista);
    printf("\n");

    Remover_Final(&lista);
    Imprimir_Lista(&lista);
    printf("\n");

    Remover_Final(&lista);
    Imprimir_Lista(&lista);
    printf("\n");

    Remover_Final(&lista);
    Imprimir_Lista(&lista);
    printf("\n");

    Remover_Final(&lista);
    Imprimir_Lista(&lista);
    printf("\n");


    return 0;
}
