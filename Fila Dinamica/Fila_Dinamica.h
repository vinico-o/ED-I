typedef struct
{
    int elemento;
    struct No *prox;
}No;

//descritores da fila
typedef struct
{
    int qntd;
    No* primeiro;
    No* ultimo;
}Fila;

void Inicializar(Fila *fila);
bool Vazia(Fila* fila);
void Inserir(Fila *fila, int elemento);
void Remover(Fila *fila, int *elemento);
void Imprimir(Fila *fila);
