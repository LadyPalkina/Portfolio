#include "master_modules.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 48

int delete_module(int i) {
  FILE *f;
  struct modules *b = malloc(SIZE);
  f = fopen("../materials/master_modules.db", "r+b");
  fseek(f, 0, SEEK_END);
  int mem = ftell(f);
  if (i < 0 || i - 1 > mem / SIZE) {
    printf("err");
    return 0;
  }
  while (1) {
    fseek(f, (i + 1) * SIZE, 0);
    if (fread(&b->id, sizeof(int), 1, f) == 0)
      break;
    fread(&b->name, sizeof(char), 32, f);
    fread(&b->level, sizeof(int), 1, f);
    fread(&b->num, sizeof(int), 1, f);
    fread(&b->del, sizeof(int), 1, f);
    fseek(f, (i * SIZE), 0);
    fwrite(&b->id, sizeof(int), 1, f);
    fwrite(&b->name, sizeof(char), 32, f);
    fwrite(&b->level, sizeof(int), 1, f);
    fwrite(&b->num, sizeof(int), 1, f);
    fwrite(&b->del, sizeof(int), 1, f);
    i++;
  }
  truncate("../materials/master_modules.db", mem - SIZE);
  free(b);
  return 1;
}
void update_modules(int id, int place, int new) {
  FILE *f;
  int tmp;
  int c = 32 * sizeof(char) + sizeof(int);
  f = fopen("../materials/master_modules.db", "r+b");
  fseek(f, id * SIZE + c + place * sizeof(int), 0);
  if (fread(&tmp, sizeof(int), 1, f) == 0) {
    printf("Incorrect module\n");
    return;
  }
  fseek(f, id * SIZE + c + place * sizeof(int), 0);
  fwrite(&new, sizeof(int), 1, f);
  fclose(f);
}
int sizemod() {
  FILE *f;
  f = fopen("../materials/master_modules.db", "r+b");
  fseek(f, 0, SEEK_END);
  return ftell(f) / SIZE;
  fclose(f);
}
void insert_modules(int id, char *name, int level, int num, int del) {
  FILE *f;
  f = fopen("../materials/master_modules.db", "a");
  fseek(f, 0, SEEK_END);
  fwrite(&id, sizeof(int), 1, f);
  fwrite(name, sizeof(char), 32, f);
  fwrite(&level, sizeof(int), 1, f);
  fwrite(&num, sizeof(int), 1, f);
  fwrite(&del, sizeof(int), 1, f);
  fclose(f);
}
void print_modules(struct modules *b) {
  if (b == NULL) {
    printf("Incorrect module");
  } else {
    printf("%3d %14s %2d %d %d", b->id, b->name, b->level, b->num, b->del);
    free(b);
  }
}

struct modules *select_modules(int i) {
  FILE *f;
  struct modules *b = malloc(SIZE);
  f = fopen("../materials/master_modules.db", "r");
  int flag = 0;
  fseek(f, i * SIZE, 0);
  if (fread(&b->id, sizeof(int), 1, f) == 0)
    flag = -1;
  fread(&b->name, sizeof(char), 32, f);
  fread(&b->level, sizeof(int), 1, f);
  fread(&b->num, sizeof(int), 1, f);
  fread(&b->del, sizeof(int), 1, f);
  if (flag == -1) {
    free(b);
    b = NULL;
  }
  fclose(f);
  return b;
}

void modules() {
  struct modules *b = malloc(SIZE);
  FILE *f;

  f = fopen("../materials/master_modules.db", "r");
  int count = 0;
  fseek(f, 0, 0);
  while (1) {
    if (fread(&b->id, sizeof(int), 1, f) == 0)
      break;
    fread(&b->name, sizeof(char), 32, f);
    fread(&b->level, sizeof(int), 1, f);
    fread(&b->num, sizeof(int), 1, f);
    fread(&b->del, sizeof(int), 1, f);
    if (b == NULL) {
      printf("Incorrect module");
    } else {
      printf("%3d %14s %2d %d %d", b->id, b->name, b->level, b->num, b->del);
    }
    printf("\n");
    count++;
  }
  free(b);
  fclose(f);
}
