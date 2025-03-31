typedef struct
{
    char elemento;
    struct No *prox;
} No;

typedef struct
{
    No *primElem;
    No *ultElem;
    int qntd;
} Lista;

void Criar(Lista* lista);
void Inserir_Final(Lista* lista, char letra);
void Imprimir(Lista* lista);
int Tamanho(Lista* lista);
void Copiar(Lista* lista1, Lista* lista2);
void Concatenar(Lista* lista1, Lista* lista2, Lista* lista3);
bool Comparar_Conteudo(Lista *lista1, Lista *lista2);
void Remover_Trecho(Lista* lista1, int start, int numero);
void Inserir_Substring(Lista* lista1, Lista* subs, int start);
int Busca_Posicao(Lista* lista1, Lista* lista2);
