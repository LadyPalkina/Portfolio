#include "../data_libs/data_io.h"
#include "decision.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  double *data;
  int n;

  if (scanf("%d", &n) == 0 || n < 0) {
    printf("n/a");
    return 0;
  }
  data = malloc(n * sizeof(double));
  // Don`t forget to allocate memory !

  input(data, n);

  if (make_decision(data, n))
    printf("YES");
  else
    printf("NO");

  free(data);
  return 0;
}
