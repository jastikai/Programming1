/* 
Ohjelmointi 1
Ohjelmointitehtävä 60

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
char joukkueenNimi[30];
int voittojenMaara;
int tappioidenMaara;
} joukkueTietue;

joukkueTietue lueJoukkueenTiedot(void);
void tulostaSarjataulukko(joukkueTietue st);
void luepois(void);
void katkaise(char * jono);
void selectionSort(int arr[], int n);
void swap(int* xp, int* yp);
void vaihda(int arr[],int arr2[], int arr3[], int n);

int main(void)
{
    int joukkueidenMaara;
    int temp1, temp2;
    char tempChar[30];
    int a, b, c;

    scanf("%d", &joukkueidenMaara);
    luepois();

    int pelit[100] = {0};
    int voitot[100] = {0};
    int tappiot[100] = {0};


    joukkueTietue sarjataulukko[joukkueidenMaara];
    joukkueTietue jarjestetty[joukkueidenMaara];

    for (int i = 0; i < joukkueidenMaara; i++)
    {
        pelit[i] = i;
        sarjataulukko[i] = lueJoukkueenTiedot();
        voitot[i] = sarjataulukko[i].voittojenMaara;
        tappiot[i] = sarjataulukko[i].tappioidenMaara;
    }

    vaihda(pelit, voitot, tappiot, joukkueidenMaara);

    for (int i = 0; i < joukkueidenMaara; i++)
    {
        printf("%d", pelit[i]);
    }
    

    printf("\n****************************************\nTULOSLISTA\n****************************************\n");

    for (int i = 0; i < joukkueidenMaara; i++)
    {
        printf("\n%d. joukkue:          ", i + 1);
        tulostaSarjataulukko(sarjataulukko[pelit[i]]);
    }

    return(0);
}

joukkueTietue lueJoukkueenTiedot(void)
{
    joukkueTietue st;

    katkaise(fgets(st.joukkueenNimi, 30, stdin));
    scanf("%d", &st.voittojenMaara);
    scanf("%d", &st.tappioidenMaara);
    luepois();
    
    return(st);
}

void tulostaSarjataulukko(joukkueTietue st)
{
    printf("%s tilanne: %d voittoa ja %d tappiota", st.joukkueenNimi, st.voittojenMaara, st.tappioidenMaara);
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


void vaihda(int arr[], int arr2[], int arr3[], int n)
{
    int temp1, temp2, temp3;
    int max_idx;

    for (int i = 0; i < n - 1; i++)
    {
        max_idx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr2[j] > arr2[max_idx] | arr2[j] == arr2[max_idx] && arr3[j] < arr3[max_idx])
                max_idx = j;
        }

        swap(&arr[max_idx], &arr[i]);
        swap(&arr2[max_idx], &arr2[i]);
        swap(&arr3[max_idx], &arr3[i]);
    }
}

void swap(int* xp, int* yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 