// Copyright 2022 by mathosho (ilusha stetskiy)
#include <stdio.h>
#include <stdlib.h>
#define MASMAX 100
int input_mas(int *array, int n);
void output(int **mass, int a, int b);
int menu();
int scan(int lim);
int scn();
int max(int **mas, int a, int b, int *data);
void outp1t(int *mas, int a);
int min(int **mas, int a, int b, int *data);
int min_stat(int mas[][MASMAX], int a, int b, int *data);
int max_stat(int mas[][MASMAX], int a, int b, int *data);

int main() {
  int m;
  m = menu();
  if (m == -1) {
    printf("n/a");
    return 0;
  }
}

int scan(int lim) {
  int a;
  char temp;
  if (!((scanf("%d%c", &a, &temp) >= 1) && (temp == 10 || temp == 32) &&
        (0 < a) && (a <= lim)))
    a = -1;
  return a;
}

int scn() {
  int a;
  char temp;
  if (!((scanf("%d%c", &a, &temp) >= 1) && (temp == 10 || temp == 32) &&
        (0 < a)))
    a = -1;
  return a;
}

int menu() {
  int m, a, b;
  m = scan(4);
  if (m == 1) {
    a = scan(MASMAX);
    b = scan(MASMAX);
  } else {
    a = scn();
    b = scn();
  }
  if (a == -1 || b == -1)
    m = -1;
  int **mass;
  int *v_a;
  int rez_max[a], rez_min[b];
  switch (m) {
  case 1: {
  };
    int data[MASMAX][MASMAX];
    // char temp;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        scanf("%d", &data[i][j]);
      }
    }

    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        printf("%d", data[i][j]);
        if (j < b - 1)
          printf(" ");
        else if (j == b - 1)
          printf("\n");
      }
    }
    max_stat(data, a, b, rez_max);
    min_stat(data, a, b, rez_min);
    break;
  case 2:
    mass = malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
      mass[i] = malloc(b * sizeof(int));

    break;
  case 3:
    mass = malloc(a * sizeof(int *));
    v_a = malloc(a * b * sizeof(int));
    for (int i = 0; i < a; i++)
      mass[i] = v_a + b * i;

    break;
  case 4:
    mass = malloc(a * b * sizeof(int) + a * sizeof(int *));
    int *ptr = (int *)(mass + a);
    for (int i = 0; i < a; i++)
      mass[i] = ptr + b * i;

    break;

  default:
    break;
  }
  if (m > 1) {
    for (int i = 0; i < a; i++)
      input_mas(mass[i], b);
    output(mass, a, b);
    printf("\n");
    min(mass, a, b, rez_min);
    max(mass, a, b, rez_max);

    if (m == 2) {
      for (int i = 0; i < a; i++) {
        free(mass[i]);
      }
    }
    free(mass);
    if (m == 3)
      free(v_a);
  }
  if (m > 0) {
    outp1t(rez_max, a);
    printf("\n");
    outp1t(rez_min, b);
  }
  return m;
}

int input_mas(int *array, int n) {
  char temp;
  int flag;
  for (int i = 0; i < n; i++) {
    if (i < n - 1 && ((scanf("%d%c", &array[i], &temp) < 1) || (temp != 32))) {
      flag = -1;
      break;
    }
    if (i == n - 1 &&
        ((scanf("%d%c", &array[i], &temp) < 1) || (temp != 10 && temp != 32))) {
      flag = -1;
      break;
    }
  }
  return flag;
}

void output(int **mas, int a, int b) {
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      printf("%d", mas[i][j]);
      if (j < b - 1)
        printf(" ");
      else if (j == b - 1 && i < a - 1)
        printf("\n");
    }
  }
}

void outp1t(int *mas, int a) {
  for (int j = 0; j < a; j++) {
    printf("%d", mas[j]);
    if (j < a - 1)
      printf(" ");
  }
}

int max(int **mas, int a, int b, int *data) {
  for (int i = 0; i < a; i++) {
    int max = mas[i][0];
    for (int j = 0; j < b; j++) {
      if (max < mas[i][j])
        max = mas[i][j];
    }
    data[i] = max;
  }
  return 0;
}

int min(int **mas, int a, int b, int *data) {
  for (int i = 0; i < b; i++) {
    int min = mas[0][i];
    for (int j = 0; j < a; j++) {
      if (min > mas[j][i])
        min = mas[j][i];
    }
    data[i] = min;
  }
  return 0;
}

int max_stat(int mas[][MASMAX], int a, int b, int *data) {
  for (int i = 0; i < a; i++) {
    int max = mas[i][0];
    for (int j = 0; j < b; j++) {
      if (max < mas[i][j])
        max = mas[i][j];
    }
    data[i] = max;
  }
  return 0;
}

int min_stat(int mas[][MASMAX], int a, int b, int *data) {
  for (int i = 0; i < b; i++) {
    int min = mas[0][i];
    for (int j = 0; j < a; j++) {
      if (min > mas[j][i])
        min = mas[j][i];
    }
    data[i] = min;
  }
  return 0;
}
