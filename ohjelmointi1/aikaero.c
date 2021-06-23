/* 
Ohjelmointi 1
Ohjelmointitehtävä 29

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>

int timeToSeconds(int hours, int minutes, int seconds);

int main(void)
{
    //Muuttujat
    int hoursOne, minutesOne, secondsOne;
    int hoursTwo, minutesTwo, secondsTwo;
    int totalSecOne, totalSecTwo;
    int secDifference, totalSecDiff;
    int diffHour, diffMin, diffSec;

    //Alkuarvot
    scanf("%d", &hoursOne);
    scanf("%d", &minutesOne);
    scanf("%d", &secondsOne);

    scanf("%d", &hoursTwo);
    scanf("%d", &minutesTwo);
    scanf("%d", &secondsTwo);

    totalSecOne = timeToSeconds(hoursOne, minutesOne, secondsOne);
    totalSecTwo = timeToSeconds(hoursTwo, minutesTwo, secondsTwo);
    secDifference = abs(totalSecTwo - totalSecOne);
    totalSecDiff = secDifference;
    diffHour = secDifference / (60 * 60);
    secDifference = secDifference - (diffHour * 60 * 60);
    diffMin = secDifference / 60;
    secDifference = secDifference - (diffMin * 60);
    diffSec = secDifference;

    printf("Aikaero on: %d sekuntia\n", totalSecDiff);
    printf("Aika on %d tuntia %d minuuttia %d sekuntia\n", diffHour, diffMin, diffSec);

    return(0);
}

int timeToSeconds(int h, int m, int s)
{
    int seconds = s;
    seconds = seconds + (h * 60 * 60);
    seconds = seconds + (m * 60);

    return(seconds);
}