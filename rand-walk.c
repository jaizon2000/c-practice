/*
  Name: rand-walk.c
  Description: a random walk
*/

/* DICTIONARY
  rand() % 4 ---> random num from 0-4
  0: up
  1: down
  2: left
  3: right
  'A': 65
  'Z': 90
  '.': 46
*/

#include <stdio.h>

#include <stdlib.h> // rand()
#include <time.h> // time()

#define ROW 10
#define COL 10



/* PRINT() - prints current grid*/
void print(char grid[ROW][COL]) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      printf("%c ", grid[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}








/* MAIN() - the start*/
int main() {  
  char grid[ROW][COL] = {0};
  int i, j;

  // Initialize grid with '.'
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      grid[i][j] = '.';
    }
  }


  
  // RANDOM DIRECTION
  i = 0;
  j = 0;
  const char empty = '.';
  srand((unsigned) time(NULL));
  grid[i][j] = 'A';

  char curr_pos = grid[i][j];
  char letter = 'B';
  
  while (letter < 'Z') {
    
    
    int direction = rand() % 4;
    printf("%d ", direction);
      
    int prev=0;
    /* if (grid[i+1][j] != empty && grid[i-1][j] != empty && \ */
    /* 	grid[i][j+1] != empty && grid[i][j-1] != empty) { */
	
    /* } else { */

    while (curr_pos = grid[i][j] != '.') {
      // GET A DIRECTION
      if (direction == 0 && i-1 > 0) {
	prev = i--;

      } else if (direction == 1 && i+1 < ROW) {
	prev = i++;
	
      
      } else if (direction == 2 && j-1 > 0) {
	prev = j--;
	
      
      } else if (direction == 3 && j+1 < COL) {
	prev = j++;
      } else {
      
	if (direction < 2)
	  i = prev;
	else
	  j = prev;
      }
    }
    grid[i][j] = letter++;
    curr_pos = grid[i][j];
  }    
    curr_pos = grid[i][j];
    /* if (curr_pos > 'A' && curr_pos <= 'Z') { */
    /*   if (direction < 2) */
    /* 	i = prev; */
    /*   else */
    /* 	j = prev; */
    /* /\* } *\/ */
    /* printf("\n[%c], (%d, %d)\n", curr_pos, i+1, j+1); */
    /* print(grid); */
  
 

  
return 0;
}


