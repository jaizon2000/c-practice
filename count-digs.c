#include <stdio.h>

int main(void){
  int num, dig;
  
  printf("Enter a number: ");
  scanf("%d", &num);

  if (num >= 0 && num < 10) dig = 1;
  else if (num < 100) dig = 2;
  else if (num < 1000) dig = 3;
  else if (num < 10000) dig = 4;

  printf("The number %d has %d digits\n", num, dig);

  return 0;
}
