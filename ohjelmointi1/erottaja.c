/* 
Ohjelmointi 1
Ohjelmointitehtävä 6

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Muuttujat
    int kokonaisluku;
    int jakaja;
    int temp;
    int laskuri;
    int temp2;
    int i, j, k;

    scanf("%d", &kokonaisluku);
    printf("Luku %d eroteltuna: ", kokonaisluku);

    temp = kokonaisluku;
    jakaja = 1;
    temp2 = kokonaisluku;
    laskuri = 1;

   
    if (abs(kokonaisluku) < 10000 && kokonaisluku != 0)
    {
        if (kokonaisluku < 10)
        {
            for (j = 1; j <= 4; j = j + 1)
            {
                printf("%d ", 0);
            }
        }
        if (kokonaisluku > 10)
        {
            while(temp2)
            {
                temp2 = temp2/10;
                laskuri++;
            }
            for (i = 0; i <= 5 - laskuri; i = i + 1)
            {
                printf("%d ", 0);
            } 
        }
    }
    if (kokonaisluku == 0)
    {
        for (k = 1; k <= 5; k = k + 1)
        {
            printf("%d ", 0);
        }
    }


    //Tehdään tarpeeksi iso jakaja, jotta saadaan aina yksi desimaali ulos luvusta tulostettavaksi.
    while(temp)
    {
        temp = temp/10;
        jakaja = jakaja*10;
    }

    while(jakaja > 1)
    {
        jakaja = jakaja/10;
        printf("%d ", kokonaisluku/jakaja);
        kokonaisluku = kokonaisluku % jakaja;
    }
    
    return(0);
}