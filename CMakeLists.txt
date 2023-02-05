cmake_minimum_required(VERSION 3.15)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

project(leetcode${CODE_NUMBER})

add_library(prog${CODE_NUMBER} STATIC src/leetcode${CODE_NUMBER}.cpp)

add_compile_definitions(LEETCODE${CODE_NUMBER})

add_executable(${PROJECT_NAME} src/leetcode_base.cpp)
target_link_libraries(${PROJECT_NAME} prog${CODE_NUMBER})