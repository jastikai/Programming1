/* 
Ohjelmointi 1
Ohjelmointitehtävä 7

Jaakko Astikainen
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Muuttujat
    int luku1;
    int luku2;

    /*
    scanf("%d", &luku1);
    do
    {
        scanf("%d", &luku2);
    } while (luku2 == 0);
    */
    
    scanf("%d", &luku1);
    scanf("%d", &luku2);
    
    if (luku2 == 0)
    {
        return(0);
    }

    if (luku1 % luku2 == 0)
    {
        printf("Luku %d on luvun %d monikerta.", luku1, luku2);
    }
    if (luku1 % luku2 != 0)
    {
        printf("Luku %d ei ole luvun %d monikerta.", luku1, luku2);
    }
    return(0);
}