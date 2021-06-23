/* 
Ohjelmointi 1
Ohjelmointitehtävä 57

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int omaStrcmp(char * jono1, char * jono2);
void luepois(void);
void katkaise(char * jono);

int main(void)
{
    char jono1[100];
    char jono2[100];
    char jono1test[100];
    char jono2test[100];

    katkaise(fgets(jono1, 100, stdin));
    katkaise(fgets(jono2, 100, stdin));
    
    strcpy(jono1test, jono1);
    strcpy(jono2test, jono2);

    if (omaStrcmp(jono1test, jono2test) == 1)
        printf("\n%s > %s", jono1, jono2);
    else if (omaStrcmp(jono1test, jono2test) == 2)
        printf("\n%s < %s", jono1, jono2);
    else if (omaStrcmp(jono1test, jono2test) == 3)
        printf("\n%s == %s", jono1, jono2);

    return(0);
}

int omaStrcmp(char * jono1, char * jono2)
{
    int pituus1, pituus2;
    int laskuri = 0;
    int pidempi;

    pituus1 = strlen(jono1);
    pituus2 = strlen(jono2);
    
    if (pituus1 >= pituus2)
        pidempi = pituus1;
    else
        pidempi = pituus2;
    

    // printf("%s", jono1);
    // printf("%s", jono2);

    for (int i = 0; i < pidempi; i++)
    {
        if (jono1[i] > 64 && jono1[i] < 91)
            jono1[i] = jono1[i] + 32;
        if (jono2[i] > 64 && jono2[i] < 91)
            jono2[i] = jono2[i] + 32;

        if (jono1[i] == jono2[i])
            laskuri++;
        else if (jono1[i] > jono2[i])
        {
            // printf("\n%s > %s", jono1, jono2);
            return(1);
            // break;
        }
        else if (jono1[i] < jono2[i])
        {
            // printf("\n%s < %s", jono1, jono2);
            return(2);
            // break;
        }
    }

    if (laskuri == pidempi)
    {
        // printf("\n%s == %s", jono1, jono2);
        return(3);
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