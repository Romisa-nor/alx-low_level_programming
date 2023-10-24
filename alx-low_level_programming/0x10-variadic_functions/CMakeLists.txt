cmake_minimum_required(VERSION 3.26)
project(0x10_variadic_functions C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(0x10_variadic_functions
        0-sum_them_all.c
        1-print_numbers.c
        2-print_strings.c
        3-print_all.c
        variadic_functions.h)
