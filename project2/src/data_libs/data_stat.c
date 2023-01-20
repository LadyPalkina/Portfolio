#include "data_stat.h"
#include <stdio.h>

double max(double *a, int n) {
  double mx = *a;
  for (double *p = a; p - a < n; p++)
    if (mx < *p)
      mx = *p;

  return mx;
}

double min(double *a, int n) {
  double mn = a[0];
  for (double *p = a; p - a < n; p++)
    if (mn > *p)
      mn = *p;

  return mn;
}

double mean(double *a, int n) {
  double m = 0;
  for (double *p = a; p - a < n; p++)
    m = m + *p;
  m = m / n;
  return m;
}

double variance(double *a, int n) {
  double s = 0;
  double mean1 = mean(a, n);
  for (double *p = a; p - a < n; p++)
    s += (*p - mean1) * (*p - mean1);
  s = s / n;
  return s;
}

void sort(double *a, int n) {
  double temp;
  for (double *p = a; p - a < n; p++) {
    for (double *q = p + 1; q - a < n; q++) {
      if (*q < *p) {
        temp = *q;
        *q = *p;
        *p = temp;
      }
    }
  }
}
