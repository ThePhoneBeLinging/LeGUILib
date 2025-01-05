cmake_minimum_required(VERSION 3.28)
project(LeGUILib)

set(CMAKE_CXX_STANDARD 20)

add_library(LeGUILib SHARED
        LeGUILib.cpp
        LeGUILib.h
        GUIElements/GUIElement.h
        GUIElements/Text.cpp
        GUIElements/Text.h
)

target_include_directories(LeGUILib PUBLIC include)