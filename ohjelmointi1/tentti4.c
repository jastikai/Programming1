#include <stdio.h>

#define COEFFICIENT 1.609;

int main( void ){

   double miles, kilometers;
   
   printf("Enter the mileage > ");
   scanf("%lf", &miles);
   
   kilometers = COEFFICIENT * miles;
   
   printf("\n%f mailes is %f kilometers\n", miles, kilometers);
   
   return 0;   
}