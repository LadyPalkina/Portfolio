#ifndef SRC_MASTER_LEVELS_H_
#define SRC_MASTER_LEVELS_H_

struct levels {
  int num;
  int max;
  int def;
};
struct levels *select_level(int i);
void print_level(struct levels *a);
void insert_level(int num, int max, int def);
void levels();
void update_level(int lvl, int place, int new);
int delete_level(int i);
#endif  // SRC_MASTER_LEVELS_H_
