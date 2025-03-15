cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use clang++ as the compiler
set(CMAKE_CXX_COMPILER "clang++")

# Add executable
add_executable(my_program src/main.cpp)

target_link_libraries(my_program sfml-graphics sfml-window sfml-system)