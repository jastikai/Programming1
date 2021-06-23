/* 
Ohjelmointi 1
Ohjelmointitehtävä 43

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    int summa;
    int summat[11] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int heitot[11] = {0};
    int noppaYksi, noppaKaksi;


    for (int i = 1; i <= 36000; i++)
    {   
        do
        {
            noppaYksi = rand() % 7;
            noppaKaksi = rand() % 7;
        } while(noppaYksi == 0 | noppaKaksi == 0);

        summa = noppaYksi + noppaKaksi;
        for (int j = 2; j <= 12; j++)
        {
            if (summa == summat[j - 2])
            {
                heitot[j - 2] = heitot[j - 2] + 1;
            }
        }
    }

    // printf("Summa   Lukumäärä\n");
    for (int i = 0; i <= 10; i++)
    {
        printf("%8d%9d\n", summat[i], heitot[i]);
    }
    printf("YHTEENSA%9d", 36000);

    return(0);
}