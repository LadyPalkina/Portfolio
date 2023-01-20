#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#define ROOT 7
void test(int i);

int main() {
  test(6);
  printf("\n");
  test(-4);
  printf("\n");
  test(0);
}

void test(int i) {
  printf("%d\n", i);
  struct t_btree *root = bstree_create_node(i);
  printf("%d ", root->item);
  if (root->left == NULL)
    printf("NULL ");
  if (root->right == NULL)
    printf("NULL\n");
  if (root->item == i && root->left == NULL && root->right == NULL)
    printf("SUCCES");
  else
    printf("FAIL");
  bstree_free(root);
}
