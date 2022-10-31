cmake_minimum_required(VERSION 3.23)
project(yo_dwm C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(src)
include_directories(src/keys)
include_directories(src/layouts)

add_executable(yo_dwm
        src/keys/keys.c
        src/keys/keys.h
        src/layouts/centeredmaster.c
        src/layouts/centeredmaster.h
        src/layouts/fibonacci.c
        src/layouts/grid.c
        src/layouts/layouts.h
        src/layouts/monocle.c
        src/layouts/tile.c
        src/colors.h
        src/config.h
        src/drw.c
        src/drw.h
        src/dwm.c
        src/movestack.c
        src/transient.c
        src/util.c
        src/util.h)
