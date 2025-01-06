cmake_minimum_required(VERSION 3.28)
project(LeGUILib)

set(CMAKE_CXX_STANDARD 20)

add_library(LeGUILib SHARED
        LeGUILib.cpp
        GUIElements/Text.cpp
        ElementUpdaterController.cpp
        ElementUpdaterController.h
        GUIElements/GUIElement.cpp
        GUIElements/GUIElement.h
)