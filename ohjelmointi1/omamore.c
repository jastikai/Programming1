/* 
Ohjelmointi 1
Ohjelmointitehtävä 66

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    FILE * input;
    char tuloste[100];
    char filename[20];
    char c;
    int ch;
    int i;

    scanf("%s", filename);
    //getchar();
    input = fopen(filename, "r");

    do
    {
        for (int i = 0; i < 20; i++);
        {
            fgets(tuloste, 100, input);

            fputs(tuloste, stdout);
        }
        c = getchar();
    } while(c != 'q' && !feof(input));

    fclose(input);

    return(0);
}