/* 
Ohjelmointi 1
Ohjelmointitehtävä 8

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Muuttujat
    double tankkaus;
    double kokonaistankkaus;
    double kilometrit;
    double kokonaismatka;
    double kulutus;
    double kokonaiskulutus;
    double keskikulutus;
    int laskuri;

    //Määrätään alkuarvot
    kokonaiskulutus = 0;
    laskuri = 0;
    kokonaismatka = 0;
    kokonaistankkaus = 0;

    while (1)
    {
        //printf("Anna tankatun bensiinin maara ( -1 lopettaa ) > ");
        printf("%d\n", -1);
        scanf("%lf", &tankkaus);
        if (tankkaus == -1)
        {
            break;
        }
        //printf("Ajetut kilometrit > ");
        scanf("%lf", &kilometrit);
        kulutus = (tankkaus / kilometrit) * 100;
        //printf("Keskikulutus talla tankkauksella on %.3lf litraa satasella\n", kulutus);
        printf("%.3lf\n", kulutus);
        kokonaiskulutus = kokonaiskulutus + kulutus;
        kokonaismatka = kokonaismatka + kilometrit;
        kokonaistankkaus = kokonaistankkaus + tankkaus;
        laskuri++;
    }

    //keskikulutus = kokonaiskulutus / laskuri;
    keskikulutus = (kokonaistankkaus / kokonaismatka)*100;
    
    //printf("kokonaiskeskikulutus on %.3lf litraa satasella", keskikulutus);
    printf("%.3f\n", keskikulutus);

    return(0);
}