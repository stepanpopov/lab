cmake_minimum_required(VERSION 3.20)
project(pracsem_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(pracsem_2
        dbmsLib.h
        testDB.cpp)

add_executable(main main.cpp)
target_link_libraries(main ${CMAKE_SOURCE_DIR}/libbingitup.a)
