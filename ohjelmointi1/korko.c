/* 
Ohjelmointi 1
Ohjelmointitehtävä 5

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Määritellään tarvittavat muuttujat.
    double lainasumma;
    double lainakorko;
    int lainapaivat;
    double kokonaiskorko;
    double korkoprosentti;

    //Pyydetään käyttäjältä summa, korko ja laina-aika päivinä.
    scanf("%lf", &lainasumma);
    scanf("%lf", &lainakorko);
    scanf("%d", &lainapaivat);

    //Lasketaan kokonaiskorko.
    korkoprosentti = lainakorko/100.0;
    kokonaiskorko = lainasumma * korkoprosentti * lainapaivat/365;
    printf("Lainapääoman %.2lf euroa korko %d päivältä korkoprosentilla %.2lf on yhteensä %.2lf euroa.", lainasumma, lainapaivat, lainakorko, kokonaiskorko);

    return(0);
}