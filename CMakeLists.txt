cmake_minimum_required(VERSION 3.20)

project(VDB
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(vdb
    src/main.cpp
    src/storage/page.cpp
)

target_include_directories(vdb PRIVATE
    src
)

add_executable(test_page
    tests/test_page.cpp
    src/storage/page.cpp
)

target_include_directories(test_page PRIVATE
    src
)

add_test(
    NAME PageTest
    COMMAND test_page
)
