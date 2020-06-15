/*
  Name: naming.c
  Description: converts name from  First Last --> Last, F.
*/

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int main() {
  // https://stackoverflow.com/questions/17848561/linux-unbuffered-reads-from-stdio
  struct termios ctrl;
  tcgetattr(STDIN_FILENO, &ctrl);
  ctrl.c_lflag &= ~ICANON; // turning off canonical mode makes input unbuffered
  tcsetattr(STDIN_FILENO, TCSANOW, &ctrl);

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
