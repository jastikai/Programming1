/* 
Ohjelmointi 1
Ohjelmointitehtävä 2

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Määritellään tarvittavat muuttujat.
    int tuntipalkka;
    int tehdyt_tunnit;
    int bruttopalkka;

    //Pyydetään käyttäjältä tuntipalkka ja tehdyt tunnit.
    printf("Anna tuntipalkka:\n> ");
    scanf("%d", &tuntipalkka);
    printf("Anna tehdyt tunnit:\n> ");
    scanf("%d", &tehdyt_tunnit);

    //Lasketaan bruttopalkka ja printataan se käyttäjälle.
    bruttopalkka = tuntipalkka * tehdyt_tunnit;
    printf("Bruttopalkkasi on %d euroa.\n", bruttopalkka);

    return(0);

}