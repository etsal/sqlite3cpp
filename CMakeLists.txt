cmake_minimum_required(VERSION 3.20)
project(sqlite3cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

option(SQLITE3CPP_BUILD_TESTS "Build tests" ON)

add_library(sqlite3cpp INTERFACE)
target_include_directories(sqlite3cpp INTERFACE include)

if (SQLITE3CPP_BUILD_TESTS)
    add_subdirectory(test)
endif ()
