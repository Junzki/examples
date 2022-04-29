cmake_minimum_required(VERSION 3.8)

PROJECT(word_count CXX)

add_executable(word_count word_count.cpp main.cpp)


add_library(libword_count STATIC word_count.cpp)
add_executable(test_count test_count.cpp)
target_link_libraries(test_count libword_count)

add_test(NAME test_count COMMAND test_count WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Testing)
