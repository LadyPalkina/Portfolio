CC=gcc 
PUT=

all: 1 start

1:
	$(CC) master_levels.c master_modules.c master_status_events.c shared.c modules_db.c -o $(PUT)Quest_1
start:
	$(PUT)./Quest_1
clean:
	rm -rf $(PUT)Quest*
rebuild: clean 1
