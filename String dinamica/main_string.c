#include <stdio.h>
#include <stdlib.h>
#include "string_dinamica.c"

int main()
{
    Lista str1;
    Lista str2;
    Lista str3;
    Criar(&str1);
    Criar(&str2);
    Criar(&str3);

    Inserir_Final(&str1, 'v');
    Inserir_Final(&str1, 'i');
    Inserir_Final(&str1, 'n');
    Inserir_Final(&str1, 'i');

    Imprimir(&str1);
    printf("Tamanho: %d\n", Tamanho(&str1));

    Copiar(&str1, &str2);
    Imprimir(&str2);
    printf("Tamanho: %d\n", Tamanho(&str2));

    Concatenar(&str1, &str2, &str3);
    Imprimir(&str3);
    printf("Tamanho: %d\n", Tamanho(&str3));

    Comparar_Tamanho(&str1, &str2);
    Comparar_Tamanho(&str1, &str3);

    if(Comparar_Conteudo(&str1, &str2) == 1)
    {
        printf("Os conteudos sao iguais!\n");
    }
    else
    {
        printf("Os conteudos sao diferentes!\n");
    }

    if(Comparar_Conteudo(&str1, &str3) == 1)
    {
        printf("Os conteudos sao iguais!\n");
    }
    else
    {
        printf("Os conteudos sao diferentes!\n");
    }

    Remover_Trecho(&str1, 0, 2);
    Imprimir(&str1);

    Inserir_Substring(&str1, &str2, 1);
    Imprimir(&str1);
    Imprimir(&str2);

    printf("teste: %d\n", Busca_Posicao(&str1, &str2));

    Reinicializar(&str1);
    printf("Tamanho: %d\n", Tamanho(&str1));
    Imprimir(&str1);

    return 0;
}
