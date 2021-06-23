/* 
Ohjelmointi 1
Ohjelmointitehtävä 62

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} koordinaatit;

double laskeEtaisyys(double x1, double y1, double x2, double y2);

int main(void)
{
    double x1, y1, x2, y2;
    double kokoMatka;
    double etaisyys;
    double linnuntie;

    koordinaatit xy[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%lf", &xy[i].x);
        scanf("%lf", &xy[i].y);
    }

    for (int i = 1; i < 5; i++)
    {
        etaisyys = laskeEtaisyys(xy[i - 1].x, xy[i - 1].y, xy[i].x, xy[i].y);
        kokoMatka += etaisyys;
    }

    linnuntie = sqrt(pow(xy[4].x - xy[0].x, 2) + pow(xy[4].y - xy[0].y, 2));

    printf("\nEtaisyys mutkitellen on %.3lf", kokoMatka);
    printf("\nAlku ja loppupisteiden valinen etaisyys on %.3lf", linnuntie);

    return(0);
}

double laskeEtaisyys(double x1, double y1, double x2, double y2)
{
    double etaisyys;

    etaisyys = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    return(etaisyys);
}