/* 
Ohjelmointi 1
Ohjelmointitehtävä 42

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>

void taytaTaulukko(int * taulukko);
void tulostaTaulukko(int taulukko[], double keskiarvo, int suurin, int suurinIdx);
double laskeKeskiarvo(int taulukko[]);
int suurinLuku(int taulukko[]);
int etsiIndeksi(int taulukko[], int luku);

int main(void)
{
    int taulukko[10] = {0};
    int suurin;
    double keskiarvo;
    int suurinIdx;

    taytaTaulukko(taulukko);
    suurin = suurinLuku(taulukko);
    keskiarvo = laskeKeskiarvo(taulukko);
    suurinIdx = etsiIndeksi(taulukko, suurin);
    tulostaTaulukko(taulukko, keskiarvo, suurin, suurinIdx);

    

    return(0);
}

void taytaTaulukko(int * taulukko)
{
    for (int i = 0; i <= 9; i++)
    {   
        

        
        do
        {
            printf("Anna %d. kokonaisluku >", i + 1);
            scanf("%d", &taulukko[i]);
            // taulukko[i] = rand() % 100;
            // if (taulukko[i] < 10 | taulukko[i] > 100)
            //     printf("Ei kelpaa! Yrita uudelleen >");
        } while(taulukko[i] < 0 | taulukko[i] > 100);
    }
}

void tulostaTaulukko(int taulukko[], double keskiarvo, int suurin, int suurinIdx)
{   
    printf("Taulukon:\n");
    for (int i = 0; i <= 9; i++)
    {
        printf("%d ", taulukko[i]);
    }

    printf("\nSuurin arvo on %d, ja se sijaitsee paikassa %d", suurin, suurinIdx);
    printf("\nTaulukon arvojen keskiarvo on %.3lf", keskiarvo);
}

double laskeKeskiarvo(int taulukko[])
{
    double summa;
    double keskiarvo;

    for (int i = 0; i <= 9; i++)
    {
        summa = summa + taulukko[i];
    }

    keskiarvo = summa / 10.0;

    return(keskiarvo);
}

int suurinLuku(int taulukko[])
{
    int suurin = 0;

    for (int i = 0; i <= 9; i++)
    {
        if (taulukko[i] > suurin)
            suurin = taulukko[i];
    }

    return(suurin);
}

int etsiIndeksi(int taulukko[], int luku)
{
    int indeksi;

    for (int i = 0; i <= 9; i++)
    {
        if (taulukko[i] == luku)
        {
            indeksi = i;
            return(indeksi);
        }
    }

    // return(indeksi);
}