/*
Ohjelmointi 1
Ohjelmointitehtävä 21

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    //Muuttujat
    char syote[6];
    char *eptr;
    double summa;
    double keskiarvo;
    int laskuri;
    int virheLaskuri;
    int onKirjain;
    int onNolla;
    double syote2;
    int virheToistaja;

    //Alkuarvot
    laskuri = 0;
    virheLaskuri = 0;
    summa = 0;

    while (virheLaskuri < 3)
    {
        scanf("%s", syote);

        syote2 = strtod(syote, &eptr);
        if (syote2 < 0)
            break;

        //Testataan onko syöte 0 tai kirjain
        onNolla = strcmp(syote, "0");
        onKirjain = (syote2 < 0.00001);

        if (!onKirjain || onNolla == 0)
        {
            summa += syote2;
            laskuri++;
        }

        virheToistaja = strlen(syote);

        if (onKirjain && onNolla != 0)
        {
            virheLaskuri++;

            /*for (int j = 1; j <= virheToistaja; j++)
            {
                printf("\n");
            }
            for (int i = 1; i <= virheToistaja; i++)
            {
                printf("Ei ollut reaaliluku\n");
            }*/

            printf("Ei ollut reaaliluku\n");
            printf("Virheellinen syote numero %d\n\n", virheLaskuri);

            if (virheLaskuri < 3)
                printf("Ei kelpaa, yrita uudelleen! >\n\n");

            /*for (int k = 1; k <= virheToistaja; k++)
            {
                printf("\n");
            }*/
        }
    }


    if (virheLaskuri == 3)
        printf("Virheellinen syote kolme kertaa. Ohjelma lopetetaan\n");

    if (laskuri > 0 && summa > 0)
    {
        keskiarvo = summa / laskuri;
        printf("%.2lf", keskiarvo);
    }

    return(0);
}