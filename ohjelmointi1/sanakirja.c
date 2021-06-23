/* 
Ohjelmointi 1
Ohjelmointitehtävä 67

Jaakko Astikainen
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char filename[20];
    char suomi[30];
    char englanti[30];
    char sana[30];
    char rivi[30];
    FILE *input;
    int pituus;
    int k;

    //scanf("%s", filename);
    //getchar();

    input = fopen("sanakirja.txt", "r");

    scanf("%s", sana);
    getchar();

    while(!feof(input))
    {

        //fgets(rivi, 30, input);
        //strtok(rivi, ";");

        fscanf(input, "%s", rivi);
        printf("\n%s", rivi);
        pituus = strlen(rivi);
        //strtok(rivi, ";");
        
        for (int i = 0; i < pituus; i++)
        {
            suomi[i] = rivi[i];
            
            if (rivi[i] == ';')
            {

                suomi[i] = '\0';
                k = 0;
                
                for (int j = i + 1; j < pituus; j++)
                {
                    englanti[k] = rivi[j];
                    k++;
                }
                englanti[k] = '\0';
                break;
            }
        }
        
        //printf("\n%s", suomi);
        //printf("\n%s", englanti);
        //getchar();

        if (strcmp(suomi, sana) == 0)
        {
            printf("\nSana %s englanniksi on %s", suomi, englanti);
            fclose(input);
            return(0);
        }
        if (strcmp(englanti, sana) == 0)
        {
            printf("\nSana %s suomeksi on %s", englanti, suomi);
            fclose(input);
            return(0);
        }

    }

    printf("\nSanaa %s ei loytynyt sanakirjasta", sana);
    fclose(input);
    return(0);
}