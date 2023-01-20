#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#define lenght 8

void output(struct node *root, int rez[lenght]);
void outpt(struct node *root);
void obnul(int rez[lenght]);
void proverka(int rez[lenght], const int right[lenght]);
struct door newdoor(int id, int status);
void addtest(struct node *head, struct node *elem, struct door d2,
             int rez[lenght], int right[lenght]);
struct node *removetest(struct node *head, struct node *elem, int rez[lenght],
                        int right[lenght]);
int main() {
  int rez[lenght] = {0, 0, 0, 0, 0, 0, 0, 0};
  int right[lenght] = {1, 0, 2, 0, 0, 0, 0, 0};
  struct door d1 = newdoor(1, 0);
  struct door d2 = newdoor(2, 0);
  struct door d3 = newdoor(3, 0);
  struct door d4 = newdoor(99, 0);
  struct node *head = init(d1);
  printf("Test add_door\n");
  addtest(head, head, d2, rez, right);
  right[2] = 3;
  right[4] = 2;
  addtest(head, head, d3, rez, right);
  struct node *tmp = find_door(2, head);
  right[6] = 99;
  addtest(head, tmp, d4, rez, right);
  right[4] = 99;
  right[6] = 0;
  tmp = find_door(2, head);
  printf("Test remove_door\n");
  head = removetest(head, tmp, rez, right);
  right[4] = 0;
  right[0] = 3;
  right[2] = 99;
  head = removetest(head, head, rez, right);
  right[2] = 0;
  tmp = find_door(99, head);
  head = removetest(head, tmp, rez, right);
  destroy(head);
}

void output(struct node *root, int rez[lenght]) {
  struct node *p = root;
  int counter = 0;
  while (p != NULL) {
    printf("%d, %d\n", p->door.id, p->door.status);
    rez[counter] = (p->door.id);
    rez[counter + 1] = p->door.status;
    counter += 2;
    p = p->next;
  }
}
void outpt(struct node *root) {
  printf("%d, %d\n", root->door.id, root->door.status);
}
void obnul(int rez[lenght]) {
  for (int j = 0; j < lenght; j++) {
    rez[j] = 0;
  }
}
void proverka(int rez[lenght], const int right[lenght]) {
  int i = 1;
  for (int j = 0; j < lenght; j++) {
    if (rez[j] != right[j]) {
      printf("%d", rez[j]);
      i = 0;
    }
  }

  if (i == 1)
    printf("SUCCESS");
  else
    printf("FAIL");
}
struct door newdoor(int id, int status) {
  struct door new;
  new.id = id;
  new.status = status;
  return new;
}
void addtest(struct node *head, struct node *elem, struct door d2,
             int rez[lenght], int right[lenght]) {
  struct node *tmp = init(d2);
  printf("Input\n");
  output(head, rez);
  printf("\n");
  output(tmp, rez);
  printf("Output\n");
  obnul(rez);
  add_door(elem, d2);
  output(head, rez);
  proverka(rez, right);
  obnul(rez);
  printf("\n");
}

struct node *removetest(struct node *head, struct node *elem, int rez[lenght],
                        int right[lenght]) {
  printf("Input\n");
  output(head, rez);
  printf("\n");
  outpt(elem);
  printf("Output\n");
  obnul(rez);
  if (elem == head)
    head = remove_door(elem, head);
  else
    head = remove_door(elem, head);
  output(head, rez);
  proverka(rez, right);
  obnul(rez);
  printf("\n");

  return head;
}
