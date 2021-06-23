/* 
Ohjelmointi 1
Ohjelmointitehtävä 47

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int pisteet[4][10] = {0};
    int arvio[4] = {0};
    int hyvia;

    for (int i = 0; i <= 3; i++)
    {
        printf("\nAnna juoma numero %d. pisteet", i + 1);

        for (int j = 0; j <= 9; j++)
        {
            printf("\nAnna arvosana (1-5) > ");
            do
            {
                scanf("%d", &pisteet[i][j]);
                if (pisteet[i][j] < 1 | pisteet[i][j] > 5)
                    printf("\nARVOSANAN TULEE OLLA VALILTA 1 - 5 !");
            } while(pisteet[i][j] < 1 | pisteet[i][j] > 5);
        }
    }

    for (int i = 0; i <= 3; i++)
    {
        hyvia = 0;
        for (int j = 0; j <= 9; j++)
        {
            if (pisteet[i][j] >= 3)
                hyvia++;
        }

        if (hyvia > 5)
        {
            printf("\nJuoma numero %d on kelvollista", i + 1);
            // arvio[i] = 1;
        }
        else
        {
            printf("\nJuoma numero %d on kelvotonta", i + 1);
            // arvio[i] = 0;
        }
        // printf("")
    }

    return(0);
}