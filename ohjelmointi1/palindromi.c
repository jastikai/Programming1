/* 
Ohjelmointi 1
Ohjelmointitehtävä 13

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    //Muuttujat
    int kokonaisluku;
    int luku;
    double luku2;
    int temp;
    double temp2;
    int jakaja;
    double jakaja2;
    double jakojaannos;
    int temp3;
    int i;

    //Määritetään alkuarvot
    jakaja = 1;
    jakaja2 = 1;

    //Pyydetään kokonaisluku
    scanf("%d", &kokonaisluku);
    temp = kokonaisluku;
    luku = kokonaisluku;
    luku2 = kokonaisluku;

    
    if (abs(luku) < 10000 || luku < 0)
    {
        printf("Syote ei ole viisinumeroinen positiivinen kokonaisluku");
        return(0);
    }

    //Tehdään tarpeeksi iso jakaja, jotta saadaan aina yksi desimaali ulos luvusta tulostettavaksi.
    while(temp)
    {
        temp = temp/10;
        jakaja = jakaja*10;
    }

    temp3 = 0;
    while(jakaja > 1)
    {
        jakaja = jakaja/10;
        jakaja2 = jakaja2*10;
        jakojaannos = luku2 / jakaja2;
        temp3 = temp3 + (luku/jakaja)*jakaja2;
        luku = luku % jakaja;
        
    }
    if (temp3/10 == kokonaisluku)
        printf("Luku %d on palindromi", kokonaisluku);
    else
        printf("Luku %d ei ole palindromi", kokonaisluku);
    
    return(0);
}