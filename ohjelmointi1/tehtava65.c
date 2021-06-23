#include <stdio.h>

int main(void)
{
    
    FILE *tiedosto1;
    FILE *tiedosto2;
    int ch1, ch2;
    
    char nimi1[20];
    char nimi2[20];
    
    fgets(nimi1, 20, stdin);
    fgets(nimi2, 20, stdin);
    
    tiedosto1 = fopen(nimi1, "r");
    tiedosto2 = fopen(nimi2, "r");
    
    for (ch1 = fgetc(tiedosto1); ch1 != EOF; ch1 = fgetc(tiedosto1))
    {
        ch2 = fgetc(tiedosto2);
        
        if (ch2 == EOF)
        {
            printf("Tiedostot eivät ole sisällöltään identtiset.");
            fclose(tiedosto1);
            fclose(tiedosto2);
            return(0);
        }
        if (ch1 != ch2)
        {
            printf("Tiedostot eivät ole sisällöltään identtiset.");
            fclose(tiedosto1);
            fclose(tiedosto2);
            return(0);
        }
    }
    
    fclose(tiedosto1);
    fclose(tiedosto2);
    printf("Tiedostot ovat sisällöltään identtiset.");
    return(0);
}