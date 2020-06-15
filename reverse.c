/*
  Name: reverse.c
  Description: give 10 integer numbers, reverses them (using array)
*/

#include <stdio.h>


#define N 10

int main() {
  int a[N], i;

  // Get numbers
  printf("Enter %d numbers: ", N);
  for (i=0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Print Reverse Order
  printf("In reverse order: ");
  for (i = N-1; i >= 0; i--) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
