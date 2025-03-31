typedef struct No
{
    int elemento;
    struct No* prox;
}No;

typedef struct
{
    int qntd;
    No* primeiro;
    No* ultimo;
}Fila;

void Inicializar(Fila* fila);
void Imprimir(Fila *fila);
bool Vazio(Fila* fila);
void Enfileirar(Fila* fila, int n_cliente);
void Desenfileirar(Fila *fila);