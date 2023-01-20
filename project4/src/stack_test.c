#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void proverka(int i);
void pushtest(struct stack *stk, int f);
void poptest(struct stack *stk, int f);
int main() {
  struct stack stk = init();
  stack_push(&stk, 1);
  stack_push(&stk, 2);
  stack_push(&stk, 3);
  pushtest(&stk, 7);
  printf("\n");
  pushtest(&stk, 0);
  printf("\n");
  pushtest(&stk, -12);
  poptest(&stk, -12);
  stack_pop(&stk);
  stack_pop(&stk);
  stack_pop(&stk);
  stack_pop(&stk);
  poptest(&stk, 1);
  poptest(&stk, ERR);
  stack_destroy(&stk);
}
void poptest(struct stack *stk, int f) {
  int tmp;
  printf("\nInput\n");
  print_stk(stk);
  tmp = stack_pop(stk);
  printf("\nOutput\n");
  if (tmp != ERR)
    printf("%d", tmp);
  else
    (printf("NULL"));
  proverka(tmp == f);
}

void pushtest(struct stack *stk, int f) {
  printf("Input\n");
  print_stk(stk);
  printf("\n%d", f);
  stack_push(stk, f);
  printf("\nOutput\n");
  proverka(print_stk(stk) == f);
}

void proverka(int i) {
  if (i == 1)
    printf("\nSUCCESS");
  else
    printf("\nFAIL");
}
