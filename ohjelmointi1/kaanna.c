/* 
Ohjelmointi 1
Ohjelmointitehtävä 31

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int flip(int n);

int main(void)
{
    int input;
    int flipped;

    scanf(" %d", &input);
    flipped = flip(input);

    printf("Luku %d kaannettyna on %d", input, flipped);

    return(0);
}

int flip(int n)
{
    double denom = 10.0;
    double digits;
    int multiplier;
    int output = 0;
    int rounds;

    if (n > 0 && n <= 10)
        multiplier = 1;
    if (n > 10 && n <= 100)
        multiplier = 10;
    if (n > 100 && n <= 1000)
        multiplier = 100;
    if (n > 1000 && n <= 10000)
        multiplier = 1000;


    for (int i = 1; i <= rounds; i++)
    {
        digits = (double)n / denom;
        digits = digits - (int)digits;
        digits = digits * 10;
        digits = floor(digits + 0.01);

        output = output + (digits * multiplier);

        denom = denom * 10;
        multiplier = multiplier / 10;
    }

    return(output);
}