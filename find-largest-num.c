/*
  Program Name: find-largest-num.c
  Description: Enter a bunch of numbers, returns the largest entered.
*/
#include <stdio.h>

int main(){
  float num, largest=1;
  
  do {
    printf("Enter a number: ");
    scanf("%f", &num);
    
    if (num > largest)
      largest = num;
    
  } while (num > 0);
  

  printf("The largest number entered was %g\n", largest);
  
  return 0;
}
