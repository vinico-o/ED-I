#include <stdio.h>
#include <stdlib.h>
#include "Deque.c"

int main()
{
    Deque deque;
    int elemento;

    Inicializar(&deque);

    if(Vazio(&deque))
    {
        printf("Deque Vazio!\n");
    }
    
    InserirInicio(&deque, 1);
    Imprimir(&deque);
    InserirInicio(&deque, 2);
    Imprimir(&deque);
    InserirInicio(&deque, 3);
    Imprimir(&deque);
    InserirInicio(&deque, 4);
    Imprimir(&deque);
    InserirFinal(&deque, 1);
    Imprimir(&deque);
    InserirFinal(&deque, 2);
    Imprimir(&deque);
    InserirFinal(&deque, 3);
    Imprimir(&deque);
    InserirFinal(&deque, 4);
    Imprimir(&deque);

    RemoverInicio(&deque, &elemento);
    printf("Elemento: %d\n", elemento);
    Imprimir(&deque);
    RemoverFinal(&deque, &elemento);
    printf("Elemento: %d\n", elemento);
    Imprimir(&deque);

    Reinicializar(&deque);
    Imprimir(&deque);

    return 0;
}