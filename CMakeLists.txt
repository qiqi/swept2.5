cmake_minimum_required (VERSION 2.6)

project (swept2.5)

set(warnings "-Wall -Wextra -Werror")
# set(CMAKE_CXX_FLAGS "${warnings}")
# set(CMAKE_C_FLAGS   "${warnings}")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)

include_directories(src)

add_library(chunks_overlappyramid_serial SHARED src/chunks/overlappyramid_serial.c)
