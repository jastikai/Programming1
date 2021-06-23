#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse( char * str1, char * str2 );

int main( void ){

    int t[10] = {0}, i;
    
    char str1[6] = {"apple"};
    char copyOfStr[6];
    
    reverse( copyOfStr, str1 );
    copyOfStr[6] = "\0";
    printf("the copy is:  %s\n", copyOfStr);
    
    return 0;
}

void reverse( char * str1, char * str2 ){
    
    int i=0;
    int len = strlen(str2) - 1;
    
    for(i=0; i <= len; i++){
        str1[i] = str2[ len - i ];
        //printf("%c", str1[i]);
    }

}   