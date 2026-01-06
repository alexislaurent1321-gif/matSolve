cmake_minimum_required(VERSION 3.20)
project(matrixProject LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE SOURCES
    src/*.cpp
    tests/*.cpp
    examples/*.cpp
)

file(GLOB_RECURSE HEADERS
    include/*.h
    include/*.hpp
    include/numbers/*.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})


target_include_directories(${PROJECT_NAME} PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
)

message(STATUS "Configuration réussie")
