cmake_minimum_required(VERSION 3.8)

project(read_write CXX)

add_executable(sender src/sender.cpp)
add_executable(receiver src/receiver.cpp)
