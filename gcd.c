/*
  Name: gcd.c
  Description: Finds greatest common denominator b/w 2 integers
*/

#include <stdio.h>

int main() {
  int m, n, div, gcd=0;

  printf("Enter two integers: ");
  scanf("%d %d", &m, &n);
  
  if (m == 0 || n == 0) {
    // GCD is the bigger num
    gcd = m > 0 ? m : n;
    
  } else {
    int rem;
    
    if (m > n) {
      int temp=m;
      
      m = n;
      n = temp;
    }

    // n bigger one
    // m smaller one
    do {
      rem = n%m;
      
      if (rem > 0)
	gcd = rem;
    
      n = m;
      m = rem;
      
    } while (rem > 0);
  }
  
  printf("Greatest common divisor: %d\n", gcd);

  return 0;
}
