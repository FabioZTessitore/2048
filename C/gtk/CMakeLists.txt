project (2048_gtk)

find_package (PkgConfig REQUIRED)
pkg_check_modules (GTK3 REQUIRED gtk+-3.0)

include_directories (${GTK3_INCLUDE_DIRS})
link_directories (${GTK3_LIBRARY_DIRS})

add_executable (2048_gtk main_gtk.c)
target_link_libraries (2048_gtk ${GTK3_LIBRARIES} Board Tile)
