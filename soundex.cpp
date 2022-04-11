#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int verifica_string(char palavra[])
{
    for (int i = 0; palavra[i] != '\0'; ++i)
    {
        if (!isalpha(palavra[i]) || palavra[i] == ' ')
        {
            return 0;
        }
    }
    return 1;
}

void le_string(char palavra[],int tam_min, int tam_max)
{
    do
    {
        printf("Digite a palavra desejada: ");
        gets(palavra);

        if ((strlen(palavra) < tam_min || strlen(palavra) > tam_max) && palavra[0] != '\0')
            printf("Quantidade minima 4 letras e maxima 30 letras.\n");
    }
    while((strlen(palavra) < tam_min || strlen(palavra) > tam_max) && palavra[0] != '\0');
}

void soundex(char palavra[], char* soundex)
{
    char   *digitos = soundex;
    char   anterior = '\0';
    int    letra_1 = 1;
    char   codigo;

    while (*palavra != '\0' && digitos - soundex < 4)
    {
        switch(tolower(*palavra))
        {
        case 'b':
        case 'f':
        case 'p':
        case 'v':
            codigo = '1';
            break;

        case 'c':
        case 'g':
        case 'j':
        case 'k':
        case 'q':
        case 's':
        case 'x':
        case 'z':
            codigo = '2';
            break;

        case 'd':
        case 't':
            codigo = '3';
            break;

        case 'l':
            codigo = '4';
            break;

        case 'm':
        case 'n':
            codigo = '5';
            break;

        case 'r':
            codigo = '6';
            break;

        default:
            codigo = 0;
            break;
        }

        if (letra_1)
        {
            *digitos++ = toupper(*palavra);
            letra_1 = 0;
        }
        else if (codigo && anterior != codigo)
            *digitos++ = codigo;
            anterior = codigo;
            palavra++;
    }

    while (digitos - soundex < 4)
        *digitos++ = '0';

    *digitos = '\0';
}

int main()
{
    char palavra[31];
    char var_soundex[5];

    do
    {
        le_string(palavra,4, 30);
        if(verifica_string(palavra))
        {
            if(palavra[0] != '\0'){
            soundex(palavra, var_soundex);
            printf("%s = %s\n",palavra, var_soundex);
            }
        }
        else
        {
            printf("Nao e uma palavra, Digite Novamente.\n");
        }
    }
    while(palavra[0] != '\0');

    return 0;
}
