#include <stdio.h>

#include "print_module.h"

char print_char(char ch) { return putchar(ch); }
void print_log(char (*print)(char), char *message) {
  // puts(message);
  for (; *message != '\0'; message++)
    print(*message);
}
