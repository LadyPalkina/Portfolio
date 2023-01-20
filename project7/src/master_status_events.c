#include "master_status_events.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 32

int delete_event(int i) {
  FILE *f;
  struct event *c = malloc(SIZE);
  f = fopen("../materials/master_status_events.db", "r+b");
  fseek(f, 0, SEEK_END);
  int mem = ftell(f);
  if (i < 0 || i - 1 > mem / SIZE) {
    printf("err");
    return 0;
  }
  while (1) {
    fseek(f, (i + 1) * SIZE, 0);
    if (fread(&c->ev_id, sizeof(int), 1, f) == 0)
      break;
    fread(&c->mod_id, sizeof(int), 1, f);
    fread(&c->newst, sizeof(int), 1, f);
    fread(&c->date, sizeof(char), 11, f);
    fread(&c->time, sizeof(char), 9, f);
    fseek(f, (i * SIZE), 0);
    fwrite(&c->ev_id, sizeof(int), 1, f);
    fwrite(&c->mod_id, sizeof(int), 1, f);
    fwrite(&c->newst, sizeof(int), 1, f);
    fwrite(c->date, sizeof(char), 11, f);
    fwrite(c->time, sizeof(char), 9, f);
    i++;
  }
  truncate("../materials/master_status_events.db", mem - SIZE);
  free(c);
  return 1;
}
void update_status_events(int id, int place, int new) {
  FILE *f;
  int tmp;
  f = fopen("../materials/master_status_events.db", "r+b");
  fseek(f, id * SIZE + place * sizeof(int), 0);
  if (fread(&tmp, sizeof(int), 1, f) == 0) {
    printf("err");
    return;
  }
  fseek(f, id * SIZE + place * sizeof(int), 0);
  fwrite(&new, sizeof(int), 1, f);
  fclose(f);
}

void insert_status_events(int ev_id, int mod_id, int newst, char *date,
                          char *time) {
  FILE *f;
  f = fopen("../materials/master_status_events.db", "a");
  fseek(f, 0, SEEK_END);
  fwrite(&ev_id, sizeof(int), 1, f);
  fwrite(&mod_id, sizeof(int), 1, f);
  fwrite(&newst, sizeof(int), 1, f);
  fwrite(date, sizeof(char), 11, f);
  fwrite(time, sizeof(char), 9, f);
  fclose(f);
}
void print_status_events(struct event *c) {
  if (c == NULL) {
    printf("incorrect event");
  } else {
    printf("%3d %2d %d %s %s", c->ev_id, c->mod_id, c->newst, c->date, c->time);
    free(c);
  }
}

struct event *select_status_events(int i) {
  FILE *f;
  struct event *c = malloc(SIZE);
  f = fopen("../materials/master_status_events.db", "r");
  int flag = 0;
  fseek(f, i * SIZE, 0);
  if (fread(&c->ev_id, sizeof(int), 1, f) == 0 || i < 0)
    flag = -1;
  fread(&c->mod_id, sizeof(int), 1, f);
  fread(&c->newst, sizeof(int), 1, f);
  fread(&c->date, sizeof(char), 11, f);
  fread(&c->time, sizeof(char), 9, f);

  if (flag == -1) {
    free(c);
    c = NULL;
  }
  fclose(f);
  return c;
}
int sizeevents() {
  FILE *f;
  f = fopen("../materials/master_status_events.db", "r+b");
  fseek(f, 0, SEEK_END);
  int i = ftell(f) / SIZE;
  fclose(f);
  return i;
}

void all_status_events() {
  struct event *c = malloc(SIZE);
  FILE *f;

  f = fopen("../materials/master_status_events.db", "r");
  int count = 0;
  fseek(f, 0, 0);
  while (1) {
    if (fread(&c->ev_id, sizeof(int), 1, f) == 0)
      break;
    fread(&c->mod_id, sizeof(int), 1, f);
    fread(&c->newst, sizeof(int), 1, f);
    fread(&c->date, sizeof(char), 11, f);
    fread(&c->time, sizeof(char), 9, f);
    if (c == NULL) {
      printf("incorrect event");
    } else {
      printf("%3d %2d %d %s %s", c->ev_id, c->mod_id, c->newst, c->date,
             c->time);
    }
    printf("\n");
    count++;
  }

  fclose(f);
  free(c);
}
