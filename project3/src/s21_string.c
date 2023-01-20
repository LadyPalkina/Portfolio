#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>

int s21_strlen(const char *start) {
  const char *end = start;
  for (; *end != '\0'; ++end) {
  }
  return end - start;
}

int s21_strcmp(const char *str1, const char *str2) {
  float rez = 0;
  for (int i = 0; i <= s21_strlen(str1); i++) {
    rez = (char)str1[i] - (char)str2[i];
    if (rez != 0)
      break;
  }
  if (rez < 0)
    rez = -1;
  else if (rez > 0)
    rez = 1;
  return rez;
}

char *s21_strcpy(char *str2, const char *str1) {
  str2 = malloc((s21_strlen(str1) + 1) * sizeof(char));
  for (int i = 0; i <= s21_strlen(str1); i++) {
    str2[i] = str1[i];
  }
  return str2;
}

char *s21_strcat(char *str, const char *str2) {
  char *tmp = malloc((s21_strlen(str) + s21_strlen(str2) + 1) * sizeof(char));
  int len_1 = s21_strlen(str);
  for (int i = 0; i < len_1; i++) {
    tmp[i] = str[i];
  }
  for (int i = 0; i <= s21_strlen(str2); i++) {
    tmp[i + len_1] = str2[i];
  }
  str = s21_strcpy(str, tmp);
  free(tmp);
  return str;
}

char *s21_strchr(char *str, char fl) {
  char *point = str;
  for (; !(*point == '\0' || *point == fl); ++point) {
  }
  if (*point == '\0')
    point = NULL;
  return point;
}

int srav(const char *str1, const char *str2) {
  float rez = 0;
  for (int i = 0; i < s21_strlen(str1); i++) {
    rez = (char)str1[i] - (char)str2[i];
    if (rez != 0)
      break;
  }
  return rez;
}

char *s21_strstr(char *str, const char *fl) {
  char *point = str;
  for (; !(*point == '\0' || srav(fl, point) == 0); ++point) {
    // printf("%d\n",s21_strcmp(point,fl))
  }
  if (*point == '\0' && *fl != '\0') {
    point = NULL;
  }
  return point;
}
