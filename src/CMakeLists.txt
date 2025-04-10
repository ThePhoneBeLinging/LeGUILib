cmake_minimum_required(VERSION 3.25)
project(LeGUILib)

set(CMAKE_CXX_STANDARD 20)

set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif ()
endif ()

add_library(LeGUILib STATIC
        LeGUILib.cpp
        GUIElements/Text.cpp
        ElementUpdaterController.cpp
        GUIElements/GUIElement.cpp
        GUIElements/RectangleElement.cpp
        GUIElements/ImageElement.cpp
        GUIElements/Slide.cpp
        raylibIncludeFile.h
)

target_include_directories(LeGUILib PUBLIC include)
target_link_libraries(LeGUILib PUBLIC TouchCore-CPP)
target_link_libraries(LeGUILib PUBLIC raylib)