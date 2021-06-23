/* 
Ohjelmointi 1
Ohjelmointitehtävä 39

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>

int isLeapYear(int year);
int daysInMonth(int month, int year);
int countDays(int yearOne, int monthOne, int dayOne, int yearTwo, int monthTwo, int dayTwo);

int main(void)
{
    int yearOne, monthOne, dayOne;
    int yearTwo, monthTwo, dayTwo;
    int howManyDays;

    scanf("%d", &yearOne);
    scanf("%d", &monthOne);
    scanf("%d", &dayOne);
    scanf("%d", &yearTwo);
    scanf("%d", &monthTwo);
    scanf("%d", &dayTwo);

    if (yearOne > yearTwo)
    {
        printf("**** Aloitusvuosi on myöhempi kuin lopetusvuosi");
        return(0);
    }
    else if (yearOne == yearTwo && monthOne == monthTwo && dayOne == dayTwo)
    {
        printf("Paivaykset ovat samat!");
        return(0);
    }
    else if (yearOne == yearTwo && monthOne > monthTwo)
    {
        printf("**** Koska aloitusvuosi on sama kuin lopetusvuosi\n**** niin, aloituskuukausi ei voi olla suurempi kuin lopetuskuukausi!");
        return(0);
    }
    else if (yearOne == yearTwo && monthOne == monthTwo && dayOne > dayTwo)
    {
        printf("**** Koska aloitusvuosi on sama kuin lopetusvuosi\n**** ja aloituskuukausikin on sama kuin lopetuskuukausi\n**** niin aloituspäivä ei olla suurempi kuin lopetuspäivä!");
        return(0);
    }

    howManyDays = countDays(yearOne, monthOne, dayOne, yearTwo, monthTwo, dayTwo);
    printf("%d.%d.%d ja %d.%d.%d valilla on %d paivaa", yearOne, monthOne, dayOne, yearTwo, monthTwo, dayTwo, howManyDays);
    
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

int daysInMonth(int month, int year)
{

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
        days[1] = 29;
    
    // if (isLeapYear(year))
    //     int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // else
    //     int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int nrDays;
    

    if (month > 12 | month < 1)
        return(-1);
    else
    {
        nrDays = days[month - 1];
        return(nrDays);
    }
}

int countDays(int yearOne, int monthOne, int dayOne, int yearTwo, int monthTwo, int dayTwo)
{
    int dayCounter = 0;
    int startMonth;
    int endMonth;
    int startDay;
    int endDay;

    for (int i = yearOne; i <= yearTwo; i++)
    {
        if (i > yearOne)
            startMonth = 1;
        else
            startMonth = monthOne;
        
        if (i < yearTwo)
            endMonth = 12;
        else
            endMonth = monthTwo;
        
        for (int j = startMonth; j <= endMonth; j++)
        {
            if (j == monthOne && i == yearOne)
                startDay = dayOne;
            else
                startDay = 1;
            
            if (j == monthTwo && i == yearTwo)
                endDay = dayTwo;
            else
                endDay = daysInMonth(j, i);

            // dayCounter = dayCounter + daysInMonth(j, i);
            for (int k = startDay; k <= endDay; k++)
            {
                dayCounter++;
            }
        }
    }

    return(dayCounter - 1);
}