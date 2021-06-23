/* 
Ohjelmointi 1
Ohjelmointitehtävä 11

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Muuttujat
    int i;
    int suurin;
    int luku;

    suurin = 0;

    for (i = 1; i <= 10; i = i + 1)
    {
        scanf("%d", &luku);
        if (i == 1)
            suurin = luku;
        if (luku > suurin)
            suurin = luku;
    }
    printf("Suurin syottamasi luku oli %d", suurin);
    return(0);
}