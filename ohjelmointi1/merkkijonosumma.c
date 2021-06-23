/* 
Ohjelmointi 1
Ohjelmointitehtävä 49

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void luepois(void);
void katkaise(char * jono);

int main(void)
{
    int luku1, luku2;
    int summa;
    char merkkiLuku1[10];
    char merkkiLuku2[10];
    int kerroin = 10;
    int jonoPit1, jonoPit2;

    fgets(merkkiLuku1, 10, stdin);
    fgets(merkkiLuku2, 10, stdin);

    katkaise(merkkiLuku1);
    katkaise(merkkiLuku2);

    // jonoPit1 = strlen(merkkiLuku1);
    // jonoPit2 = strlen(merkkiLuku2);

    // for (int i = 0; jonoPit1; i++)
    // {

    // }

    luku1 = atoi(merkkiLuku1);
    luku2 = atoi(merkkiLuku2);

    summa = luku1 + luku2;

    printf("\n%d", summa);



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