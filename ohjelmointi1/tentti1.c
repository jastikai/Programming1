#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double keskiarvo(int taulukko[], int koko);

int main(void)
{
    int koko = 50;
    int taulukko[50] = {0};
    double keskia;
    srand(time(NULL));

    //Tässä taulukko täytetään satunnaisluvuilla.
    for (int i = 0; i < koko; i++)
    {
        taulukko[i] = rand() %;
    }

    keskia = keskiarvo(taulukko, koko);

    printf("%lf", keskia);

    return(0);
}

double keskiarvo(int taulukko[], int koko)
{
    double summa;
    double keskia;

    for (int i = 0; i < koko; i++)
    {
        summa += taulukko[i];
    }

    keskia = summa / koko;

    return(keskia);
}