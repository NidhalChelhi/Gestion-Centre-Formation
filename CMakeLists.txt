cmake_minimum_required(VERSION 3.26)
project(ProjetC C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ProjetC
        bib.c
        bib.h
        main.c)
