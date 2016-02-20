CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=
PROGRAM=test_random

test_random: test_random.o random.o
	$(CC) -o $(PROGRAM) $^

test_random.o: test_random.c
random.o: random.c

clean:
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
