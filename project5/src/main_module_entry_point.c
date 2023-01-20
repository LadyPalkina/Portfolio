#include "documentation_module.h"
#include "print_module.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
#ifdef PRINTMODULE
  time_t rawtime;
  struct tm *timeinfo;
  char buffer[80];
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(buffer, 80, " %H:%M:%S ", timeinfo);
  print_log(print_char, Log_prefix);
  print_log(print_char, buffer);
  print_log(print_char, Module_load_success_message);
#elif DOCUMMODULE

  char *Docs[] = {Documents};
  int DocsSize = (int)(sizeof(Docs) / sizeof(char *));
  if (DocsSize > Documents_count) {
    printf("n/a");
    return 0;
  }
  int *availability_mask =
      check_available_documentation_module(validate, DocsSize, Docs);
  for (int i = 0; i < DocsSize; i++) {
    print_log(print_char, Docs[i]);
    print_char(':');
    if (availability_mask[i] == 0)
      print_log(print_char, "unavailable");
    else
      print_log(print_char, "available");
    if (i != DocsSize - 1)
      print_char('\n');
  }
  free(availability_mask);
#endif

  return 0;
}
