/* 
Ohjelmointi 1
Ohjelmointitehtävä 63

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void luepois(void);
void katkaise(char * jono);
double muutaSek(char * jono);
void swap(int* xp, int* yp);
void vaihda(int arr[],double arr2[], int n);

typedef struct
{
    char nimi[100];
    double aika500;
    double aika1500;
    double aika5k;
    double aika10k;
    double pisteet;
} pistetaulukko;

int main(void)
{

    int kilpailijat;

    scanf("%d", &kilpailijat);
    luepois();

    pistetaulukko pts[kilpailijat];

    int indeksit[kilpailijat];
    double pisteytys[kilpailijat];
    double h, min, sec;
    double matka500, matka1500, matka5k, matka10k;
    char aikateksti500[20];
    char aikateksti1500[20];
    char aikateksti5k[20];
    char aikateksti10k[20];

    for (int i = 0; i < kilpailijat; i++)
    {

        indeksit[i] = i;
        katkaise(fgets(pts[i].nimi, 100, stdin));
        katkaise(fgets(aikateksti500, 20, stdin));
        katkaise(fgets(aikateksti1500, 20, stdin));
        katkaise(fgets(aikateksti5k, 20, stdin));
        katkaise(fgets(aikateksti10k, 20, stdin));

        pts[i].aika500 = muutaSek(aikateksti500);
        pts[i].aika1500 = muutaSek(aikateksti1500) / 3.0;
        pts[i].aika5k = muutaSek(aikateksti5k) / 10.0;
        pts[i].aika10k = muutaSek(aikateksti10k) / 20.0;

        pts[i].pisteet = pts[i].aika500 + pts[i].aika1500 + pts[i].aika5k + pts[i].aika10k;

        pisteytys[i] = pts[i].pisteet;
    }

    //lajittele(pisteytys, indeksit, kilpailijat);

    vaihda(indeksit, pisteytys, kilpailijat);

    for (int i = 0; i < kilpailijat; i++)
    {
        printf("\n%d. %15s%.3lf", i+1, pts[indeksit[i]].nimi, pisteytys[indeksit[i]]);
    }

    return(0);
}

void luepois(void)
{
   while( getc(stdin) != '\n' );
}

void katkaise(char * jono)
{
    if( jono[strlen(jono)-1] == '\n')
        jono[strlen(jono)-1] = '\0';
    else
        luepois();
}

double muutaSek(char * jono)
{
    int pituus;
    double kerroin = 10.0;
    double sek, min;
    char minuutit[3];
    char sekunnit[3];
    char desimaalit[3];

    minuutit[0] = jono[0];
    minuutit[1] = jono[1];
    minuutit[2] = '\0';

    min = (double)atoi(minuutit);

    sekunnit[0] = jono[3];
    sekunnit[1] = jono[4];
    sekunnit[2] = '\0';

    sek = (double)atoi(sekunnit);

    desimaalit[0] = jono[6];
    desimaalit[1] = jono[7];
    desimaalit[2] = '\0';

    sek += ((double)atoi(desimaalit)) / 100.0;
    sek += 60.0 * min;


    return(sek);
}


void vaihda(int arr[], double arr2[], int n)
{
    int temp1, temp2, temp3;
    int min_idx;

    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr2[j] < arr2[min_idx])
                min_idx = j;
        }

        swap(&arr[min_idx], &arr[i]);
        //swap(&arr2[min_idx], &arr2[i]);
    }
}

void swap(int* xp, int* yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 