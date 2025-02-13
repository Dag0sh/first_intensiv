CC=gcc
CFCLAGS=-c -Wall -Werror -Wextra

all: Quest_3
clean:
	rm -rf *.o
	rm -rf ../data_libs/*.o
	rm -rf ../data_module/*.o
	rm -rf *.a
	rm -rf ../yet_another_decision_module/*.o
rebuild:
	$(MAKE) clean
	$(MAKE) all

Quest_3: data_io.o data_stat.o data_process.o decision.o main_executable_module.o
	$(CC) -o ../../build/Quest_3 data_io.o data_stat.o data_process.o decision.o main_executable_module.o 

data_io.o: ../data_libs/data_io.c
	$(CC) $(CFLAGS) -o data_io.c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -o data_stat.c ../data_libs/data_stat.c

data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) -o data_process.c ../data_module/data_process.c

decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) -o decision.c ../yet_another_decision_module/decision.c

main_executable_module: ../main_executable_module/main_executable_module.c
	$(CC) $(CFLAGS) -o main_executable_module.c ../main_executable_module/main_executable_module.c

data_stat.a: data-stat.o
	ar rcs data_stat.a data_stat.o

build_with_static: data_io.o data_stat.c data_process.o decision.o main_executable_module.o
	$(CC) -Wall -Werror -Wextra data_io.o data_stat.o data_process.o decision.o main_executable_module.o