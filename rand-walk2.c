/*
  Name: rand-walk2.c
  Description: maze.
*/

#include <stdio.h>

#include <time.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

#define UP 0
#define DOWN 1
#define RIGHT 3
#define LEFT 2


 /* PRINT() - prints current grid*/
void print(char grid[ROW][COL]) {
  for (int y = 0; y < ROW; y++) {
    for (int x = 0; x < COL; x++) {
      printf("%c ", grid[y][x]);
    }
    printf("\n");
  }
  printf("\n");
}



int main() {
  char grid[ROW][COL], letter = 'A';
  int x=0, y=0, dir;

  // Initialize Grid
  for (x=0; x < COL; x++) {
    for (y=0; y < ROW; y++) {
      grid[y][x] = '.';
    }
  }
  x=0, y=0;
  grid[0][0] = letter++;
  
  // RAND DIRECTION
  srand((unsigned) time(NULL));

  while (letter <= 'Z' && (y > 0 && grid[y-1][x] == '.' ||
			   y < ROW-1 && grid[y+1][x] == '.' ||
			   x < COL-1 && grid[y][x+1] == '.' ||
			   x > 0 && grid[y][x-1] == '.')) {
    
    dir = rand() % 4; // 0-3

    if (dir == UP && y > 0 && grid[y-1][x] == '.') {
      grid[--y][x] = letter++;
    
    } else if (dir == DOWN && y < ROW-1 && grid[y+1][x] == '.') {
      grid[++y][x] = letter++;
    
    } else if (dir == RIGHT && x < COL-1 && grid[y][x+1] == '.') {
      grid[y][++x] = letter++;
    
    } else if (dir == LEFT && x > 0 && grid[y][x-1] == '.') {
      grid[y][--x] = letter++;
    
    }
    printf("%d, (%d, %d)\n", dir, x, y);
    print(grid);
  }

  return 0;
}
