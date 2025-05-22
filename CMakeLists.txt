cmake_minimum_required(VERSION 3.30.5)
project(Black_Scholes__Monte)

set(CMAKE_CXX_STANDARD 26)

include_directories(include)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.h)

add_subdirectory(test)

add_executable(Black_Scholes__Monte main.cpp ${SOURCES} ${HEADERS}
        test/main_test.cpp)
