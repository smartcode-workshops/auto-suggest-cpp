cmake_minimum_required(VERSION 3.10)
project(auto_suggest_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GoogleTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "src/tests/*.cpp")

# 主可执行文件
add_executable(auto_suggest ${SOURCES})
target_include_directories(auto_suggest PRIVATE include)

# 测试可执行文件
add_executable(trie_tests ${TEST_SOURCES} src/trie.cpp)
target_include_directories(trie_tests PRIVATE include)
target_link_libraries(trie_tests GTest::GTest GTest::Main pthread)
