#include "master_levels.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int delete_level(int i) {
  FILE *f;
  f = fopen("../materials/master_levels.db", "r+b");
  fseek(f, 0, SEEK_END);
  int mem = ftell(f);
  if (i < 0 || i - 1 > mem / 12) {
    printf("err");
    return 0;
  }
  int tmp1, tmp2, tmp3;
  while (1) {
    fseek(f, (i * 3 + 3) * sizeof(int), 0);
    if (fread(&tmp1, sizeof(int), 1, f) == 0)
      break;
    fseek(f, (i * 3 + 4) * sizeof(int), 0);
    fread(&tmp2, sizeof(int), 1, f);
    fseek(f, (i * 3 + 5) * sizeof(int), 0);
    fread(&tmp3, sizeof(int), 1, f);
    fseek(f, (i * 3) * sizeof(int), 0);
    fwrite(&tmp1, sizeof(int), 1, f);
    fwrite(&tmp2, sizeof(int), 1, f);
    fwrite(&tmp3, sizeof(int), 1, f);
    i++;
  }
  truncate("../materials/master_levels.db", mem - 12);
  return 1;
}
void update_level(int lvl, int place, int new) {
  FILE *f;
  int tmp;

  f = fopen("../materials/master_levels.db", "r+b");
  fseek(f, (lvl * 3 + place) * sizeof(int), 0);
  if (fread(&tmp, sizeof(int), 1, f) == 0) {
    printf("err");
    return;
  }
  fseek(f, (lvl * 3 + place) * sizeof(int), 0);
  fwrite(&new, sizeof(int), 1, f);
  fclose(f);
}
void insert_level(int num, int max, int def) {
  FILE *f;
  f = fopen("../materials/master_levels.db", "a");
  fseek(f, 0, SEEK_END);
  fwrite(&num, sizeof(int), 1, f);
  fwrite(&max, sizeof(int), 1, f);
  fwrite(&def, sizeof(int), 1, f);
  fclose(f);
}
void print_level(struct levels *a) {
  if (a == NULL) {
    printf("incorrect level");
  } else {
    printf("%d %d %d", a->num, a->max, a->def);
    free(a);
  }
}

struct levels *select_level(int i) {
  struct levels *a = malloc(40);
  FILE *f;
  int flag = 0;
  f = fopen("../materials/master_levels.db", "r");

  fseek(f, i * 3 * sizeof(int), 0);
  if (fread(&a->num, sizeof(int), 1, f) == 0 || i < 0)
    flag = -1;
  fread(&a->max, sizeof(int), 1, f);
  fread(&a->def, sizeof(int), 1, f);
  if (flag == -1) {
    free(a);
    a = NULL;
  }

  fclose(f);
  return a;
}

void levels() {
  struct levels *a = malloc(1000);
  FILE *f;

  f = fopen("../materials/master_levels.db", "r");
  int count = 0;
  while (1) {
    fseek(f, count * 3 * sizeof(int), 0);
    if (fread(&a->num, sizeof(int), 1, f) == 0)
      break;
    fread(&a->max, sizeof(int), 1, f);
    fread(&a->def, sizeof(int), 1, f);
    if (a == NULL) {
      printf("incorrect level");
    } else {
      printf("%d %d %d", a->num, a->max, a->def);
    }

    printf("\n");
    count++;
  }
  free(a);
  fclose(f);
}
