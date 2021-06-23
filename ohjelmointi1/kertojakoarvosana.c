/* 
Ohjelmointi 1
Ohjelmointitehtävä 35

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int createProblem(void);
int testInput(int input, int testValue);
int division(void);
int multiplication(void);
int isComposite(int a, int b);

int main(void)
{
    srand(time(NULL));

    int input;
    int correctAns;
    int countCorrect = 0, countIncorrect = 0;

    while(1)
    {
        correctAns = createProblem();
        scanf("%d", &input);

        if (input == -1)
            break;
        if (testInput(input, correctAns))
        {
            printf("Oikein!\n");
            countCorrect++;
        }
        else
        {
            printf("Väärin\n");
            countIncorrect++;
        }
    }

    printf("Sait %d vastausta oikein, ja %d meni pikkuisen pieleen\n", countCorrect, countIncorrect);
    if (countCorrect >= countIncorrect)
        printf("Arvosanasi on : \"Hyvaksytty\"");
    else
        printf("Arvosanasi on : \"Hylatty\"");
    return(0);
}

int createProblem(void)
{
    int temp;
    int ans;
    temp = rand();
    if (temp % 2 == 0)
        ans = multiplication();
    else
        ans = division();

    return(ans);
}

int division(void)
{
    int numOne, numTwo;
    int product;

    do
    {
        numOne = rand() % 10;
        numTwo = rand() % 10;
    } while(isComposite(numOne, numTwo) == 0 | numOne == 0 | numTwo == 0);

    product = numOne / numTwo;

    printf("Paljonko on %d jaettuna %d?", numOne, numTwo);

    return(product);
}

int multiplication(void)
{
    int numOne, numTwo;
    int product;

    do
    {
        numOne = rand() % 10;
        numTwo = rand() % 10;
    } while (numOne == 0 | numTwo == 0);
        
    product = numOne * numTwo;

    printf("Paljonko on %d kertaa %d?", numOne, numTwo);

    return(product);
}

int testInput(int input, int testValue)
{

    if (input == testValue)
        return(1);
    else
        return(0);   
}

int isComposite(int a, int b)
{
    if (a == 0 | b == 0)
        return(0);
    else if (a % b != 0)
        return(0);
    else
        return(1);
}