/* 
Ohjelmointi 1
Ohjelmointitehtävä 4

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
    int ylityo;
    double ylityopalkka;


    //Pyydetään käyttäjältä tuntipalkka, tehdyt tunnit ja veroprosentti.
    scanf("%lf", &tuntipalkka);
    scanf("%lf", &tehdyt_tunnit);
    scanf("%lf", &veroprosentti);

    //Jos tunnit menevät yli 40 tunnin, kerrotaan tuntipalkka 1.5:llä ja lasketaan ylityötunneista tullut palkka
    if (tehdyt_tunnit > 40)
    {
        ylityo = tehdyt_tunnit - 40;
        ylityopalkka = (tuntipalkka * 1.5) * ylityo;
        tehdyt_tunnit = tehdyt_tunnit - ylityo;
    }
    //Lasketaan normaaleista tunneista tullut palkka ja lisätään niihin ylityöpalkka, sekä verojen osuus.
    bruttopalkka = tuntipalkka * tehdyt_tunnit + ylityopalkka;
    verot = (veroprosentti/100.0) * bruttopalkka;
    nettopalkka = bruttopalkka - verot;

    //Kerrotaan käyttäjälle nettopalkka ja verojen osuus.
    printf("Nettopalkkasi on %.2lf euroa josta veron osuus on %.2lf euroa", nettopalkka, verot);

    return(0);
}