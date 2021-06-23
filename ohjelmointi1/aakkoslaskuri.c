/* 
Ohjelmointi 1
Ohjelmointitehtävä 53

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void luepois(void);
void katkaise(char * jono);

int main(void)
{
    char aakkoset[26];
    char merkkijonot[3][100];
    int maarat[26] = {0};
    int pituus;

    for (int i = 0; i <= 25; i++)
    {
        aakkoset[i] = i + 97;
    }

    for (int i = 0; i <= 2; i++)
    {
        katkaise(fgets(merkkijonot[i], 100, stdin));

        pituus = strlen(merkkijonot[i]);

        for (int j = 0; j <= pituus - 1; j++)
        {   
            // printf("\n%d", merkkijonot[i][j]);
            maarat[merkkijonot[i][j] - 97] = maarat[merkkijonot[i][j] - 97] + 1;
        }
    }

    printf("\n%-15s%-4s", "Aakkonen", "Kpl");
    for (int i = 0; i <= 25; i++)
    {
        printf("\n%-15c%-4d", aakkoset[i], maarat[i]);
    }

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