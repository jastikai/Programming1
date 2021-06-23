/* 
Ohjelmointi 1
Ohjelmointitehtävä 9

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Muuttujat
    int pisteet;

    scanf("%d", &pisteet);

    if (pisteet >= 0 && pisteet <= 11)
        printf("Hylatty");
    if (pisteet >= 12 && pisteet <= 13)
        printf("%d", 1);
    if (pisteet >= 14 && pisteet <= 16)
        printf("%d", 2);
    if (pisteet >= 17 && pisteet <= 19)
        printf("%d", 3);
    if (pisteet >= 20 && pisteet <= 22)
        printf("%d", 4);
    if (pisteet >= 23 && pisteet <= 24)
        printf("%d", 5);
    if (pisteet < 0 || pisteet > 24)
        printf("Virheellinen pistemaara");

    return(0);
}