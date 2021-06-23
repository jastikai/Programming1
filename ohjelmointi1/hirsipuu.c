/* 
Ohjelmointi 1
Ohjelmointitehtävä 68

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void piirraUkko(int virheet);
void luepois(void);

int main(void)
{
    FILE *input;

    srand(time(NULL));

    char sanat[100][30];

    int sanaLkm;
    int i = 0;
    int valitsin;
    char oikeaSana[30];
    char alaViiva[30];
    char sanaKopio[30];
    char ch;
    int pituus;
    int virheet = 0;
    int oikeaArvaus;
    int arvatutKirjaimet = 0;

    input = fopen("sanat.txt", "r");

    do
    {
        // fgets(sanat[i], 30, input);
        fscanf(input, "%s", sanat[i]);
        i++;
    } while(!feof(input));

    valitsin = rand() % i;

    strcpy(oikeaSana, sanat[valitsin]);
    strcpy(alaViiva, oikeaSana);
    strcpy(sanaKopio, oikeaSana);


    pituus = strlen(oikeaSana);

    for (int i = 0; i < pituus - 1; i++)
    {
        alaViiva[i] = '_';
    }

    while(virheet < 8 && arvatutKirjaimet < (pituus))
    {
        oikeaArvaus = 0;
        printf("\nArvaa kirjain > ");
        ch = getchar();
        luepois();

        for (int i = 0; i < pituus; i++)
        {
            if (oikeaSana[i] == ch)
            {
                alaViiva[i] = ch;
                oikeaSana[i] = '-';
                arvatutKirjaimet++;
                oikeaArvaus = 1;
            }
        }

        if (oikeaArvaus == 1)
            printf("\n%s", alaViiva);

        if (oikeaArvaus == 0)
        {
            virheet++;
            piirraUkko(virheet);
        }

    }

    if (arvatutKirjaimet == (pituus))
        printf("\nHienoa, arvasit oikein!");
    if (virheet == 8)
        printf("\nArvattava sana oli: %s", sanaKopio);

    fclose(input);

    return(0);
}

void piirraUkko(int virheet)
{
    switch (virheet)
    {
        case 1:
            printf("\n-------");
            break;
        case 2:
            printf("\n   |\n   |\n   |\n   |\n   |\n-------");
            break;
        case 3:
            printf("\n   ____\n   |\n   |\n   |\n   |\n   |\n-------");
            break;
        case 4:
            printf("\n   ______\n   |    |\n   |\n   |\n   |\n   |\n-------");
            break;
        case 5:
            printf("\n   ______\n   |    |\n   |    O\n   |\n   |\n   |\n-------");
            break;
        case 6:
            printf("\n   ______\n   |    |\n   |    O\n   |    |\n   |\n   |\n-------");
            break;
        case 7:
            printf("\n   ______\n   |    |\n   |    O\n   |   /|\\\n   |\n   |\n-------");
            break;
        case 8:
            printf("\n   ______\n   |    |\n   |    O\n   |   /|\\\n   |   / \\\n   |\n-------");
            break;
    }
}

void luepois(void)
{
   while( getc(stdin) != '\n' );
}