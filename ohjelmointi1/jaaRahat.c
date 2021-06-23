/* 
Ohjelmointi 1
Kotitehtävä 5

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    //Muuttujat
    int summa;
    int setelitArvot[2] = {50, 20};
    int setelitLkm[2] = {0};
    int osamaara;
    int temp;

    //Pyydetään käyttäjältä haluttu rahasumma, tarkistetaan että summa on oikeanlainen.

    printf("\nAnna haluamasi summa: ");
    do
    {
        scanf("%d", &summa);
    } while(summa < 20 | summa > 1000 | summa % 10 != 0 | summa == 30);

    //Aletaan jakaa summa seteleihin.

    for (int i = 0; i <= 1; i++)
    {
        osamaara = summa / setelitArvot[i];
        temp = osamaara * setelitArvot[i];

        if ((summa - temp) % 20 != 0)
        {
            osamaara--;
            temp = osamaara * setelitArvot[i];
        }

        summa = summa - temp;
        setelitLkm[i] = osamaara;
    }

    //Tulostetaan annettavien setelien lukumäärät.

    for (int i = 0; i <= 1; i++)
    {
        printf("\n%d €: ", setelitArvot[i]);
        printf("%d", setelitLkm[i]);
    }

    return(0);
}