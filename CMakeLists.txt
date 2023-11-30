cmake_minimum_required(VERSION 3.24)
project(kalkulator C)

set(CMAKE_C_STANDARD 11)

add_executable(kalkulator main.c sum.c sum.h turntointchar.c turntointchar.h division.c division.h compare.c compare.h subtract.c subtract.h mutliplication.c mutliplication.h readinfile.c readinfile.h power.c power.h modulo.c modulo.h convert.c convert.h)
