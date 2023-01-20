CC=gcc -Wall -Werror -Wextra
SOURSES=main_module_entry_point.c print_module.c  documentation_module.c
PUT=../build/

all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test

print_module:
	$(CC) $(SOURSES) -D PRINTMODULE  -o $(PUT)Quest_1
documentation_module:
	$(CC) $(SOURSES) -D DOCUMMODULE  -o $(PUT)Quest_2
bst_create_test:
	$(CC) bst.c bst_create_test.c -o $(PUT)Quest_3
bst_insert_test:
	$(CC) bst.c bst_insert_test.c -o $(PUT)Quest_4
bst_traverse_test:
	$(CC) bst.c bst_traverse_test.c -o $(PUT)Quest_5
clean:
	rm -rf $(PUT)Quest*
rebuild: clean all
