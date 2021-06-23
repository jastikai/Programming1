/* 
Ohjelmointi 1
Ohjelmointitehtävä 3

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Määritellään tarvittavat muuttujat.
    double tuntipalkka;
    double veroprosentti;
    double tehdyt_tunnit;
    double bruttopalkka;
    double nettopalkka;
    double verot;

    //Pyydetään käyttäjältä tuntipalkka, tehdyt tunnit ja veroprosentti.
    printf("Anna tuntipalkka:\n> ");
    scanf("%lf", &tuntipalkka);
    printf("Anna tehdyt tunnit:\n> ");
    scanf("%lf", &tehdyt_tunnit);
    printf("Anna veroprosentti:\n> ");
    scanf("%lf", &veroprosentti);

    //Lasketaan veron osuus bruttopalkasta sekä nettopalkka, ja kerrotaan ne käyttäjälle.
    bruttopalkka = tuntipalkka * tehdyt_tunnit;
    verot = (veroprosentti/100.0) * bruttopalkka;
    nettopalkka = bruttopalkka - verot;
    printf("Nettopalkkasi on %.2lf euroa, ja verojen osuus %.2lf euroa.\n", nettopalkka, verot);

    return(0);
}