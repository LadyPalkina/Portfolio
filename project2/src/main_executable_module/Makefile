CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-Wextra -Werror
SOURCES=main_executable_module.c ../data_libs/data_io.c ../data_libs/data_stat.c ../yet_another_decision_module/decision.c ../data_module/data_process.c
HFILES=../data_libs/data_io.h ../data_libs/data_stat.h ../yet_another_decision_module/decision.h ../data_module/data_process.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../../build/Quest_3

all: $(SOURCES) $(HFILES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

data_stat.a: ../data_libs/data_stat.c ../data_libs/data_stat.h
	$(CC) $(CFLAGS) $(LDFLAGS) ../data_libs/data_stat.c
	ar rc libdata_stat.a ../data_libs/data_stat.o
	ranlib libdata_stat.a
build_with_static:
	$(CC) $(CFLAGS) $(LDFLAGS) main_executable_module.c
	make data_stat.a
	$(CC) main_executable_module.o ../data_libs/data_io.o libdata_stat.a ../yet_another_decision_module/decision.o ../data_module/data_process.o -o ../../build/Quest_5 
data_process.so:
	$(CC) $(CFLAGS) $(LDFLAGS) ../data_module/data_process.c
	$(CC) -shared -o libdata_process.so ../data_module/data_process.o ../data_libs/data_stat.o

build_with_dynamic: all data_process.so
	$(CC) -o ../../build/Quest_6 main_executable_module.o ../yet_another_decision_module/decision.o ../data_libs/data_io.o ../data_libs/data_stat.o -L. -ldata_process
	install_name_tool -change libdata_process.so ../src/main_executable_module/libdata_process.so ../../build/Quest_6




.c.o:
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) libdata_stat.a libdata_process.so

rebuild:
	make clean
	make