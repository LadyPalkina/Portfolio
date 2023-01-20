#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>
void output(const char *str) {
  for (int i = 0; i <= s21_strlen(str); i++) {
    printf("%c", str[i]);
  }
}
void proverka(int i) {
  if (i == 1)
    printf("SUCCESS");
  else
    printf("FAIL");
}

void log_strlen_test(const char *str, int n) {
  printf("%s\n", str);
  printf("%d\n", s21_strlen(str));
  proverka(s21_strlen(str) == n);
}
void s21_strlen_test() {
  log_strlen_test("Have a nice day!", 16);
  printf("\n");
  log_strlen_test("", 0);
  printf("\n");
  log_strlen_test("Ты классный(ая)!!", 29);
}
void log_strcmp_test(const char *str, const char *str2, int n) {
  printf("%s  %s", str, str2);
  printf("\n%d\n", s21_strcmp(str, str2));
  proverka(s21_strcmp(str, str2) == n);
}
void s21_strcmp_test() {
  log_strcmp_test("Have a nice day!", "Have a beautiful day!", 1);
  printf("\n");
  log_strcmp_test("", "", 0);
  printf("\n");
  log_strcmp_test("Ты классный(ая)!!", "Ты потрясающий(ая)!!", -1);
}
void log_strcpy_test(char *str, const char *str2) {
  output(str);
  printf("\n");
  output(str2);
  printf("\n");
  str = s21_strcpy(str, str2);
  for (int i = 0; i <= s21_strlen(str); i++) {
    printf("%c", str[i]);
  }
  printf("\n");
  proverka(s21_strcmp(str, str2) == 0);
  free(str);
}
void s21_strcpy_test() {
  log_strcpy_test("123321", "Hallelujah");
  printf("\n");
  log_strcpy_test("тут что-то не пустое", "");
  printf("\n");
  log_strcpy_test("непривет", "Привет!");
}

void log_strcat_test(char *str, const char *str2, const char *rez) {
  output(str);
  printf("\n");
  output(str2);
  printf("\n");
  str = s21_strcat(str, str2);
  output(str);
  printf("\n");
  proverka(s21_strcmp(str, rez) == 0);
  free(str);
}

void s21_strcat_test() {
  log_strcat_test("Привет! ", "Бонжур! Хеллоу!", "Привет! Бонжур! Хеллоу!");
  printf("\n");
  log_strcat_test("", "", "");
  printf("\n");
  log_strcat_test("Show must", " go on", "Show must go on");
}

void log_strchr_test(char *str, char fl, const char *rez) {
  output(str);
  printf("\n");
  printf("%c\n", fl);
  char *tmp;
  tmp = (s21_strchr(str, fl));
  if (tmp == NULL) {
    printf("NULL\n");
    proverka(rez == NULL);
  } else {
    output(tmp);
    printf("\n");
    proverka(s21_strcmp(tmp, rez) == 0);
  }
}

void log_strstr_test(char *str, const char *fl, const char *rez) {
  output(str);
  printf("\n");
  output(fl);
  printf("\n");
  char *tmp;
  tmp = (s21_strstr(str, fl));
  if (tmp == NULL) {
    printf("NULL\n");
    proverka(rez == NULL);
  } else {
    output(tmp);
    printf("\n");
    proverka(s21_strcmp(tmp, rez) == 0);
  }
}

void s21_strchr_test() {
  log_strchr_test("I Want to Break Free", 'B', "Break Free");
  printf("\n");
  log_strchr_test("Я свободен, словно птица в небесах", ',',
                  ", словно птица в небесах");
  printf("\n");
  log_strchr_test("", 'B', NULL);
}
void s21_strstr_test() {
  log_strstr_test("I Want to Break Free", "Br", "Break Free");
  printf("\n");
  log_strstr_test("Я свободен, словно птица в небесах", "hey", NULL);
  printf("\n");
  log_strstr_test("", "", "");
}

int main() {
  name return 0;
}
