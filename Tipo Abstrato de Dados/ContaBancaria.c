#include <stdio.h>
#include "ContaBancaria.h"

void Inicializar_Conta(ContaBancaria *conta, int numero, double saldo)
{
    conta->numero = numero;
    conta->saldo = saldo;
}
void Depositar_Conta(ContaBancaria *conta, double valor)
{
    conta->saldo += valor;
}
void Sacar_Conta(ContaBancaria *conta, double valor)
{
    conta->saldo -= valor;
}
void Imprimir_Conta(ContaBancaria* conta)
{
    printf("nNumero: %d\n", conta->numero);
    printf("Saldo: %.2lf\n", conta->saldo);
}
