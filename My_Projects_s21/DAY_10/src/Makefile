CC=gcc
CFLAGS=  -Wall -Werror -Wextra 


all: main

main: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests

strlen_tests: CFLAGS += -DLENTEST
strlen_tests: clean s21_string.o s21_string_test.o
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_1 && ../build/Quest_1


strcmp_tests: CFLAGS += -Dcmptest
strcmp_tests: clean s21_string.o s21_string_test.o
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_2 && ../build/Quest_2


strcpy_tests: CFLAGS += -Dcpytest
strcpy_tests: clean s21_string.o s21_string_test.o
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_3 && ../build/Quest_3

strcat_tests: CFLAGS += -Dcattest
strcat_tests: clean s21_string.o s21_string_test.o
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_4 && ../build/Quest_4

strchr_tests: CFLAGS += -Dchrtest
strchr_tests: clean s21_string.o s21_string_test.o
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_5 && ../build/Quest_5

strstr_tests: CFLAGS += -Dstrtest
strstr_tests: clean s21_string.o s21_string_test.o
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_6 && ../build/Quest_6

s21_string.o:
	$(CC) $(CFLAGS) -c s21_string.c

s21_string_test.o:
	$(CC) $(CFLAGS) -c s21_string_test.c
	
clean:
	rm -rf *.o
rebuild:
	$(MAKE) clean
	$(MAKE) all
