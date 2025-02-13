CC=gcc
CFLAGS=  -Wall -Werror -Wextra 


all: main

main: door_struct list_test# stack_test

door_struct: clean dmanager_module.o
	$(CC) dmanager_module.o -o ../build/Quest_1 && ../build/Quest_1

list_test: clean list_test.o list.o
	$(CC) list.o list_test.o -o ../build/Quest_2 && ../build/Quest_2

dmanager_module.o:
	$(CC) $(CFLAGS) -c dmanager_module.c
	
list_test.o:
	$(CC) $(CFLAGS) -c list_test.c

list.o:
	$(CC) $(CFLAGS) -c list.c

clean:
	rm -rf *.o
rebuild:
	$(MAKE) clean
	$(MAKE) all
