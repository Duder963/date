cmake_minimum_required(VERSION 3.29)
project(DATE VERSION 0.1
             DESCRIPTION "A music tag editor")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_subdirectory(lib/id3v2lib)
add_executable(date src/main.cpp)
target_include_directories(date PUBLIC
                           lib/id3v2lib/include)
target_link_libraries(date PUBLIC id3v2lib)
