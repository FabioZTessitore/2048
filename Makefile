CFLAGS=-Wall -ansi

test: test_int_list test_tile test_board

test_board: test_board.o board.o tile.o int_list.o
test_board.o: test_board.c

test_tile: test_tile.o tile.o
test_tile.o: test_tile.c

test_int_list: test_int_list.o int_list.o
test_int_list.o: test_int_list.c

board.o: board.c
tile.o: tile.c
int_list.o: int_list.c

clean:
	rm -f *.o test_int_list test_tile test_board
