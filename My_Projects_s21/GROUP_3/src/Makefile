CC=gcc
CFLAGS=  -Wall -Werror -Wextra 


all: stack.o polish_notation.o
	$(CC) stack.o polish_notation.o -o ../build/graph 

stack.o:
	$(CC) $(CFLAGS) -c stack.c

polish_notation.o:
	$(CC) $(CFLAGS) -c polish_notation.c

clean:
	rm -rf *.o
rebuild:
	$(MAKE) clean
	$(MAKE) all
