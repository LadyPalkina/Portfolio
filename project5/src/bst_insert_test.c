#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#define ROOT 7
void test(int i, int fl);
int main() {
  test(6, -1);
  printf("\n");
  test(19, 1);
}
void test(int i, int fl) {
  printf("%d     %d", ROOT, i);
  struct t_btree *root = bstree_create_node(ROOT);
  bstree_insert(root, i, max);

  printf("\nЗначение левого элемента корня\n");
  if (root->left == NULL)
    printf("NULL ");
  else
    printf("%d", root->left->item);
  printf("\nЗначение правого элемента корня\n");
  if (root->right == NULL)
    printf("NULL\n");
  else
    printf("%d", root->right->item);
  if (fl == 1) {
    if (root->right->item == i)
      printf("\nSUCCES");
    else
      printf("\nFAIL");
    bstree_free(root);
  } else {
    if (root->left->item == i)
      printf("\nSUCCES");
    else
      printf("\nFAIL");
    bstree_free(root);
  }
}
