/* 
Ohjelmointi 1
Ohjelmointitehtävä 36

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int createNum(void);
int checkNum(int a, int b);

int main(void)
{
    srand(time(NULL));

    int number;
    int guess;
    int input;
    int temp = 'k';

    number = createNum();

    while(1)
    {
        scanf(" %d", &guess);
        getchar();

        if (checkNum(number, guess))
        {
            printf("OIKEIN!\nHaluatko yrittaa uudelleen (vastaa k, jos haluat jatkaa ja e jos et halua jatkaa pelia)?\n");
            input = getchar();
            // printf("%d", input);
            if (input == 'k')
                number = createNum();
            else
                break;
        }
        else if (number > guess)
            printf("Liian pieni luku, yrita uudelleen.\n");
        else if (number < guess)
            printf("Liian suuri luku, yrita uudelleen.\n");
    }

    return(0);
}

int createNum(void)
{
    int num;
    do
    {
        num = rand() % 100;
    } while(num == 0);

    return(num);
}

int checkNum(int a, int b)
{
    if (a == b)
        return(1);
    else
        return(0);
}