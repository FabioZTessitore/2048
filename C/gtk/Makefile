CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=
PROGRAM=2048

2048_gtk: ../lib/intlist/int_list.o ../lib/random/random.o ../lib/tile/tile.o ../lib/board/board.o main_gtk.o
	$(CC) -o $(PROGRAM) $^ `pkg-config --libs gtk+-3.0`

main_gtk.o: main_gtk.c
	$(CC) -c `pkg-config --cflags gtk+-3.0` -o $@ $^

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
