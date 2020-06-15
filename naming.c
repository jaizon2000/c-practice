/*
  Name: naming.c
  Description: converts name from  First Last --> Last, F.
*/

#include <stdio.h>
#include <ctype.h>

int main() {
  char ch, first;
  
  printf("Enter first and last name: ");

  // Get first letter in first name
  do {
    ch  = getchar();
    first = ch;
  } while (ch  == ' ');

  // Find where space is
  while (ch = getchar() != ' ');
  
  // Get last name
  do {
    ch = getchar();
    if (ch != '\n')
      printf("%c", ch);
  } while (ch != '\n');
  
  printf(", %c.\n", first);
  return 0;
}
