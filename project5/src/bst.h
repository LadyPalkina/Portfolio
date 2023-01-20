#ifndef  SRC_BST_H_
#define  SRC_BST_H_
struct t_btree {
  int item;
  struct t_btree *left;
  struct t_btree *right;
};

struct t_btree *bstree_create_node(int item);
void bstree_insert(struct t_btree *root, int item, int (*cmpf)(int, int));
void bstree_apply_infix(struct t_btree *root, void (*applyf)(int));
void bstree_apply_prefix(struct t_btree *root, void (*applyf)(int));
void bstree_apply_postfix(struct t_btree *root, void (*applyf)(int));
void bstree_free(struct t_btree *tree);
int max(int a, int b);
void print(int i);
#endif  // SRC_BST_H_
