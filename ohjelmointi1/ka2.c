/*
Ohjelmointi 1
Ohjelmointitehtävä 19

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

    do
    {
        //Pyydetään syöte
        scanf("%lf", &syote);
        if (syote < 0)
            break;
        summa += syote;
        laskuri++;
    } while (1);
    
    keskiarvo = summa / laskuri;
    printf("%.2lf", keskiarvo);
    
    return(0);
}