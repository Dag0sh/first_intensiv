CC=gcc
CFLAGS= -Wall -Werror -Wextra 

all: main

main: cipher logging_cipher

cipher: CFLAGS += -Dci
cipher: clean cipher.o 
	$(CC) cipher.o -o ../build/cipher && ../build/cipher

logging_cipher: CFLAGS += -Dlog
logging_cipher: clean cipher.o logger.o
	$(CC) cipher.o logger.o -o ../build/logging_cipher && ../build/logging_cipher

cipher.o:
	$(CC) $(CFLAGS) -c cipher.c

logger.o:
	$(CC) $(CFLAGS) -c logger.c

clean:
	rm -rf *.o
rebuild:
	$(MAKE) clean
	$(MAKE) all