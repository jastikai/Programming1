/* 
Ohjelmointi 1
Ohjelmointitehtävä 38

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>

int isLeapYear(int year);

int main(void)
{
    int year;

    scanf("%d", &year);

    if (isLeapYear(year))
        printf("Vuosi %d on karkausvuosi", year);
    else
        printf("Vuosi %d ei ole karkausvuosi", year);

    return(0);
}

int isLeapYear(int year)
{
    int test = 0;

    if (year % 4 == 0 && year % 100 != 0)
        test = 1;
    else if (year % 100 == 0 && year % 400 == 0)
        test = 1;

    return(test);
}