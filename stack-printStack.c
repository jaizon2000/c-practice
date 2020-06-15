// Terrible implementation of a stack.
// (but fun with pointers!)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack Structure Blueprint
struct stack {
  int *items;
  int currentSize;
};

// newStack: Stack Constructor
struct stack *newStack() {
  struct stack *stack = malloc(sizeof(struct stack));
  if (stack == NULL) {
    exit(1);
  }

  stack->items = NULL;
  stack->currentSize = 0;

  return stack;
}

// printStack: 
// Print Items in a Stack
void printStack(struct stack *stack) {
    printf("----\n");
    for (int i = stack->currentSize - 1; i >= 0; i--) {
        printf("%d\n", stack->items[i]);
    }
    printf("----\n");
}

// pushStack: 
// Push To Stack (LIFO)
void pushStack(struct stack *stack, int item) {
  int *oldItems = stack->items;

  stack->currentSize++;
  stack->items = malloc(sizeof(int) * stack->currentSize);
  if (stack->items == NULL) {
    exit(1);
  }

  memcpy(stack->items, oldItems, sizeof(int) * (stack->currentSize - 1));
  stack->items[stack->currentSize - 1] = item;

  free(oldItems);
}

// Pop From Stack (LIFO)
int popStack(struct stack *stack) {
  if (stack->currentSize == 0) {
    fprintf(stderr, "you made boo boo\n");
    exit(1);
  }

  int item = stack->items[stack->currentSize - 1];

  int *oldItems = stack->items;

  stack->currentSize--;
  stack->items = malloc(sizeof(int) * stack->currentSize);
  if (stack->items == NULL) {
    exit(1);
  }
  memcpy(stack->items, oldItems, sizeof(int) * stack->currentSize);

  free(oldItems);

  return item;
}

// Free the memory that stack used
void deleteStack(struct stack *stack) {
  if (stack->currentSize > 0) {
    free(stack->items);
  }

  free(stack);
}

int main() {
  struct stack *stack = newStack();

  int num;
  scanf("%d", &num);
  while (num > 0) {
    pushStack(stack, num);

    scanf("%d", &num);
  }
  
    printStack(stack);
  while (stack->currentSize > 0) {
    int item = popStack(stack);

    printf("removed %d\n", item);
  }
  
  deleteStack(stack);

  return 0;
}
