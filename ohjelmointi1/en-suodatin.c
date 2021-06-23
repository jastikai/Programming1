/* 
Ohjelmointi 1
Ohjelmointitehtävä 52

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void luepois(void);
void katkaise(char * jono);

int main(void)
{
    char merkkijono[5][100];
    int pituus;

    for (int i = 0; i <= 4; i++)
    {
        katkaise(fgets(merkkijono[i], 100, stdin));
    }

    for (int i = 0; i <= 4; i++)
    {
        pituus = strlen(merkkijono[i]);

        if (merkkijono[i][pituus - 1] == 78 | merkkijono[i][pituus - 1] - 32 == 78 && merkkijono[i][pituus - 2] == 69 | merkkijono[i][pituus - 2] - 32 == 69)
            printf("\n\"en\"-merkkijonoon paattyva merkkijono \"%s\"", merkkijono[i]);
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