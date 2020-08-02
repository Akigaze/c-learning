cmake_minimum_required(VERSION 3.16)
project(get_start C)

set(CMAKE_C_STANDARD 11)

add_executable(get_start main.c)
add_executable(helloworld helloworld/hello.c)
add_executable(escape string/escape.c)