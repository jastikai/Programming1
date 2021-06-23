/* 
Ohjelmointi 1
Ohjelmointitehtävä 22

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    //Muuttujat
    int input;
    double denom;
    double result;
    double digits;
    int exponent;
    int sum;

    //Alkuarvoja
    denom = 10;
    sum = 0;

    scanf("%d", &input);

    for (int i = 0; i <= 4; i++)
    {
        exponent = pow(2, i);
        digits = (double)input / denom;
        digits = digits - (int)digits;
        digits = digits * 10.0;
        digits = floor(digits + 0.01);
        //printf("%d\n", exponent);

        sum = sum + (digits * exponent);
        //printf("%d\n", sum);
        denom = denom * 10;
    }

    printf("%d", sum);
    return(0);
}