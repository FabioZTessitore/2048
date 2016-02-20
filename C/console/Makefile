CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=
PROGRAM=2048

2048_console: ../lib/intlist/int_list.o ../lib/random/random.o ../lib/tile/tile.o ../lib/board/board.o main_console.o
	$(CC) $^ -o $(PROGRAM)

main_console.o: main_console.c
board.o:
	cd ../lib/board; make board.o
random.o:
	cd ../lib/random; make random.o
tile.o:
	cd ../lib/tile; make tile.o
int_list.o:
	cd ../lib/intlist; make int_list.o

clean:
	cd ../lib/random; make clean
	cd ../lib/tile; make clean
	cd ../lib/intlist; make clean
	cd ../lib/board; make clean
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
