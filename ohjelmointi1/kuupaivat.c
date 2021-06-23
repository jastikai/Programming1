/* 
Ohjelmointi 1
Ohjelmointitehtävä 37

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>

int paivienLukumaaraKuukaudessa (int kk);

int main(void)
{
    int paivat;
    int kk;

    scanf("%d", &kk);

    paivat = paivienLukumaaraKuukaudessa(kk);

    if (paivat == -1)
        printf("Kuukautta %d ei ole olemassa", kk);
    else
        printf("Kuukaudessa %d on %d paivaa", kk, paivat);

    return(0);
}

int paivienLukumaaraKuukaudessa (int kk)
{
    int paivat[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int pvLkm;
    

    if (kk > 12 | kk < 1)
        return(-1);
    else
    {
        pvLkm = paivat[kk - 1];
        return(pvLkm);
    }
}