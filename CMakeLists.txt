cmake_minimum_required(VERSION 3.10)
project(auto_suggest_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(auto_suggest ${SOURCES})

target_include_directories(auto_suggest PRIVATE include)
