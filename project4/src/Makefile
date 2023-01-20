CC=gcc -Wall -Werror -Wextra
SOURSES=s21_string_test.c s21_string.c
PUT=../build/

all: door_struct list_test stack_test

door_struct:
	$(CC) dmanager_module.c -o $(PUT)Quest_1
list_test:
	$(CC) list_test.c list.c -o $(PUT)Quest_2
stack_test:
	$(CC) stack_test.c stack.c -o $(PUT)Quest_3

clean:
	rm -rf $(PUT)Quest*
rebuild: clean all
