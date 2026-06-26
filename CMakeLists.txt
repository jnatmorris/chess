cmake_minimum_required(VERSION 3.15)
project(MyCProject C)

# https://zed.dev/docs/languages/c#cmake-compile-commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Looks inside src/ and ALL subdirectories for .c files
file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(main ${SOURCES})

target_include_directories(main PRIVATE includes)

target_compile_options(main PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
