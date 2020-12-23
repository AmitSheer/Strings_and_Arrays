CC=gcc
AR=ar
FLAGS= -Wall -g
FILES= basicMath.c power.c
OBJECTS_LIB= basicMath.o power.o

.PHONY: all clean

export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

all: isort txtfind
main: main.c
	$(CC) $(FLAGS) -o main.o main.c txtfind.c
isort: isort.c isort.h
	gcc $(FLAGS) -o isort isort.c

txtfind: txtfind.c txtfind.h
	gcc $(FLAGS) -o txtfind txtfind.c


clean:
	rm -f *.o *.a *.so isort txtfind