typedef struct
{
    int numero;
    double saldo;
} ContaBancaria;

//cabe�alho das fun��es
void Inicializar_Conta(ContaBancaria *conta, int numero, double saldo);
void Depositar_Conta(ContaBancaria *conta, double valor);
void Sacar_Conta(ContaBancaria *conta, double valor);
void Imprimir_Conta(ContaBancaria conta);
