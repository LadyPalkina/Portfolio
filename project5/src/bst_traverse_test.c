#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  struct t_btree *root = bstree_create_node(7);
  bstree_insert(root, 9, max);
  bstree_insert(root, 42, max);
  bstree_insert(root, -8, max);
  bstree_insert(root, 0, max);
  bstree_insert(root, 5, max);
  bstree_insert(root, -12345, max);
  printf("7, 9, 42, -8, 0, 5, -12345\n\n");
  bstree_apply_prefix(root, print);
  printf("\n");
  printf("7 -12345 -8 0 5 9 42\n\n");
  bstree_apply_infix(root, print);
  printf("\n");
  printf("-12345 -8 0 5 7 9 42\n\n");
  bstree_apply_postfix(root, print);
  printf("\n");
  printf("-12345 -8 0 5 9 42 7");
  bstree_free(root);
}
