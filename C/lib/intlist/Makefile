CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=
PROGRAM=test_int_list

test_int_list: test_int_list.o int_list.o
	$(CC) -o $(PROGRAM) $^

test_int_list.o: test_int_list.c
int_list.o: int_list.c

clean:
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
