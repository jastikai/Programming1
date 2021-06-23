/* 
Ohjelmointi 1
Ohjelmointitehtävä 33

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int createProblem(void);
int testInput(int input, int testValue);

int main(void)
{
    srand(time(NULL));

    int correctAns;
    int input;

    printf("Anna luku -1 lopettaaksesi\n");
    correctAns = createProblem();

    while(1)
    {
        scanf("%d", &input);
        if (testInput(input, correctAns))
        {
            printf("Oikein!");
            break;
        }
        else
            printf("Väärin, yritä uudelleen >");
    }

    return(0);
}

int createProblem(void)
{
    int numOne, numTwo;
    int product;

    numOne = rand() % 10;
    numTwo = rand() % 10;
    if (numOne == 0)
        numOne++;
    if (numTwo == 0)
        numTwo++;
        
    product = numOne * numTwo;

    printf("Paljonko on %d kertaa %d?", numOne, numTwo);

    return(product);
}

int testInput(int input, int testValue)
{
    if (input == -1)
        exit(0);
    
    if (input == testValue)
        return(1);
    else
        return(0);
    
}