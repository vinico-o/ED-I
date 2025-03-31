typedef struct
{
    int numero;
    double saldo;
} ContaBancaria;

//cabeçalho das funções
void Inicializar_Conta(ContaBancaria *conta, int numero, double saldo);
void Depositar_Conta(ContaBancaria *conta, double valor);
void Sacar_Conta(ContaBancaria *conta, double valor);
void Imprimir_Conta(ContaBancaria conta);
