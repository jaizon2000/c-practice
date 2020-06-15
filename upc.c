#include <stdio.h>

int main(void){
  int a, i1, i2, i3, i4, i5,
    j1, j2, j3, j4, j5;

  // Getting barcoode input
  printf("Enter first num: ");
  scanf("%d", &a);

  printf("Enter first group of 5 digits: ");
  scanf("%1d %1d %1d %1d %1d", &i1, &i2, &i3, &i4, &i5) ;
  
  printf("Enter second group of 5 digits: ");
  scanf("%1d %1d %1d %1d %1d", &j1, &j2, &j3, &j4, &j5);

  // Calculating
  int sum1, sum2, total;
  
  sum1 = a+i2+i4+ j1+j3+j5;
  sum2 = i1+i3+i5+j2+j4;
  total = sum1*3 + sum2;

  //Result
  printf("Check digit (last number): %d\n", 9 - ((total-1) % 10));
  
  return 0;
}
