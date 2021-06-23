/* 
Ohjelmointi 1
Ohjelmointitehtävä 10

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Muuttujat
    int pisteet;

    scanf("%d", &pisteet);

    switch (pisteet)
    {
    case 0 ... 11:
        printf("Hylatty");
        break;
    case 12 ... 13:
        printf("%d", 1);
        break;
    case 14 ... 16:
        printf("%d", 2);
        break;
    case 17 ... 19:
        printf("%d", 3);
        break;
    case 20 ... 22:
        printf("%d", 4);
        break;
    case 23 ... 24:
        printf("%d", 5);
        break;
    default:
        printf("Virheellinen pistemaara");
        break;
    }

    return(0);
}