file(GLOB_RECURSE MATSOLVE_SOURCES src/*.cpp)

add_library(matSolve STATIC ${MATSOLVE_SOURCES})

target_include_directories(matSolve PUBLIC include)

