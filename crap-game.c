/*
    Name:
    Description: a game of craps
*/
#include <stdio.h>
#include <stdlib.h>     // srand(), rand()
#include <time.h>       // time()
#include <stdbool.h>    // true, false

// Function Prototypes
int roll_dice(void);
bool play_game(void);

// ------------------------------
// MAIN():
// main function, displays # of wins & losses
// ------------------------------
int main() {
    srand((unsigned) time(NULL));
    int wins = 0, losses = 0;
    char ch;
    
    // do {
    //     (play_game() == true ? wins++ : losses++);
        
    //     printf("\nPlay again? ");
    //     scanf("%c", &ch);
    // } while (ch == 'Y' || ch == 'y');
    
    // printf("\nWins: %d    Losses: %d\n", wins, losses);
    do {
        printf("\nCommand: ");
        scanf("%c", &ch);

    } while (ch != 'N' || ch != 'n');
    
    return 0;
}

// ------------------------------
// ROLL_DICE():
// rolls 2 random die & returns the sum
// ------------------------------
int roll_dice(void) {
    int roll_1 = 1 + rand() % 5; // 0-6
    int roll_2 = 1 + rand() % 5;
    int sum = roll_1 + roll_2;
    
    // printf("You rolled: %d + %d = %d\n", roll_1, roll_2, sum);
    printf("You rolled: %d\n", sum);
    return sum;
}

// ------------------------------
// PLAY_GAME():
// play 1 game of crabs, returns T or F
// ------------------------------
bool play_game(void) {
    printf("\n");
    
    int sum = roll_dice();
    printf("Your point is %d\n", sum);
    do {
        switch (sum) {
            case 7:
            case 11: printf("You win!\n");
                     return true;
            case 2:
            case 3:
            case 12: printf("You lose\n");
                     return false;
        }
    } while (sum = roll_dice() != 7);
    
    printf("You lose!\n");
    return false;
}