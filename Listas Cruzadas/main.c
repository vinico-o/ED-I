#include "Lista_Cruzada.c"

int main ()
{
    Matriz matriz;
    Inicializar_Matriz(&matriz);

    for(int i = 0; i < LINHA; i++)
    {
        for(int j = 0; j < COLUNA; j++)
        {
            Inserir(&matriz, i, j, (i + j));
        }
    }

    Imprimir(&matriz);

    Somar_Linha(&matriz, 1, 3);

    Imprimir(&matriz);

    for(int i = 0; i < LINHA; i++)
    {
        for(int j = 0; j < COLUNA; j++)
        {
            Remover(&matriz, i, j);
            printf("REMOCAO %d %d\n", i, j);
            Imprimir(&matriz);
        }
    }

    Remover(&matriz, 3, 3); //testando remocao de elem ento que nao existe
    
    return 0;
}