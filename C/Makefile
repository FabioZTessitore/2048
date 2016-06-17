CFLAGS=-Wall -ansi
LDFLAGS=-lncurses
PROGRAM=2048

2048_ncurses:
	cd ./ncurses && make && cp ./2048 ../

2048_gtk:
	cd ./gtk && make && cp ./2048 ../

2048_console:
	cd ./console && make && cp ./2048 ../

test: test_random test_int_list test_tile test_board

test_board:
	cd ./lib/board && make test_board && cp ./test_board ../../
test_tile:
	cd ./lib/tile && make test_tile && cp ./test_tile ../../
test_int_list:
	cd ./lib/intlist && make test_int_list && cp ./test_int_list ../../
test_random:
	cd ./lib/random && make test_random && cp ./test_random ../../

clean:
	rm -f test_board test_random test_int_list test_tile
	cd ./lib/board && make clean && make uninstall;
	cd ./lib/intlist && make clean && make uninstall;
	cd ./lib/random && make clean && make uninstall;
	cd ./lib/tile && make clean && make uninstall;
	cd ./console && make clean && make uninstall;
	cd ./ncurses && make clean && make uninstall;
	cd ./gtk && make clean && make uninstall;
	rm -f *.o

uninstall:
	rm -f 2048
