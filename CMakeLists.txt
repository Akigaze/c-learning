cmake_minimum_required(VERSION 3.16)
project(get_start C)

set(CMAKE_C_STANDARD 11)

add_executable(get_start main.c)
add_executable(helloworld helloworld/hello.c)
add_executable(escape string/escape.c)
add_executable(data_type data_type/cDataType.c)
add_executable(bitShift operation/comma.c)
add_executable(stringArray array/stringArray.c)
add_executable(functionDeclare function/functionDeclare.c function/math.c)
add_executable(localVariable variable/localVariable.c)
add_executable(macroDefine macro/macroDefine.c)