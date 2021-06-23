/* 
Ohjelmointi 1
Ohjelmointitehtävä 25

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void floorAndPrint(double x);

int main(void)
{
    double x;

    for (int i = 1; i <= 5; i++)
    {
        floorAndPrint(x);
    }

    return(0);
}

void  floorAndPrint(double z)
{
    double y;

    scanf("%lf", &z);
    y = floor(z + 0.5);
    printf("%lf\n%lf\n", z, y);
}