CFLAGS=-Wall -ansi

test_int_list: test_int_list.o int_list.o
test_int_list.o: test_int_list.c
int_list.o: int_list.c

clean:
	rm -f *.o test_int_list
