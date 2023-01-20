// Copyright 2022 by mathosho (ilusha stetskiy)
#include <stdio.h>
#include <stdlib.h>
int input_mas(int *array, int n);
void output(int **mass, int a, int b);
int menu();
int scan(int lim);
int scn();
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
  printf("Есть четыре стула, один статический,три динамических..\n");
  printf("На какой массив вводить хочешь?)\n");
  printf("1-Статический\n2-Динамический, создающий много массивов\n");
  printf("3-Динамический создающий два массива \n4-Динамический, создающий "
         "единый массив\n");
  printf("Введите число, а затем с новой строчки размеры матриц.\n");
  printf("После этого можно вводить матрицу\n");
  int m, a, b;
  m = scan(4);
  if (m == 1) {
    a = scan(100);
    b = scan(100);
  } else {
    a = scn();
    b = scn();
  }
  if (a == -1 || b == -1)
    m = -1;
  int **mass;
  int *v_a;
  switch (m) {
  case 1:
    {};
    int data[100][100];
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
        else if (j == b - 1 && i < a - 1)
          printf("\n");
      }
    }
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
    int *ptr = (int*) (mass + a);
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
    if (m == 2) {
      for (int i = 0; i < a; i++) {
        free(mass[i]);
      }
    }
    free(mass);
    if (m == 3)
      free(v_a);
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
