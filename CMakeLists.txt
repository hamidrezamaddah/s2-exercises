cmake_minimum_required(VERSION 3.0.0)
project(base64 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(base64 06-base64/base64.cpp  06-base64/bit_funcs.cpp)
target_include_directories(base64 PRIVATE 06-base64)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
