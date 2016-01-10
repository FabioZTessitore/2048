CFLAGS=-Wall -ansi
LDFLAGS=-lncurses
PROGRAM=2048

2048_gtk: int_list.o random.o tile.o board.o main_gtk.o
	$(CC) -o $(PROGRAM) $^ `pkg-config --libs gtk+-3.0`

2048_ncurses: int_list.o random.o tile.o board.o main_ncurses.o
	$(CC) $(LDFLAGS) $^ -o $(PROGRAM)

2048_console: int_list.o random.o tile.o board.o main_console.o
	$(CC) $^ -o $(PROGRAM)

test: test_int_list test_tile test_board

test_board: test_board.o board.o tile.o int_list.o random.o
test_board.o: test_board.c

test_tile: test_tile.o tile.o
test_tile.o: test_tile.c

test_int_list: test_int_list.o int_list.o
test_int_list.o: test_int_list.c

main_gtk.o: main_gtk.c
	$(CC) -c `pkg-config --cflags gtk+-3.0` -o $@ $^

main_ncurses.o: main_ncurses.c
main_console.o: main_console.c
random.o: random.c
board.o: board.c
tile.o: tile.c
int_list.o: int_list.c

clean:
	rm -f *.o test_int_list test_tile test_board

uninstall:
	rm -f 2048
