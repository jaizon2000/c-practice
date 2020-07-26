/*
  Name:
  Date:

  Description:
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool test_extension(const char *fname, const char *extension) {
  while (*fname != '.') {
    putchar(*fname);
    fname++;
  }
}

int main() {
  testexttension("memo.txt", "TXT");
  return 0;
}
