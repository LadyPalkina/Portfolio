CC=gcc -Wall -Werror -Wextra
SOURSES=s21_string_test.c s21_string.c
PUT=../build/

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests

strlen_tests:
	$(CC) $(SOURSES) -o $(PUT)Quest_1 -Dname='s21_strlen_test();'
strcmp_tests:
	$(CC) $(SOURSES) -o $(PUT)Quest_2 -Dname='s21_strcmp_test();'
strcpy_tests:
	$(CC) $(SOURSES) -o $(PUT)Quest_3 -Dname='s21_strcpy_test();'
strcat_tests:
	$(CC) $(SOURSES) -o $(PUT)Quest_4 -Dname='s21_strcat_test();'
strchr_tests:
	$(CC) $(SOURSES) -o $(PUT)Quest_5 -Dname='s21_strchr_test();'
strstr_tests:
	$(CC) $(SOURSES) -o $(PUT)Quest_6 -Dname='s21_strstr_test();'

clean:
	rm -rf $(PUT)Quest*
rebuild: clean all
