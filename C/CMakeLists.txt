cmake_minimum_required (VERSION 2.6)

project (2048)

set (CMAKE_C_FLAGS "-Wall -ansi -pedantic")

include_directories (lib/random lib/tile lib/intlist lib/board)

add_subdirectory (lib)
add_subdirectory (console)
add_subdirectory (ncurses)
add_subdirectory (gtk)
