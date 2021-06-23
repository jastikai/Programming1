/* 
Ohjelmointi 1
Ohjelmointitehtävä 24

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double laskeParkkiMaksu(double tunnit);

int main(void)
{
    //Muuttujat
    double tunnitYksi;
    double tunnitKaksi;
    double tunnitKolme;
    double summaTunnit;
    double maksuYksi;
    double maksuKaksi;
    double maksuKolme;
    double summaMaksut;

    //Alkuarvot
    scanf("%lf", &tunnitYksi);
    scanf("%lf", &tunnitKaksi);
    scanf("%lf", &tunnitKolme);

    maksuYksi = laskeParkkiMaksu(tunnitYksi);
    maksuKaksi = laskeParkkiMaksu(tunnitKaksi);
    maksuKolme = laskeParkkiMaksu(tunnitKolme);
    
    summaTunnit = tunnitYksi + tunnitKaksi + tunnitKolme;
    summaMaksut = maksuYksi + maksuKaksi + maksuKolme;
    
    printf("Asiakas      Tunnit    Veloitus\n");
    printf("%8d%12.2lf%12.2lf\n", 1, tunnitYksi, maksuYksi);
    printf("%8d%12.2lf%12.2lf\n", 2, tunnitKaksi, maksuKaksi);
    printf("%8d%12.2lf%12.2lf\n", 3, tunnitKolme, maksuKolme);
    printf("YHTEENSA%12.2lf%12.2lf\n", summaTunnit, summaMaksut);



    return(0);
}

double laskeParkkiMaksu(double tunnit)
{
    double parkkiMaksu = 2.0;

    if (tunnit > 3.0 && tunnit <= 24.0)
        parkkiMaksu = parkkiMaksu + ((double)ceil(tunnit - 3) * 0.5);
    if (parkkiMaksu > 10.0)
        parkkiMaksu = 10.0;

    return(parkkiMaksu);
}