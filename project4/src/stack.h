#ifndef SRC_STACK_H_
#define SRC_STACK_H_
#define ERR 764892

struct stack {
  int *values;
  int lenght;
  int capacity;
};
int print_stk(struct stack *stk);
struct stack init();
void stack_push(struct stack *stk, int num);
int stack_pop(struct stack *stk);
void stack_destroy(struct stack *stk);
#endif  // SRC_STACK_H_
