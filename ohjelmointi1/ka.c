/*
Ohjelmointi 1
Ohjelmointitehtävä 18

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Muuttujat
    double syote;
    double summa;
    double keskiarvo;
    int laskuri;


    //Alkuarvot
    summa = 0;
    laskuri = 0;

    while(1)
    {
        scanf("%lf", &syote);
        if (syote < 0)
            break;
        summa += syote;
        laskuri++;
    }

    keskiarvo = summa / laskuri;
    printf("%.2lf", keskiarvo);
    return(0);
}