cmake_minimum_required(VERSION 3.30)
project(Black_Scholes__Monte_Test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.h)

add_executable(Black_Scholes__Monte_Test
        main_test.cpp
        ${SOURCES} ${HEADERS}
        src/Options__TEST.cpp
        include/TestObjectGenerators.h
)

target_include_directories(Black_Scholes__Monte_Test PRIVATE
    ${gtest_SOURCE_DIR}/include
    ${gmock_SOURCE_DIR}/include
)

target_link_libraries(Black_Scholes__Monte_Test gtest gtest_main gmock gmock_main)
include(GoogleTest)
gtest_discover_tests(Black_Scholes__Monte_Test)