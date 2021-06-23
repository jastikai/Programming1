#include <stdio.h>

int main(void){
   int num1, num2, temp;
   
   printf("Give an integer > ");
   scanf("%d", &num1);
   
   printf("Give another integer > ");
   scanf("%d", &num2);
   
   printf("Numbers before if are: %d and %d\n", num1, num2);
   
   if( num1 < num2 )
   {
      temp = num2;
      num2 = num1;
      num1 = temp;
   }
   
   printf("Numbers after if are: %d and %d\n", num1, num2);
   
   return 0;         
}

int doSomething( int * arr , int size ){
    
    int i= size-1;
    int x = arr[i];
    
    for( i=size-1; i >= 0; i--)
        if( arr[i] < x )
            x = arr[i];
    
    return x;    
}
