#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 32
struct date {
  int year;
  int month;
  int day;
  int hour;
  int min;
  int sec;
  int status;
  int code;
};
void print_all(char file[100]);
void wriite(char file[100]);
void sort_all(char file[100]);
void print_data(struct date *a) {
  printf("%d %d %d %d %d %d %d %d\n", a->year, a->month, a->day, a->hour,
         a->min, a->sec, a->status, a->code);
}

int main() {
  char file[100];
  file[0] = '.';
  file[1] = '.';
  file[2] = '/';
  scanf("%s", (file + 3));
  FILE *f;
  f = fopen(file, "r+b");
  if (f == NULL) {
    printf("n/a");
    return 0;
  }
  fseek(f, 0, SEEK_END);
  if (ftell(f) == 0) {
    printf("n/a");
    return 0;
  }
  int fl;
  if (scanf("%d", &fl) == 0 || fl < 0 || fl > 2) {
    printf("n/a");
    return 0;
  }
  if (fl == 2) {
    wriite(file);
  }
  if (fl > 0) {
    sort_all(file);
  }
  print_all(file);
}
long int val(struct date *a) {
  long int value = (a->year - 1900) * 12 + (a->month);
  value = value * 32 + a->day;
  value = value * 24 + a->hour;
  value = value * 60 + a->min;
  value = value * 60 + a->sec;
  return value;
}

void wriite(char file[100]) {
  int a[8];
  FILE *f;
  f = fopen(file, "r+b");
  fseek(f, 0, SEEK_END);
  for (int i = 0; i < 8; i++) {
    scanf("%d", &a[i]);
  }
  fwrite(a, sizeof(int), 8, f);

  fclose(f);
}

void sort_all(char file[100]) {
  FILE *f;
  f = fopen(file, "r+b");
  struct date *st = malloc(32);
  struct date *run = malloc(32);
  int i = 0, j = 0;
  while (1) {
    fseek(f, i * SIZE, 0);
    if (fread(st, sizeof(struct date), 1, f) == 0)
      break;
    j = i + 1;
    while (1) {
      fseek(f, j * SIZE, 0);
      if (fread(run, sizeof(struct date), 1, f) == 0)
        break;
      if (val(st) > val(run)) {
        fseek(f, i * SIZE, 0);
        fwrite(run, SIZE, 1, f);
        fseek(f, j * SIZE, 0);
        fwrite(st, SIZE, 1, f);
        fseek(f, i * SIZE, 0);
        fread(st, sizeof(struct date), 1, f);
      }
      j++;
    }
    i++;
  }
  free(st);
  free(run);
}
void print_all(char file[100]) {
  struct date *b = malloc(32);
  FILE *f;
  f = fopen(file, "r");
  fseek(f, 0, 0);
  while (1) {
    if (fread(b, sizeof(struct date), 1, f) == 0)
      break;
    print_data(b);
  }

  fclose(f);
  free(b);
}
