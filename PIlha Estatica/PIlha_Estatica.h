#define MAX 15

typedef struct
{
    int vPilha[MAX];
    int topo;
}Pilha;

void Inicializar(Pilha *pilha);
void Imprimir(Pilha *pilha);
bool Vazia(Pilha *pilha);
void Push(Pilha *pilha, int elemento);
void Pop(Pilha* pilha, int* elemento);
