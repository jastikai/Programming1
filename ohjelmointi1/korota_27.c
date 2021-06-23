/* 
Ohjelmointi 1
Ohjelmointitehtävä 28

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>

int raiseToPower(int x, int y);

int main(void)
{
    int input;
    int result;
    int exponent;

    scanf("%d", &input);
    scanf("%d", &exponent);

    result = raiseToPower(input, exponent);
    printf("Luku %d korotettuna potenssiin %d on %d", input, exponent, result);

    return(0);
}

int raiseToPower(int x, int y)
{
    int result;
    result = x;
    if (y == 0)
        x = 1;
    else
    {
        for (int i = 1; i < y; i++)
        result = result * x;
    }
    return(result);
}