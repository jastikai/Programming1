#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    
    int size = 6;
    int i= size-1;
    int arr[6] = {1,-1,6,7,3,9};
    int x = arr[i];
    
    for( i=size-1; i >= 0; i--)
        if( arr[i] < x )
            x = arr[i];
    

    printf("%d", x);

    return (0);
}