#include <stdio.h>

int main(void) {
  int x;

  printf("Enter a number between 0 and 32767: ");
  scanf("%d", &x);

  int a, b, c, d, e;
  e = x % 8;
  x /= 8;

  d = x % 8;
  x /= 8;;

  c = x % 8;
  x /= 8;

  b = x % 8;
  x /= 8;

  a = x % 8;
  
  printf("In octal, your number is: %d%d%d%d%d\n", a,b,c,d,e);
  
  return 0;
}
