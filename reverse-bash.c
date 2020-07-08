/*
  Name:
  Date:

  Description: Echoes the given word in terminal.
               Using the parameters in main & how it can
               be used to run the progrma via terminal.
*/

#include <stdio.h>
#include <string.h> // strlen

int main(int argc, char *argv[]) {
  int NUMBER_OF_WORDS = argc - 1;

  char reversed_array[NUMBER_OF_WORDS];

  for (int i = 0, j = NUMBER_OF_WORDS; i != 0; i++, j--) {
    // from last item of argv, put last as first in reversed array
    reversed_array[i] = *argv[j];
  }
  return 0;
}
