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

    Remover(&matriz, 2, 2);
    Remover(&matriz, 0, 0);
    Remover(&matriz, 2, 1);

    Imprimir(&matriz);

    Somar_Linha(&matriz, 2, 3);

    Imprimir(&matriz);

    for(int i = 0; i < LINHA; i++)
    {
        for(int j = 0; j < COLUNA; j++)
        {
            printf("REMOCAO %d %d\n", i, j);
            Remover(&matriz, i, j);
            Imprimir(&matriz);
        }
    }

    return 0;
}
