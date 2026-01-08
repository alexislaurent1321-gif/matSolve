cmake_minimum_required(VERSION 3.20)
project(matSolve VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(matSolve STATIC
    src/*.cpp
)

target_include_directories(matSolve PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

install(TARGETS matSolve
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)
install(DIRECTORY include/matSolve DESTINATION include)

