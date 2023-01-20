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

long int val(struct date *a) {
  long int value = (a->year - 1900) * 12 + (a->month);
  value = value * 32 + a->day;
  value = value * 24 + a->hour;
  value = value * 60 + a->min;
  value = value * 60 + a->sec;
  return value;
}
void swap(FILE *f, int i, int j) {
  struct date *st = malloc(32);
  struct date *run = malloc(32);
  fseek(f, j * SIZE, 0);
  fread(run, sizeof(struct date), 1, f);
  fseek(f, i * SIZE, 0);
  fread(st, sizeof(struct date), 1, f);
  fseek(f, i * SIZE, 0);
  fwrite(run, SIZE, 1, f);
  fseek(f, j * SIZE, 0);
  fwrite(st, SIZE, 1, f);
  free(st);
  free(run);
}
void print_data(struct date *a) {
  printf("%d %d %d %d %d %d %d %d\n", a->year, a->month, a->day, a->hour,
         a->min, a->sec, a->status, a->code);
}

void print_all(char file[100]) {
  FILE *f;
  f = fopen(file, "r+b");
  struct date *b = malloc(32);
  fseek(f, 0, 0);
  while (1) {
    if (fread(b, sizeof(struct date), 1, f) == 0)
      break;
    print_data(b);
  }
  free(b);
  fclose(f);
}
void delete (FILE *f, char file[100], int size, int valmax, int valmin) {
  int i = 0, j = size - 1, count = 0, tmp;
  struct date *b = malloc(32);
  for (; i < j;) {
    fseek(f, i * SIZE, 0);
    fread(b, sizeof(struct date), 1, f);
    tmp = val(b);
    if (tmp > valmin && tmp < valmax) {
      swap(f, i, j);
      count++;
      j--;
    } else {
      i++;
    }
  }
  fseek(f, 0, SEEK_END);
  int mem = ftell(f);
  truncate(file, mem - (count)*SIZE);
  fclose(f);
  free(b);
}

int main() {
  char file[100];
  file[0] = '.';
  file[1] = '.';
  file[2] = '/';
  scanf("%s", (file + 3));
  FILE *f;
  f = fopen(file, "r+b");
  int day, mon, year;
  if (f == NULL) {
    printf("n/a");
    return 0;
  }
  fseek(f, 0, SEEK_END);
  int size = ftell(f) / SIZE;
  if (size == 0) {
    printf("n/a");
    return 0;
  }
  if (scanf("%d.%d.%d", &day, &mon, &year) != 3) {
    printf("n/a");
    return 0;
  }
  struct date b = {year, mon, day, 0, 0, 0, 0, 0};
  long int val1 = val(&b);
  if (scanf("%d.%d.%d", &day, &mon, &year) != 3) {
    printf("n/a");
    return 0;
  }
  struct date d = {year, mon, day, 0, 0, 0, 0, 0};
  long int val2 = val(&d);
  long int tmp;
  if (val1 > val2) {
    val1 += 86399;
  } else {
    tmp = val1;
    val1 = val2;
    val2 = tmp + 86399;
  }
  // free (&b);
  // free (&d);
  delete (f, file, size, val1, val2);
  print_all(file);
  fclose(f);
}
