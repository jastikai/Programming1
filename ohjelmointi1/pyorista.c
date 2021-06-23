/* 
Ohjelmointi 1
Ohjelmointitehtävä 26

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void pyoristaKokonaisluvuksi(double);
void pyoristaKymmenesosat(double);
void pyoristaSadasosat(double);
void pyoristaTuhannesosat(double);

int main(void)
{
    double x;
    
    for (int i = 1; i <= 5; i++)
    {
        scanf("%lf", &x);
        pyoristaKokonaisluvuksi(x);
        pyoristaKymmenesosat(x);
        pyoristaSadasosat(x);
        pyoristaTuhannesosat(x);
    }
    return(0);
}

void  pyoristaKokonaisluvuksi(double z)
{
    double y;

    y = floor(z + 0.5);
    printf("%lf %lf\n", z, y);
}

void  pyoristaKymmenesosat(double z)
{
    double y;

    y = floor(z*10 + 0.5)/10;
    printf("%lf %lf\n", z, y);
}

void  pyoristaSadasosat(double z)
{
    double y;

    y = floor(z*100 + 0.5)/100;
    printf("%lf %lf\n", z, y);
}

void  pyoristaTuhannesosat(double z)
{
    double y;

    y = floor(z*1000 + 0.5)/1000;
    printf("%lf %lf\n", z, y);
}