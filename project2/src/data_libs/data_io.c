#include "data_io.h"
#include <stdio.h>
void output(double *a, int n) {
  for (double *p = a; p - a < n; p++) {
    printf("%f", *p);
    if (p - a < n - 1)
      printf(" ");
    else
      printf("\n");
  }
}

void input(double *a, int n) {
  for (double *p = a; p - a < n; p++) {
    scanf("%lf", p);
  }
}
