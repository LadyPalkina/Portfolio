#ifndef SRC_SHARED_H_
#define SRC_SHARED_H_

void select_lvl(int lvl, int num);
void caranteen(int id);
void free_start();
void printactive();
void rebuild_events();
void UPDATE(int flag, int id, int place, int new1);
void DELETE(int flag, int id);
void INSERT(int flag);
void SELECT(int flag, int id);
int find_mod(int i);

#endif  // SRC_SHARED_H_
