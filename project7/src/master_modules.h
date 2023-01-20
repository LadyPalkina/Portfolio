#ifndef SRC_MASTER_MODULES_H_
#define SRC_MASTER_MODULES_H_

struct modules {
  int id;
  char name[32];
  int level;
  int num;
  int del;
};

int delete_module(int i);
void update_modules(int id, int place, int new);
void insert_modules(int id, char *name, int level, int num, int del);
void print_modules(struct modules *b);
struct modules *select_modules(int i);
void modules();
int sizemod();
#endif  // SRC_MASTER_MODULES_H_
