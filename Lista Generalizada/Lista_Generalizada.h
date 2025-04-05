#include <stdbool.h>

typedef struct No
{
    int tipo;

    union
    {
        int numero;
        struct Lista*  sublista;
    }Elemento;

    struct No* prox;
    struct No* ant;

}No;

typedef struct Lista
{
    No* primeiro;
    No* ultimo;
    int qntd;
}Lista;

void Inicializar(Lista* lista);
void Reinicializar(Lista* lista);
bool Vazia(Lista* lista);
void Inserir_Atomo_Final(Lista* lista, int elemento);
void Inserir_Sublista_Final(Lista*  lista, Lista* sublista);
void Imprimir_Lista(Lista* lista);
void Remover_Final(Lista* lista);
bool Buscar_Numero(Lista* lista, int chave);
bool Comparar_Listas(Lista *lista1, Lista* lista2);
int Tamanho_Principal(Lista* lista);
int Tamanho_Total(Lista* lista);
