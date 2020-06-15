/*
    Name: print-num.c
    Description: turns a num into a cooler format
    eg. 1 -->     2 --> _
              |         _|   
	      |        |_  
*/

#include <stdio.h>

#define MAX_DIGITS 10

// Global Arrays
char digits[3][MAX_DIGITS*4] = {0};
const int segments[10][7] = {{1,1,1,1,1,1,0},
                             {0,1,1,0,0,0,0},
                             {1,1,0,1,1,0,1},
                             {1,1,1,1,0,0,1},
                             {0,1,1,0,0,1,1},
			     {1,0,1,1,0,1,1},
			     {1,0,1,1,1,1,1},
			     {1,1,1,0,0,0,0},
			     {1,1,1,1,1,1,1},
			     {1,1,1,1,0,1,1}};


// -------------------
// clear_digits_array():
// fill array with blank space
// -------------------
void clear_digits_array(void) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < (MAX_DIGITS*4); x++) {
            digits[y][x] = ' ';
        }
    }
}


// -------------------
// process_digits(dig, pos):
// converts the digit into a cool looking number in pos
// -------------------
void process_digit(int digit, int pos) {
  pos = pos * 4 + 1;
  
  if (segments[digit][0]) {
    digits[0][1 + pos] = '_';
  }
  
  if (segments[digit][1]) {
    digits[1][2 + pos] = '|';
  }
  
  if (segments[digit][2]) {
    digits[2][2 + pos] = '|';
  }
  
  if (segments[digit][3]) {
    digits[2][1 + pos] = '_';
  }
  
  if (segments[digit][4]) {
    digits[2][0 + pos] = '|';
  }
  
  if (segments[digit][5]) {
    digits[1][0 + pos] = '|';
  }
  
  if (segments[digit][6]) {
    digits[1][1 + pos] = '_';
  }
   
}


// -------------------
// print_digits_array():
// prints the digits array (cool looking numbers)
// -------------------
void print_digits_array(void) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < (MAX_DIGITS*4); x++) {
            printf("%c", digits[y][x]);
        }
	printf("\n");
    }
}


// -------------------
// main();
// starts the program
// -------------------
int main() {
    clear_digits_array();
    char num;
    int pos = 0;
    
    printf("Enter a number: ");
    do {
      scanf("%c", &num);
      switch (num) {
      case '0': num = 0; break;
      case '1': num = 1; break;
      case '2': num = 2; break;
      case '3': num = 3; break;
      case '4': num = 4; break;
      case '5': num = 5; break;
      case '6': num = 6; break;
      case '7': num = 7; break;
      case '8': num = 8; break;
      case '9': num = 9; break;
      default: continue;
      }
      process_digit(num, pos++);
    } while (num != '\n' && pos < MAX_DIGITS);
    
    print_digits_array();
    
    return 0;
}
