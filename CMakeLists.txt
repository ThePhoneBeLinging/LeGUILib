cmake_minimum_required(VERSION 3.28)
project(LeGUILib)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

target_include_directories(LeGUILib PUBLIC src/include)