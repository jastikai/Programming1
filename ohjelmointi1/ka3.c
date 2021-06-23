/*
Ohjelmointi 1
Ohjelmointitehtävä 20

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
    laskuri = 0;
    summa = 0;

    for(int i = 1; i > 0; i++)
    {
        //Syöte
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