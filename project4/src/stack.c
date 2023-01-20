#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack init() {
  struct stack new = {
      .values = NULL,
      .lenght = 0,
      .capacity = 0,
  };
  return new;
}

int print_stk(struct stack *stk) {
  printf("[");
  int i = 0;
  for (; i < stk->lenght; i++) {
    printf(" %d", stk->values[i]);
  }
  printf(" ]");
  return stk->values[i - 1];
}
void stack_push(struct stack *stk, int num) {
  if (stk->values == NULL || stk->lenght == stk->capacity) {
    stk->capacity = (stk->capacity + 1) * 2;
    stk->values = (int *)realloc(stk->values, sizeof(int) * stk->capacity);
  }
  stk->values[stk->lenght] = num;
  stk->lenght++;
}
int stack_pop(struct stack *stk) {
  int rez;
  if (stk->lenght == 0) {
    rez = ERR;
  }     else {
    stk->lenght--;
    rez = stk->values[stk->lenght];
  }
  return rez;
}
void stack_destroy(struct stack *stk) {
  if (stk->values != NULL)
    free(stk->values);
  stk->lenght = 0;
  stk->capacity = 0;
}
