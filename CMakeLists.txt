cmake_minimum_required(VERSION 3.10)
project(panoscan C)

set(CMAKE_C_STANDARD 11)

find_package(CURL REQUIRED)

add_executable(panoscan src/main.c)
target_link_libraries(panoscan CURL::libcurl)
