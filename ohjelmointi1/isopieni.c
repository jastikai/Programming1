/* 
Ohjelmointi 1
Ohjelmointitehtävä 48

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void luepois( void );


int main(void)
{
    char jonoPieni[100];
    char jonoIso[100];
    int jonoPituus;

    fgets(jonoPieni, 100, stdin);

    jonoPituus = strlen(jonoPieni);

    // printf("%d", jonoPituus);

    if( jonoPieni[strlen(jonoPieni)-1] == '\n')
        jonoPieni[strlen(jonoPieni)-1] = '\0';
    else
        luepois(); /* tyhjentää lukupuskurin */

    strcpy(jonoIso, jonoPieni);

    for (int i = 0; i <= jonoPituus - 1; i++)
    {
        if (jonoPieni[i] > 64 && jonoPieni[i] < 91)
            jonoPieni[i] += 32;


        if (jonoPieni[i] > 96 && jonoPieni[i] < 123)
            jonoIso[i] = jonoPieni[i] - 32;
        else
            jonoIso[i] = jonoPieni[i];
    }

    // for (int i = 0; i <= jonoPituus - 1; i++)
    // {
    //     printf("%c", jonoPieni[i]);
    // }

    // for (int i = 0; i <= jonoPituus - 1; i++)
    // {
    //     printf("%c", jonoIso[i]);
    // }

    printf("%s%s", jonoPieni, jonoIso);

    return(0);
}

void luepois( void )
{
   while( getc(stdin) != '\n' );
}