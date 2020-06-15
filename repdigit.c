/*
  Name: repdigit.c
  Description: list the repeated numbers
*/

#include <stdio.h>

#define N 10

int main() {
  long num;
  int dig;
  int nums[N] = {0};

  // Input
  printf("Enter a number: ");
  scanf("%ld", &num);
  
  do {
    dig = num % 10;
    nums[dig] += 1;
    num /= 10;
  } while (dig > 0);

  // Result
  printf("Repeated digit(s): ");
  for (int i = 0; i < N; i++) {
    if (nums[i] > 1)
      printf("%d ", i);
  }

  printf("\n");
  
  return 0;
}
