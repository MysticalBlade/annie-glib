cmake_minimum_required(VERSION 3.29)
project(annie_glib C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(annie_arbitrary_precision_arithmetic)
include_directories(annie_arbitrary_precision_arithmetic/aapa_int)

add_executable(annie_glib
    annie_arbitrary_precision_arithmetic/aapa_int/aapa_int_init.c
        annie_arbitrary_precision_arithmetic/aapa.h
        annie_arbitrary_precision_arithmetic/aapa_int/aapa_int_free.c)
