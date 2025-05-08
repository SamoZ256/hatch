cmake_minimum_required(VERSION 3.15...3.31)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(hatch VERSION 1.0 LANGUAGES CXX)

add_subdirectory(externals/toml11)

add_subdirectory(src)
