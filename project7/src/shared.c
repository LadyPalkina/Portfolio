#include "master_levels.h"
#include "master_modules.h"
#include "master_status_events.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void SELECT(int flag, int id) {
  if (flag == 1) {
    if (id == -1)
      modules();
    else
      print_modules(select_modules(id));
  } else if (flag == 2) {
    if (id == -1)
      levels();
    else
      print_level(select_level(id));
  } else {
    if (id == -1)
      all_status_events();
    else
      print_status_events(select_status_events(id));
  }
}
void INSERT(int flag) {
  switch (flag) {
  case 1: {
  }
    int id, level, num, del;
    char name[32];
    scanf("%d %s %d %d %d", &id, name, &level, &num, &del);
    insert_modules(id, name, level, num, del);
    break;
  case 2: {
  }
    int num1, max, def;
    scanf("%d %d %d", &num1, &max, &def);
    insert_level(num1, max, def);
    break;
  case 3: {
  }
    int ev_id, mod_id, newst;
    char data[11], time[9];
    scanf("%d %d %d %s %s", &ev_id, &mod_id, &newst, data, time);
    insert_status_events(ev_id, mod_id, newst, data, time);
    break;
  default:
    break;
  }
}
void DELETE(int flag, int id) {
  if (flag == 1)
    delete_module(id);
  else if (flag == 2)
    delete_level(id);
  else
    delete_event(id);
}
void UPDATE(int flag, int id, int place, int new) {
  if (flag == 1)
    update_modules(id, place, new);
  else if (flag == 2)
    update_level(id, place, new);
  else
    update_status_events(id, place, new);
}

void rebuild_events() {
  int max = sizeevents();
  struct event *a = malloc(40);
  struct event *b = malloc(40);
  for (int i = max - 1; i >= 0; i--) {
    free(a);
    a = select_status_events(i);
    for (int j = i - 1; j >= 0; j--) {
      free(b);
      b = select_status_events(j);
      if (a->mod_id == b->mod_id) {
        delete_event(j);
        i--;
      }
    }
  }
  free(a);
  free(b);
}
int find_mod(int id) {
  int max = sizemod();
  struct modules *a = malloc(48);
  int i = -1, flag = 0;
  for (; i < max - 1 && flag == 0; i++) {
    free(a);
    a = select_modules(i + 1);
    if (a->id == id) {
      flag = 1;
    }
  }
  free(a);
  return i;
}

void printactive() {
  rebuild_events();
  int max = sizeevents();
  struct event *a = malloc(40);
  for (int i = 0; i < max; i++) {
    free(a);
    a = select_status_events(i);
    if (a->newst == 0) {
      update_modules(find_mod(a->mod_id), 2, 1);
      print_modules(select_modules(a->mod_id));
      printf("\n");
      insert_status_events(a->mod_id, a->mod_id, 1, "data", "time");
    }
  }
  free(a);
}
void free_start() {
  int max = sizemod();
  insert_level(5, 1, 0);
  struct modules *a = malloc(48);
  for (int i = 0; i < max; i++) {
    free(a);
    a = select_modules(i);
    if (a->level == 1 && a->num == 1)
      update_modules(i, 0, 5);
  }
  free(a);
}
void caranteen(int id) {
  update_modules(id, 0, 1);
  update_modules(id, 1, 1);
  update_level(0, 2, 1);
}
void select_lvl(int lvl, int num) {
  int max = sizemod();
  insert_level(5, 1, 0);
  struct modules *a = malloc(48);
  for (int i = 0; i < max; i++) {
    free(a);
    a = select_modules(i);
    if (a->level == lvl && a->num == num) {
      print_modules(select_modules(a->id));
      printf("\n");
    }
  }
  free(a);
}
