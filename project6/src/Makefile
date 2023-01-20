CC=gcc 
PUT=../build/

all: clear_state state_search state_sort

state_sort:
	$(CC) state_sort.c  -o $(PUT)Quest_1
state_search:
	$(CC)  state_search.c  -o $(PUT)Quest_2
clear_state:
	$(CC) clear_state.c -o $(PUT)Quest_3
clean:
	rm -rf $(PUT)Quest*
rebuild: clean all
