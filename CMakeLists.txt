cmake_minimum_required(VERSION 3.8)

project(Projekt2)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(sokoban
    src/main.cpp
    src/board.cpp
    src/fields.cpp
    src/show.cpp
    src/man.cpp
    src/score.cpp
)
target_include_directories(sokoban PUBLIC include)
set_target_properties(sokoban PROPERTIES
    CXX_STANDARD 20
)
