project (2048_ncurses)

add_executable (2048_ncurses main_ncurses.c)
target_link_libraries (2048_ncurses ncurses Board Tile)
