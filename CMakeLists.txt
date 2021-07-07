cmake_minimum_required(VERSION 3.0.0)
project(lazyscript-interpreter VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB LAZYSCRIPT_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB LAZYSCRIPT_HEADERS ${CMAKE_SOURCE_DIR}/include/*.hpp)

add_executable(lazyscript-interpreter ${LAZYSCRIPT_SOURCES} ${LAZYSCRIPT_HEADERS})
target_include_directories(lazyscript-interpreter PUBLIC ${CMAKE_SOURCE_DIR}/include/)

set_property(TARGET lazyscript-interpreter PROPERTY CXX_STANDARD 17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
