/* 
Ohjelmointi 1
Ohjelmointitehtävä 40

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    int taulukko[20] = {0};
    int testiTaulukko[20] = {0};
    srand(time(NULL));

    for (int i = 0; i <= 19; i++)
    {   
        testiTaulukko[i] = i + 1;
        do
        {
            printf("%d.", i + 1);
            scanf("%d", &taulukko[i]);
            // taulukko[i] = rand() % 100;
            if (taulukko[i] < 10 | taulukko[i] > 100)
                printf("Ei kelpaa! Yrita uudelleen >");
        } while(taulukko[i] < 10 | taulukko[i] > 100);
    }

    for (int j = 0; j <= 19; j++)
    {
        for (int k = j - 1; k >= 0; k--)
        {
            if (taulukko[j] == taulukko[k])
            {
                taulukko[j] = 0;
                testiTaulukko[k] = 0;
                testiTaulukko[j] = 0;
                // taulukko[k] = 0;
            }
        }
    }

    for (int i = 0; i <= 19; i++)
    {
        if (taulukko[i] > 0 && testiTaulukko[i] != 0)
            printf("\n%d", taulukko[i]);
    }

    return(0);
}