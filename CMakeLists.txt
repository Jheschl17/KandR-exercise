cmake_minimum_required(VERSION 3.15)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(detab detab.c)
add_executable(hextodex hextodec.c)
add_executable(any any.c)
add_executable(setbits setbits.c)
add_executable(bitcount bitcount.c)