/* 
Ohjelmointi 1
Ohjelmointitehtävä 51

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

    for (int i = 0; i <= 4; i++)
    {
        katkaise(fgets(merkkijono[i], 100, stdin)); 
    }

    for (int i = 0; i <= 4; i++)
    {
        if (merkkijono[i][0] == 65 | merkkijono[i][0] == 97)
            printf("\n\"a\"-merkilla alkava merkkijono \"%s\"", merkkijono[i]);
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