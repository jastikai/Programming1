/* 
Ohjelmointi 1
Ohjelmointitehtävä 23

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int n);

int main()
{
    double e;           //e:n tulosmuuttuja.
    //e = 0.0;

    for (int i = 0; i <= 9; i++)
    {
        
        e = e + (1.0 / factorial(i));
        //printf("%d\n", factorial(i));
        printf("%.6lf\n", e);
    }
    return 0;
}

int factorial(int n)
{
    int product = 1;
    int j = 0;

    for (j = n; j >= 1; j--)
    {
        product = product * j;
    }

    return(product);
}