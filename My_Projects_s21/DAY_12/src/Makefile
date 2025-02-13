CC=gcc
CFLAGS=  -Wall -Werror -Wextra 


all: main

main: print_module bst_create_test bst_insert_test

print_module: clean print_module.o main_module_entry_point.o
	$(CC) print_module.o main_module_entry_point.o -o ../build/Quest_1 && ../build/Quest_1

bst_create_test: clean bst.o bst_create_test.o
	$(CC) bst.o bst_create_test.o -o ../build/Quest_3 && ../build/Quest_3

bst_insert_test:clean bst.o bst_insert_test.o
	$(CC) bst.o bst_insert_test.o -o ../build/Quest_4 && ../build/Quest_4

print_module.o:
	$(CC) $(CFLAGS) -c print_module.c

main_module_entry_point.o:
	$(CC) $(CFLAGS) -c main_module_entry_point.c

bst.o:
	$(CC) $(CFLAGS) -c bst.c

bst_create_test.o:
	$(CC) $(CFLAGS) -c bst_create_test.c

bst_insert_test.o:
	$(CC) $(CFLAGS) -c bst_insert_test.c

clean:
	rm -rf *.o
rebuild:
	$(MAKE) clean
	$(MAKE) all
