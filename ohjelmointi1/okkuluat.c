/* 
Ohjelmointi 1
Ohjelmointitehtävä 41

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int taulukkoYksi[10] = {0};
    int taulukkoKaksi[10] = {0};
    int k = 9;

    for (int i = 0; i <= 9; i++)
    {   
        printf("Syötä %d. luku >", i + 1);
        scanf("%d", &taulukkoYksi[i]);
    }

    for (int j = 0; j <= 9; j++)
    {
        taulukkoKaksi[j] = taulukkoYksi[k];
        k--;
    }

    for (int i = 0; i <= 9; i++)
    {
        printf("%-5d%d\n", taulukkoYksi[i], taulukkoKaksi[i]);
    }

    return(0);
}