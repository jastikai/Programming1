/* 
Ohjelmointi 1
Ohjelmointitehtävä 32

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int tossCoin(void);

int main(void)
{
    srand(time(NULL));

    int headsCounter = 0;
    int tailsCounter = 0;

    for (int i = 1; i <= 100; i++)
    {
        if (tossCoin())
            headsCounter++;
        else
            tailsCounter++;
    }

    printf("Heittojen tulos: %d kruunua ja %d klaavaa", headsCounter, tailsCounter);

    return(0);
}

int tossCoin(void)
{
    int heads, tails;
    int result;
    heads = 0;
    tails = 1;

    result = rand();

    if (result % 2 == 0)
        result = heads;
    else
        result = tails;

    return(result);
}