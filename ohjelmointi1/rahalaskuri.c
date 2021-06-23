/* 
Ohjelmointi 1
Ohjelmointitehtävä 45

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int tyontekijat = 5;
    int rahayksikot = 9;
    int nimellisarvot[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int lkmSetelit[9] = {0};
    int summaSetelit[9] = {0};
    int palkat[5] = {0};
    int tempPalkka;
    int tmp;

    for (int i = 0; i <= tyontekijat - 1; i++)
    {
        printf("\nAnna %d. tyontekijan palkka >", i + 1);
        scanf("%d", &palkat[i]);
    }

    printf("\nPalkka");
    for (int i = 0; i <= rahayksikot - 1; i++)
    {
        printf("%4d €", nimellisarvot[i]);
    }

    for (int j = 0; j <= tyontekijat - 1; j++)
    {
        tempPalkka = palkat[j];

        printf("\n%6d", tempPalkka);

        for (int k = 0; k <= rahayksikot - 1; k++)
        {
            tmp = tempPalkka / nimellisarvot[k];

            // if (tmp == 0)
            //     printf("      ");
            // else
                printf("%6d", tmp);

            summaSetelit[k] = summaSetelit[k] + tmp;
            
            tempPalkka = tempPalkka % nimellisarvot[k];
        }
    }

    printf("\n  YHT:");
    for (int i = 0; i <= rahayksikot - 1; i++)
    {
        printf("%6d", summaSetelit[i]);
    }

    return(0);
}