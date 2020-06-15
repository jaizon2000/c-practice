// Terrible implementation of a stack.
// (but fun with pointers!)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
  int *items;
  int currentSize;
};

struct stack *newStack() {
  struct stack *stack = malloc(sizeof(struct stack));
  if (stack == NULL) {
    exit(1);
  }

  stack->items = NULL;
  stack->currentSize = 0;

  return stack;
}

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

  while (stack->currentSize > 0) {
    int item = popStack(stack);

    printf("removed %d\n", item);
  }

  deleteStack(stack);

  return 0;
}
