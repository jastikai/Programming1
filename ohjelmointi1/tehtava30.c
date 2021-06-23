/* 
Ohjelmointi 1
Ohjelmointitehtävä 30

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int onkoLukuTaydellinen( int luku );

int main(void)
{
    for (int luku = 1; luku <= 10000; luku++)
    {
        if (onkoLukuTaydellinen(luku))
            printf("\nLuku %d on taydellinen luku\n", luku);
    }
    return(0);
}

int onkoLukuTaydellinen( int luku )
{
    int summa;
    int tulos;
    tulos = 0;
    summa = 0;

    for (int i = 1; i < luku; i++)
    {
        if (luku % i == 0)
            summa = summa + i;
    }
    
    if (summa == luku)
        tulos = 1;

    return(tulos);
}