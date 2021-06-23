/* 
Ohjelmointi 1
Ohjelmointitehtävä 44

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void taytaTaulukko(int * taulukko);
int tarkistaArvot(int taulukko[], int vertailuArvo);
void tulostaTaulukko(int taulukko[]);

int main(void)
{   
    srand(time(NULL));

    int taulukko[20] = {0};

    taytaTaulukko(taulukko);

    tulostaTaulukko(taulukko);

    return(0);
}

void taytaTaulukko(int * taulukko)
{   
    int testi;
    int vertailuTaulukko[20] = {0};

    for (int j = 0; j <= 19; j++)
    {
        vertailuTaulukko[j] = j + 1;
    }

    for (int i = 0; i <= 19; i++)
    {   
        do
        {
            taulukko[i] = rand() % 21;
            // testi = tarkistaArvot(taulukko, taulukko[i]);
            // printf("%d\n", testi);
            

        } while(taulukko[i] < 1 | vertailuTaulukko[taulukko[i] - 1] == 0);
        // printf("%d\n", taulukko[i]);
        vertailuTaulukko[taulukko[i] - 1] = 0;
    }
}

int tarkistaArvot(int taulukko[], int vertailuArvo)
{   
    
    for (int i = 0; i <= 19; i++)
    {
        printf("%d\n", taulukko[i]);
        if (taulukko[i] == vertailuArvo)
            return(0);
    }

    return(1);
}

void tulostaTaulukko(int taulukko[])
{   
    for (int i = 0; i <= 19; i++)
    {
        printf("%d\n", taulukko[i]);
    }
}