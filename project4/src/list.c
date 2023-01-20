#include "list.h"
#include <stdio.h>
#include <stdlib.h>
struct node *init(struct door door) {
  struct node *elem = (struct node *)malloc(sizeof(struct node));
  elem->door = door;
  elem->next = NULL;
  return (elem);
}

struct node *add_door(struct node *elem, struct door door) {
  struct node *add = init(door);
  add->next = elem->next;
  elem->next = add;
  return (add);
}

struct node *find_door(int door_id, struct node *root) {
  struct node *p = root;
  while (p->next != NULL && p->door.id != door_id) {
    p = p->next;
  }
  return (p);
}

struct node *remove_door(struct node *elem, struct node *root) {
  struct node *p = root;
  if (elem == root) {
    root = p->next;
  } else {
    while (p->next != elem) {
      p = p->next;
    }
    p->next = elem->next;
  }
  free(elem);
  return root;
}

void destroy(struct node *root) {
  struct node *p = root->next;
  while (p != NULL) {
    p = p->next;
    free(root);
    root = p;
  }
}
