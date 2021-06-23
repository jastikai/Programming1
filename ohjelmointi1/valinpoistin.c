/* 
Ohjelmointi 1
Ohjelmointitehtävä 54

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void luepois(void);
void katkaise(char * jono);
void poistaValilyonnit(char * jono1, char * jono2);

int main(void)
{
    char merkkijonot[3][100];
    char merkkijonotPuhdas[3][100];

    for (int i = 0; i <= 2; i++)
    {
        katkaise(fgets(merkkijonot[i], 100, stdin));
    }

    for (int i = 0; i <= 2; i++)
    {
        poistaValilyonnit(merkkijonot[i], merkkijonotPuhdas[i]);
    }

    for (int i = 0; i <= 2; i++)
    {
        printf("\n%s", merkkijonotPuhdas[i]);
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

void poistaValilyonnit(char * jono1, char * jono2)
{
    int pituus1, pituus2;
    int liikuttaja = 0;

    pituus1 = strlen(jono1);
    
    for (int i = 0; i <= pituus1 - 1; i++)
    {
        if (jono1[i] == ' ')
        {
            // liikuttaja++;
            for (int j = i + 1; j <= pituus1; j++)
            {
                jono1[j - 1] = jono1[j]; 
            }
        }
    }

    strcpy(jono2, jono1);
}