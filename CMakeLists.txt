cmake_minimum_required(VERSION 2.8)
project(cserver)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")
set (LIB_SRC
    cserver/log.cc
    cserver/log.h
    )
add_library(cserver SHARED ${LIB_SRC})

add_executable(test tests/test.cc)
add_dependencies(test cserver)
target_link_libraries(test cserver)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
