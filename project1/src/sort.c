// Copyright 2022 by mathosho (ilusha stetskiy)
#include <stdio.h>
#include <stdlib.h>
int *input_mas(int n);
void sort_puz(int *a, int n);
void output(int *a, int n);

int main() {
  int n;
  char temp;
  if (!((scanf("%d%c", &n, &temp) >= 2) && (temp == 10 || temp == 32) &&
        (0 < n))) {
    printf("n/a");
    return 0;
  }

  int *array = input_mas(n);
  if (*array == 32760) {
    printf("n/a");
    free(array);
    return 0;
  }
  sort_puz(array, n);
  output(array, n);
  free(array);
  array = 0;
  return 0;
}

int *input_mas(int n) {
  char temp;
  int *array = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    if (i < n - 1 && ((scanf("%d%c", &array[i], &temp) < 1) || (temp != 32))) {
      *array = 32760;
      break;
    }
    if (i == n - 1 &&
        ((scanf("%d%c", &array[i], &temp) < 1) || (temp != 10 && temp != 32))) {
      *array = 32760;
      break;
    }
  }
  return array;
}
void sort_puz(int *a, int n) {
  int temp;
  for (int *p = a; p - a < n; p++) {
    for (int *q = p + 1; q - a < n; q++) {
      if (*q < *p) {
        temp = *q;
        *q = *p;
        *p = temp;
      }
    }
  }
}
void output(int *a, int n) {
  for (int *p = a; p - a < n; p++) {
    printf("%d", *p);
    if (p - a < n - 1)
      printf(" ");
  }
}
