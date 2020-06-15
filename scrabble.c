/*
  Name: scrabble.c
  Description: enter a word, return points of the word
*/

#include <stdio.h>
#include <ctype.h>

int main() {
  char ch;
  int pts = 0;

  printf("Enter a word: ");
  do {
    ch = toupper(getchar());
    switch (ch) {
    case 'A':
    case 'E':
    case 'I':
    case 'L':
    case 'N':
    case 'O':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
      pts ++;
      break;

    case 'D':
    case 'G':
      pts += 2;
      break;

    case 'B':
    case 'C':
    case 'M':
    case 'P':
      pts += 3;
      break;

    case 'F':
    case 'H':
    case 'V':
    case 'W':
    case 'Y':
      pts += 4;
      break;

    case 'K':
      pts += 5;
      break;

    case 'J':
    case 'X':
      pts += 8;
      break;
      
    case 'Q':
    case 'Z':
      pts += 10;
      break;
	
    }
  } while (ch != '\n');

  printf("Scrabble value: %d\n", pts);
  return 0;
}
