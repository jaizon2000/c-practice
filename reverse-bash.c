/*
  Name: reverse-bash.c
  Date: July 7, 2020

  Description: Echoes the given word in terminal.
               Using the parameters in main & how it can
               be used to run the program via terminal.
*/

#include <stdio.h>
#include <string.h> // strlen

int main(int argc, char *argv[]) {
  int number_of_words = argc - 1;

  // Go through argv backwards
  for (int i = number_of_words; i > 0; i--) {
    printf("%s ", argv[i]);
  }
  printf("\n");
  
  return 0;
}
