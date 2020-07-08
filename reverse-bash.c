/*
  Name: reverse-bash.c
  Date: July 7, 2020

  Description: Echoes the given word in terminal.
               Using the parameters in main & how it can
               be used to run the progrma via terminal.
*/

#include <stdio.h>
#include <string.h> // strlen

int main(int argc, char *argv[]) {
  int NUMBER_OF_WORDS = argc - 1; // take out null

  // Go through argv backwards
  for (int i = NUMBER_OF_WORDS; i > 0; i--) {
    printf("%s ", argv[i]);
  }
  printf("\n");
  
  return 0;
}
