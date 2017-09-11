CC=gcc
CFLAGS=-I. -g -Wall
DEPS = list.h
OBJ = list.o list_test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

list_test3: list.o list_test.o
	gcc -o list_test3 list.o list_test.o -I.

clean:
	-rm -f list.o 
	-rm -f list_test.o 
	-rm -f list_test3