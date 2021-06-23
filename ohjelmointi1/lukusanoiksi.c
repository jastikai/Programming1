/* 
Ohjelmointi 1
Ohjelmointitehtävä 56

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void luepois(void);
void katkaise(char * jono);

int main(void)
{
    char tuhannet[9][17] = {"tuhat", "kaksituhatta", "kolmetuhatta", "neljatuhatta", "viisituhatta", "kuusituhatta", "seitsemantuhatta", "kahdeksantuhatta", "yhdeksantuhatta"};
    char sadat[9][15] = {"sata", "kaksisataa", "kolmesataa", "neljasataa", "viisisataa", "kuusisataa", "seitsemansataa", "kahdeksansataa", "yhdeksansataa"};
    char kymmenet[8][19] = {"kaksikymmenta", "kolmekymmenta", "neljäkymmenta", "viisikymmenta", "kuusikymmenta", "seitsemankymmenta", "kahdeksankymmenta", "yhdeksankymmenta"};
    char ykkoset[9][11] = {"yksi", "kaksi", "kolme", "nelja", "viisi", "kuusi", "seitseman", "kahdeksan", "yhdeksan"};
    char toistaset[9][16] = {"yksitoista", "kaksitoista", "kolmetoista", "neljatoista", "viisitoista", "kuusitoista", "seitsemantoista", "kahdeksantoista", "yhdeksantoista"};
    char output[200];
    char input[5];
    int inputNro;

    fgets(input, 5, stdin);

    if (input[0] != '0')
        strcpy(output, tuhannet[input[0] - 49]);

    // printf("%s", output);

    for (int i = 1; i <= 3; i++)
    {
        inputNro = input[i] - 48;

        // printf("%d", inputNro);

        if (input[i] != '0' && i == 1)
            strcat(output, sadat[inputNro - 1]);
        if (input[i] != '0' && i == 2 && input[2] != '1')
            strcat(output, kymmenet[inputNro - 2]);
        if (input[i] != '0' && i == 3 && input[2] != '1')
            strcat(output, ykkoset[inputNro - 1]);
        if (input[i] != '0' && i == 2 && input[2] == '1')
        {
            strcat(output, toistaset[inputNro]);
            break;
        }
    }

    printf("%s", output);
    return(0);
}

void luepois(void)
{
   while( getc(stdin) != '\n' );
}

void katkaise(char * jono)
{
    if( jono[strlen(jono)-1] == '\n')
        jono[strlen(jono)-1] = '\0';
    else
        luepois();
}