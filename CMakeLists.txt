cmake_minimum_required(VERSION 3.13)
project(proj C)

set(CMAKE_C_STANDARD 99)

add_executable(proj main.c estado.h estado.c jogadas.c sugereJogadas.c scoreboard.c ficheiro.c undo.c stack.c bot.c)

target_link_libraries(proj m)