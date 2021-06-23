/* 
Ohjelmointi 1
Ohjelmointitehtävä 50

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void luepois(void);
void katkaise(char * jono);
void luoLause(void);

int main(void)
{
    srand(time(NULL));

    luoLause();

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

void luoLause(void)
{
    int valitsin;
    char substantiivit[5][100];
    char verbit[5][100];
    int lkm;

    for (int i = 0; i <= 4; i++)
    {
        printf("\nAnna substantiivi (max 100 merkkia) > ");
        katkaise(fgets(substantiivit[i], 100, stdin));
        printf("\nAnna verbi (max 100 merkkia) > ");
        katkaise(fgets(verbit[i], 100, stdin));
    }

    scanf("%d", &lkm);
    luepois();

    printf("\n---Puppulauseet---");

    for (int i = 0; i <= lkm - 1; i++)
    {
        do 
        {
            valitsin = rand() % 5;
        } while (valitsin < 1 | valitsin > 4);

        switch (valitsin)
        {
            case 1:
                printf("\n%s %s", substantiivit[rand() % 5], verbit[rand() % 5]);
                break;
            
            case 2:
                printf("\n%s %s ja %s %s", substantiivit[rand() % 5], verbit[rand() % 5], substantiivit[rand() % 5], verbit[rand() % 5]);
                break;

            case 3:
                printf("\n%s %s tai %s %s", substantiivit[rand() % 5], verbit[rand() % 5], substantiivit[rand() % 5], verbit[rand() % 5]);
                break;

            case 4:
                printf("\nJos %s %s, niin %s %s", substantiivit[rand() % 5], verbit[rand() % 5], substantiivit[rand() % 5], verbit[rand() % 5]);
                break;
        }
    }
}