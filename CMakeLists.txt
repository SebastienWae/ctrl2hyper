cmake_minimum_required(VERSION 3.0)

project(ctrl2hyper)

add_executable(ctrl2hyper ctrl2hyper.c)
target_compile_options(ctrl2hyper PRIVATE -Wall -Wextra)

install(TARGETS ctrl2hyper RUNTIME DESTINATION bin)
