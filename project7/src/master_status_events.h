#ifndef SRC_MASTER_STATUS_EVENTS_H_
#define SRC_MASTER_STATUS_EVENTS_H_

struct event {
  int ev_id;
  int mod_id;
  int newst;
  char date[11];
  char time[9];
};
int delete_event(int i);
void insert_status_events(int ev_id, int mod_id, int newst, char *date,
                          char *time);
void print_status_events(struct event *c);
struct event *select_status_events(int i);
void all_status_events();
void update_status_events(int id, int place, int new);
int sizeevents();
#endif  // SRC_MASTER_STATUS_EVENTS_H_
