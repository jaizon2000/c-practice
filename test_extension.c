/*
  Name: test_extension.c
  Date: July 26, 2020

  Description: Check if file extension matches the given extension
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_EXTENSION_FILE_LENGTH 5

bool test_extension(const char *fname, const char *extension) {
  int i = 0;
  while (*fname != '.') {
    fname++;
    i++;
  }
  fname++; // pointer will point to char after '.'  
 
  while (*fname) {
    if (*extension != toupper(*fname)) {
      return false;
    }
    fname++;
    extension++;
  } 
  return true;
}

int main() {
  puts("testing: test_extension(\"memo.txt\", \"TXT\")");
  printf("result: %s\n", test_extension("memo.txt", "TXT") ? "true" : "false");
  return 0;
}
