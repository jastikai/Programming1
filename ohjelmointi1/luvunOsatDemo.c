/*  luvunOsatDemo.c    */
#include <stdio.h> /* printf- ja scanf-funktiot */
#include <math.h>  /* abs funktio */

void ositaLuku(double n, char * etumerkkiO, int * kokonaisOsaO, double * desimaaliOsaO);

int main(void){
    double luku;
    char etumerkki;
    int kokonaisOsa;
    double desimaaliOsa;

    printf("\nAnna reaaliluku >");
    scanf("%lf", &luku);

    ositaLuku(luku, &etumerkki, &kokonaisOsa, &desimaaliOsa);

    printf("\nLuvun %lf\n", luku);
    printf("Etumerkki on: %c\n", etumerkki);
    printf("Kokonaisosa on: %d\n", kokonaisOsa);
    printf("Desimaaliosa on: %lf\n", desimaaliOsa);

    return(0);
}

void ositaLuku(double n, char * etumerkkiO, int * kokonaisOsaO, double * desimaaliOsaO){

    double luvunItseisarvo;

    /* etumerkin määritys */
    *etumerkkiO = ' ';   /* jos 0.0, ei etumerkkiä */

    if(n > 0.0)
        *etumerkkiO = '+';
    else if(n < 0.0)
        *etumerkkiO = '-';

    /* kokonaisosan määritys */
    luvunItseisarvo = fabs(n); /* fabs -laskee reaaliluvun
                                 itseisarvon */

    /* floor(x) palauttaa x:ää pienemmän suurimman
   kokonaisluvun reaalilukuna.
   (int) muuttaa arvon kokonaisluvuksi */
    *kokonaisOsaO = (int)floor(luvunItseisarvo);

    /* desimaaliosan määritys */
    *desimaaliOsaO = luvunItseisarvo - *kokonaisOsaO;

}