/*
Ohjelmointi 1
Lopputyö


Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tulostetaan tilin saldoon liittyvää tietoa.
int tarkistaSaldo(int saldo, int nostettavissa, int nostoVara);
// Funktio, jolla nostetaan rahaa nostettavissa olevasta saldosta.
void nostaRahaa(int * saldo, int * nostettavissa, int nostoVara);
// Puheajan ostamisen funktio.
void lataaPuheaikaa(void);
// Tilitapahtumien tulostamisen funktio.
void tiliTapahtumat(void);
//Simuloidaan kortin lukua.
void lueKortti(char * jono);
//Merkkijonojen katkaisuun ja näppäimistöpuskurin tyhjennykseen funktiot.
void luepois(void); 
void katkaise(char * jono);


int main(void)
{
    //Muuttujia
    int userInput;
    int pinKoodi;
    int oikeaKoodi;
    int tiliNro;
    // int saldo = 10000;
    int saldo;
    // int nostettavissa = 9900;
    int nostettavissa;
    int nostoVara = 400;
    FILE *tiliTiedot;
    char filename[256];

    do
    {
        printf("\nTervetuloa!\nSyötä kortti (=tilinumero), ole hyvä\n");
        lueKortti(filename);
        strcat(filename, ".tili");
        tiliTiedot = fopen(filename, "r");
        if (tiliTiedot == NULL)
            printf("\nTilinumerolla ei löytynyt tiliä.\n");
    } while(tiliTiedot == NULL);

    //Tämä rivi lukee oikean tunnusluvun sekä tilin saldon.
    fscanf(tiliTiedot, "%d%d", &oikeaKoodi, &saldo);
    nostettavissa = saldo;

    do
    {
        printf("\nNäppäile tunnusluku\nSuojaa tunnuslukusi\n\nLopuksi paina OK (enter)\n");
        scanf("%d", &pinKoodi);
        luepois();

        if (pinKoodi != oikeaKoodi)
            printf("\nVäärä tunnusluku!\n");

    } while(pinKoodi != oikeaKoodi);

    while(1)
    {
        //Tulostetaan käyttäjälle päävalikon vaihtoehdot
        printf("\nValitse\nVoit lopettaa STOP-näppäimellä\n\n1. Liittymän lataus\n   Puheaika\n2. Otto\n3. Saldo\n4. Tapahtumat\n5. STOP\n\n");

        //Luetaan käyttäjän syöte
        do
        {
            scanf("%d", &userInput);
            luepois();
        } while(userInput < 1 | userInput > 5);

        //Siirrytään syötteen valitsemaan toimintoon
        if (userInput == 1)
        {
            lataaPuheaikaa();

            //break;

        }
        if (userInput == 2)
        {
            nostaRahaa(&saldo, &nostettavissa, nostoVara);

            //break;
        }
        if (userInput == 3)
        {
            nostettavissa = tarkistaSaldo(saldo, nostettavissa, nostoVara);
        }
        if (userInput ==4)
        {
            tiliTapahtumat();
        }
        if (userInput == 5)
            //Poistutaan while-loopista, jos STOP-näppäintä painetaan
            break;
    }

    fclose(tiliTiedot);
    printf("\nKiitos käynnistä\nTervetuloa uudelleen.\n");
    printf("\nPaina enter lopettaaksesi\n");
    getchar();
    return(0);
}


//Funktioiden prototyypit.


int tarkistaSaldo(int saldo, int nostettavissa, int nostoVara)
{

    //Tulostetaan tilin saldoon liittyvä tieto
    printf("\nTilin tilanne\n\n");
    printf("Tilin saldo %d euroa\n", saldo);
    printf("Tililtä nostettavissa %d euroa\n", nostettavissa);
    printf("Kortin käteisnostovara %d euroa\n", nostoVara);
    printf("Lopeta (enter)\n");

    getchar();

    return(nostettavissa);
    //return(0);
}

void nostaRahaa(int * saldo, int * nostettavissa, int nostoVara)
{
    int nostoSumma;

    
    
    do
    {
        printf("\nValitse haluamasi summa\n");
        scanf("%d", &nostoSumma);
        luepois();
    
        if (nostoSumma > *nostettavissa | nostoSumma > nostoVara)
        {
            printf("Ei tarpeeksi katetta tilillä tai nostoraja ylittyi.\n");
        }
        else if (nostoSumma % 10 != 0)
        {
            printf("\nAnna summa kymmenen euron tarkkuudella.\n");
        }
        else if (nostoSumma <= 0)
        {
            printf("\nEi sallittu summa.\n");
        }
        else
        {    
            *nostettavissa = *nostettavissa - nostoSumma;
            *saldo = *saldo - nostoSumma;
        }
    } while(nostoSumma > *nostettavissa | nostoSumma > nostoVara | nostoSumma % 10 != 0 | nostoSumma <= 0);

    //Ohjeita ja muita tietoja tulostetaan käyttäjälle
    printf("\nHaluatko tiedot?\n");
    printf("\nOta kortti ja rahat.\n");
}

void lataaPuheaikaa(void)
{
    //Tulostetaan puheajan latauksen kehotteet
    printf("\nLiittymän lataus\nValitse palvelu\n\n1. Saunalahti\n2. dna\n3. Go Mobile\n");
    printf("\nSyötä [operaattori] puhelinnumero (esim. 041492...)\n\n");
    printf("_ _ _ _ _ _ _ _ _ _\n\n");
    printf("ja paina OK (enter)\n");
            

    printf("\nValitse haluamasi summa\nHyväksy maksu (enter)\n");
    getchar();
    printf("Tapahtumaasi käsitellään\n");
}

void tiliTapahtumat(void)
{
    //Pyydetään valitsemaan mihin tiedot halutaan
    printf("\nHaluatko tiedot? (paina enter)\n\n1. Näytölle\n2. Kuitille\n");
    getchar();
}

void lueKortti(char * jono)
{
    //Kortin lukua simuloidaan pyytämällä tilinumero, jonka perusteella etsitään tilin tietoja .tili-tiedostoista.
    katkaise(fgets(jono, 256, stdin));
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