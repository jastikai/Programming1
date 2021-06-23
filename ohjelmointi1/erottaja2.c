#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[5];

    scanf("%s", &str);
    printf("Luku %d eroteltuna: ", atoi(str));
    printf("%c %c %c %c %c", str[0], str[1], str[2], str[3], str[4], str[5]);
    
    return(0);
}