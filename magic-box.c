/*
  Name: magic-box.c
  Description: MAGIC
*/

#include <stdio.h>


int main() {
  int size = 5;
  printf("This program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic square: ");
  scanf("%d", &size);

  if (size % 2 == 0) {
    printf("Input an odd number!!\n");
    return 0;
  }
  
  int square[size][size];
  int mid = size/2;
  int x = mid, y = 0, num = 1;
  
  // Initialize array with 0's
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) { 
      square[row][col] = 0;
    }
  }
  
  // Placing Numbers
  square[y--][x++] = num;
  for (++num; num <= size*size; num++) {
    int prev_y = y+1;
    int prev_x = x-1;
    /* printf("\n(%d, %d)\n", x, y); */
    
    if (y < 0) {
      y = size-1;
    }
    
    if (x > size-1) {
      x = 0;
    }
    
    if (square[y][x] != 0) {
      y = prev_y+1;
      x = prev_x;
      square[y][x] = num;
    } else
      square[y][x] = num;

    /* printf("(%d, %d)\n", x, y) */;
    /* for (int i = 0; i < size; i++) { */
    /*   for (int j = 0; j < size; j++) { */
    /* 	printf("%d ", square[i][j]); */
    /*   } */
    /*   printf("\n"); */
    /* } */
    y--, x++;   
  }

  
  // Print Array
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%3d  ", square[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  

  return 0;
} 

  
