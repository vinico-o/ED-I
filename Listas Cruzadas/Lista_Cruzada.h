#define LINHA 4
#define COLUNA 4

typedef struct No
{
    int numero;
    int linha, coluna;
    struct No* direita;
    struct No* baixo;  
} No;

typedef struct Matriz
{
    No *linha[20];
    No *coluna[20];
} Matriz;

void Inicializar_Matriz(Matriz* matriz);
void Imprimir(Matriz *matriz);
