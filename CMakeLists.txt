cmake_minimum_required(VERSION 3.31)
project(Pong)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

# Download and build raylib
FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz
)
FetchContent_MakeAvailable(raylib)

add_executable(Snake main.cpp)

# Link raylib and its dependencies
target_link_libraries(Snake PRIVATE raylib)

# Add Win32 libs manually (required on MinGW)
if (WIN32)
    target_link_libraries(Snake PRIVATE winmm gdi32 opengl32)
endif()
