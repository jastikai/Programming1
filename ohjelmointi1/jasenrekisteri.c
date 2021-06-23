/* 
Ohjelmointi 1
Ohjelmointitehtävä 61

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define REKISTERIN_KOKO 30

typedef struct {
char kokoNimi[100];
char etunimi[100];
char sukunimi[100];
int jasennro;
int vuosi;
int maksu2016;
int maksu2017;
int maksu2018;
int maksu2019;
int maksu2020;
} jasenrekisteri, *rekPtr;

void luepois(void);
void katkaise(char * jono);
jasenrekisteri lueTiedot(void);
void tulostaJas(jasenrekisteri rek);
void poistaJas(int *pointer);
void haeJas(jasenrekisteri rek);
jasenrekisteri muutaTiedot(jasenrekisteri rek);



int main(void)
{
    int valinta;
    int laskuri = 0;
    int *ptr;
    jasenrekisteri rekisteri[REKISTERIN_KOKO];
    int pointerit[100];
    int jsnNro;
    char hakuEtunimi[100];
    char hakuSukunimi[100];
    int hakunumero;
    int hakuvuosi;
    int jasennumerot[REKISTERIN_KOKO];
    int ylitys = 0;
    jasenrekisteri *temp;
    

    do
    {
        printf("\n1 Uuden jasenen lisaaminen\n2 Jasenen tietojen poisto\n3 Jasenen tietojen muuttaminen\n4 Tulosta jasen\n5 Tulosta rekisteri\n6 Haku\n7 Lopetus\n");
        printf("\nValintasi >\n");
        scanf("%d", &valinta);
        luepois();


        switch(valinta)
        {
            case 1:
                //Lisää uusi jäsen
                // if (laskuri > REKISTERIN_KOKO)
                // {
                //     ylitys++;
                //     temp = (jasenrekisteri *)realloc(*rekisteri, (sizeof(jasenrekisteri) * (REKISTERIN_KOKO + ylitys)));
                //     *rekisteri = temp;
                // }
                rekisteri[laskuri] = lueTiedot();
                // ptr = &rekisteri[laskuri].kokoNimi;
                // printf("%d", rekisteri);
                laskuri++;
                break;
            case 2:
                //Tietojen poisto
                printf("\nAnna poistettavan jasenen jasennumero >\n");
                scanf("%d", &jsnNro);
                luepois();

                for (int i = 0; i < laskuri; i++)
                {
                    if (jsnNro == rekisteri[i].jasennro)
                    {
                        for (int j = i + 1; j < laskuri; j++)
                        {
                            rekisteri[j - 1] = rekisteri[j];
                        }
                        laskuri--;
                    }
                }

                
                break;
            case 3:
                //Tietojen muuttaminen
                printf("\nAnna muutetaavan jasenen jasennuero >\n");
                scanf("%d", &jsnNro);
                luepois();

                for (int i = 0; i < laskuri; i++)
                {
                    if (jsnNro == rekisteri[i].jasennro)
                    {
                        rekisteri[i] = muutaTiedot(rekisteri[i]);
                    }
                }


                break;
            case 4:
                //Tulosta jäsenen tiedot
                printf("\nAnna jasennumero >\n");
                scanf("%d", &jsnNro);
                luepois();

                for (int i = 0; i < laskuri; i++)
                {
                    if (jsnNro == rekisteri[i].jasennro)
                        tulostaJas(rekisteri[i]);
                }

                break;
            case 5:
                //Tulosta koko rekisteri

                for (int i = 0; i < laskuri; i++)
                {
                    tulostaJas(rekisteri[i]);
                }

                break;
            case 6:
                //Haku
                printf("\n1 Haku etunimella\n2 Haku sukunimella\n3 Haku jasennumerolla\n4 Haku liittymisvuodella\n5 Haku jasenmaksurastien perusteella\n");
                printf("\nValintasi >\n");
                scanf("%d", &valinta);
                luepois();

                switch (valinta)
                {
                    case 1:
                        printf("\nAnna etunimi > ");
                        katkaise(fgets(hakuEtunimi, 20, stdin));
                        for (int i = 0; i < laskuri; i++)
                        {
                            if (strcmp(hakuEtunimi, rekisteri[i].etunimi) == 0)
                            {
                                tulostaJas(rekisteri[i]);
                            }
                        }
                        break;
                    case 2:
                        printf("\nAnna sukunimi > ");
                        katkaise(fgets(hakuSukunimi, 30, stdin));
                        for (int i = 0; i < laskuri; i++)
                        {
                            if (strcmp(hakuSukunimi, rekisteri[i].sukunimi) == 0)
                            {
                                tulostaJas(rekisteri[i]);
                            }
                        }
                        break;
                    case 3:
                        printf("\nAnna jasennumero > ");
                        scanf("%d", &hakunumero);
                        luepois();
                        for (int i = 0; i < laskuri; i++)
                        {
                            if (hakunumero == rekisteri[i].jasennro)
                            {
                                tulostaJas(rekisteri[i]);
                            }
                        }
                        break;
                    case 4:
                        printf("\nAnna liittymisvuosi > ");
                        scanf("%d", &hakuvuosi);
                        luepois();
                        for (int i = 0; i < laskuri; i++)
                        {
                            if (hakuvuosi == rekisteri[i].vuosi)
                            {
                                tulostaJas(rekisteri[i]);
                            }
                        }
                        break;
                    case 5:
                        for (int i = 0; i < laskuri; i++)
                        {
                            if (rekisteri[i].maksu2016 == 0 | rekisteri[i].maksu2017 == 0 | rekisteri[i].maksu2018 == 0 | rekisteri[i].maksu2019 == 0 | rekisteri[i].maksu2020 == 0)
                            {
                                tulostaJas(rekisteri[i]);
                            }
                        }
                        break;
                }
                break;
        }

    } while (valinta != 7);

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

jasenrekisteri lueTiedot(void)
{
    jasenrekisteri rek;
    int pituus;
    int k = 0;

    // char * str;

    // jasenrekisteri *rek = (jasenrekisteri *) malloc(sizeof(jasenrekisteri));

    printf("\nAnna Jasenen Etu- ja Sukunimi  >\n");
    fgets(rek.kokoNimi, 100, stdin);

    pituus = strlen(rek.kokoNimi);

    strcpy(rek.etunimi, rek.kokoNimi);

    for (int i = 0; i < pituus; i++)
    {
        if (rek.etunimi[i] == ' ')
        {
            rek.etunimi[i] = '\0';
            for (int j = i + 1; j < pituus; j++)
            {
                rek.sukunimi[k] = rek.kokoNimi[j];
                k++;
            }
        } 
    }

    pituus = strlen(rek.sukunimi);
    for (int i = 0; i < pituus; i++)
    {
        if (rek.sukunimi[i] == '\n')
            rek.sukunimi[i] = '\0';
    }
  
    printf("\nAnna jasennumero >\n");
    scanf("%d", &rek.jasennro);
    printf("\nAnna liittymisvuosi >\n");
    scanf("%d", &rek.vuosi);
    printf("\nAnna vuoden 2016 jasenmaksu >\n");
    scanf("%d", &rek.maksu2016);
    printf("\nAnna vuoden 2017 jasenmaksu >\n");
    scanf("%d", &rek.maksu2017);
    printf("\nAnna vuoden 2018 jasenmaksu >\n");
    scanf("%d", &rek.maksu2018);
    printf("\nAnna vuoden 2019 jasenmaksu >\n");
    scanf("%d", &rek.maksu2019);
    printf("\nAnna vuoden 2020 jasenmaksu >\n");
    scanf("%d", &rek.maksu2020);
    luepois();
    
    return(rek);
}

void tulostaJas(jasenrekisteri rek)
{
    // printf("\n***************************\n");

    printf("\nETUNIMI: %s", rek.etunimi);
    printf("\nSUKUNIMI: %s", rek.sukunimi);
    printf("\nJASENNRO: %d", rek.jasennro);
    printf("\nLIITTVUOSI: %d\n", rek.vuosi);
}

void poistaJas(int *pointer)
{
    free(pointer);
}

jasenrekisteri muutaTiedot(jasenrekisteri rek)
{
    int valinta;
    int vuosiVal;
    int summa;

    printf("\n1 Muuta etunimi\n2 Muuta sukunimi\n3 Muuta jasennumero\n4 Muuta liittymisvuosi\n5 Muuta jasenmaksutietoja\n");
    printf("\nValintasi >\n");
    scanf("%d", &valinta);
    luepois();

    switch (valinta)
    {
        case 1:
            printf("\nAnna uusi etunimi > ");
            katkaise(fgets(rek.etunimi, 20, stdin));
            break;
        case 2:
            printf("\nAnna uusi sukunimi > ");
            katkaise(fgets(rek.sukunimi, 30, stdin));
            break;
        case 3:
            printf("\nAnna uusi jasennumero > ");
            scanf("%d", &rek.jasennro);
            break;
        case 4:
            printf("\nAnna uusi liittymisvuosi > ");
            scanf("%d", &rek.vuosi);
            break;
        case 5:
            printf("\nAnna vuosi > ");
            scanf("%d", &vuosiVal);
            switch (vuosiVal)
            {
                case 2016:
                    printf("\nAnna uusi summa > ");
                    scanf("%d", &rek.maksu2016);
                    break;
                case 2017:
                    printf("\nAnna uusi summa > ");
                    scanf("%d", &rek.maksu2017);
                    break;
                case 2018:
                    printf("\nAnna uusi summa > ");
                    scanf("%d", &rek.maksu2018);
                    break;
                case 2019:
                    printf("\nAnna uusi summa > ");
                    scanf("%d", &rek.maksu2019);
                    break;
                case 2020:
                    printf("\nAnna uusi summa > ");
                    scanf("%d", &rek.maksu2020);
                    break;

            }
    }

    return(rek);
}