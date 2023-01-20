#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

struct t_btree *bstree_create_node(int item) {
  struct t_btree *tree = (struct t_btree *)malloc(sizeof(struct t_btree));
  tree->item = item;
  tree->left = NULL;
  tree->right = NULL;
  return tree;
}

void bstree_insert(struct t_btree *root, int item, int (*cmpf)(int, int)) {
  if (root == NULL) {
    root = bstree_create_node(item);
  } else if (cmpf(item, root->item)) {
    if (root->left == NULL)
      root->left = bstree_create_node(item);
    else
      bstree_insert(root->left, item, cmpf);
  } else {
    if (root->right == NULL)
      root->right = bstree_create_node(item);
    else
      bstree_insert(root->right, item, cmpf);
  }
}

void bstree_apply_infix(struct t_btree *root, void (*applyf)(int)) {
  if (root != NULL) {
    bstree_apply_infix(root->left, applyf);
    applyf(root->item);
    bstree_apply_infix(root->right, applyf);
  }
}

void bstree_apply_prefix(struct t_btree *root, void (*applyf)(int)) {
  if (root != NULL) {
    applyf(root->item);
    bstree_apply_infix(root->left, applyf);
    bstree_apply_infix(root->right, applyf);
  }
}
void bstree_apply_postfix(struct t_btree *root, void (*applyf)(int)) {
  if (root != NULL) {
    bstree_apply_infix(root->left, applyf);
    bstree_apply_infix(root->right, applyf);
    applyf(root->item);
  }
}

void bstree_free(struct t_btree *tree) {
  if (tree != NULL) {
    bstree_free(tree->left);
    bstree_free(tree->right);
    free(tree);
  }
}
int max(int a, int b) {
  int flag;
  if (a < b)
    flag = 1;
  else
    flag = 0;
  return flag;
}
void print(int i) { printf("%d ", i); }
