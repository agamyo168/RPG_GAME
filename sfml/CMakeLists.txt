cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use clang++ as the compiler
set(CMAKE_CXX_COMPILER "clang++")

# Find SFML
# find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add executable
add_executable(my_program)

# Group source files
target_sources(my_program
    PRIVATE
        src/main.cpp
        src/Game/Game.cpp
)

# Group header files
target_include_directories(my_program
    PUBLIC
    include
)

# Link SFML libraries
target_link_libraries(my_program
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)