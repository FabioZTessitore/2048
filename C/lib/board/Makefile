CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=
PROGRAM=test_board

test_board: test_board.o board.o ../tile/tile.o ../intlist/int_list.o ../random/random.o
	$(CC) -o $(PROGRAM) $^

test_board.o: test_board.c

board.o: board.c

clean:
	cd ../random && make clean
	cd ../tile && make clean
	cd ../intlist && make clean
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
