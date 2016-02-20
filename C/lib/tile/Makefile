CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=
PROGRAM=test_tile

test_tile: test_tile.o tile.o
	$(CC) -o $(PROGRAM) $^

test_tile.o: test_tile.c
tile.o: tile.c

clean:
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
