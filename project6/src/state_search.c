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
int finder(char file[100], int year, int mon, int day);

int main() {
  char file[100];
  file[0] = '.';
  file[1] = '.';
  file[2] = '/';
  scanf("%s", (file + 3));
  FILE *f;
  f = fopen(file, "r");
  if (f == NULL) {
    printf("n/a");
    return 0;
  }
  fseek(f, 0, SEEK_END);
  if (ftell(f) == 0) {
    printf("n/a");
    return 0;
  }
  int day, mon, year;
  if (scanf("%d.%d.%d", &day, &mon, &year) != 3) {
    printf("n/a");
    return 0;
  }
  int fin = finder(file, year, mon, day);
  if (fin == 0) {
    printf("n/a");
    return 0;
  } else {
    printf("%d", fin);
  }
}

int finder(char file[100], int year, int mon, int day) {
  struct date *b = malloc(32);
  FILE *f;
  int rez = 0;
  f = fopen(file, "r");
  fseek(f, 0, 0);
  for (; fread(b, sizeof(struct date), 1, f) != 0 && rez == 0;) {
    if (year == b->year && mon == b->month && day == b->day)
      rez = b->code;
  }
  fclose(f);
  free(b);
  return rez;
}
