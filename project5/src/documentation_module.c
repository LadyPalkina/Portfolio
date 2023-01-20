#include "documentation_module.h"
#include <stdlib.h>

int validate(char *data) {
  int validation_result = !strcmp(data, Available_document);
  return validation_result;
}

int *check_available_documentation_module(int (*validate)(char *),
                                          int document_count, char **Docs) {
  int *check_rezult = (int *)malloc(document_count * sizeof(int));
  for (int i = 0; i < document_count; i++) {
    check_rezult[i] = (*validate)(Docs[i]);
  }
  return check_rezult;
}
