/*
  Name: find-largest-word.c
  Date: July 6, 2020

  Description: Find the smallest and largest words
               the way you'd find them in the dictionary	       
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc
#include <stdbool.h> // bool
#include <ctype.h> // isalpha

#define MAX_WORD_LENGTH ((size_t)20 + 1)

void remove_new_line(char *word) {
  char *p = strchr(word, '\n');
  if (p != NULL) {
    *p = '\0'; 
  }
}

bool is_word_alpha(const char *word) {
  for (int i = 0; i < strlen(word); i++) {
    if (!isalpha(word[i]))
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  char smallest_word[MAX_WORD_LENGTH], largest_word[MAX_WORD_LENGTH];
  char *word = malloc(MAX_WORD_LENGTH); // heap
  // OR *word[MAX_WORD_LENGTH]          // stack
  
  if (word == NULL) {
    perror(argv[0]); // argv[0] = file name
    exit(EXIT_FAILURE); // 1
  }
  
  // Get a word (1st run)
  printf("Enter a word: ");
  fgets(word, MAX_WORD_LENGTH, stdin);
  remove_new_line(word);
  
  // copy word into smallest_word and largest_word
  strcpy(smallest_word, word);
  strcpy(largest_word, word);
  
  do {
    // Get the word (continues)
    printf("Enter a word: ");
    if (fgets(word, MAX_WORD_LENGTH, stdin) == NULL) {
      if (ferror(stdin)) {
	perror(argv[0]);
      }
      exit(ferror(stdin) ? EXIT_FAILURE : EXIT_SUCCESS);
    }
    
    remove_new_line(word);
    
    // if word is smaller than smallest_word
    if (strcmp(word, smallest_word) < 0 && is_word_alpha(word)) {
      strcpy(smallest_word, word);
    }
    // if word is bigger than largest_word
    else if (strcmp(word, largest_word) > 0 && is_word_alpha(word)) {
      strcpy(largest_word, word);
    }
  } while (strlen(word) != 4 + 1); //+1 for \0
  printf("\nSmallest word: %s", smallest_word);
  printf("Largest word: %s", largest_word);
  
  free(word); // free the malloc
  return 0;  
}
