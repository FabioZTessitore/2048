CFLAGS=-Wall -ansi

test_tile: test_tile.o tile.o
test_tile.o: test_tile.c

test_int_list: test_int_list.o int_list.o
test_int_list.o: test_int_list.c

tile.o: tile.c
int_list.o: int_list.c

clean:
	rm -f *.o test_int_list test_tile
