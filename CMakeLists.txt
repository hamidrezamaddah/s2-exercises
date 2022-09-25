cmake_minimum_required(VERSION 3.0.0)
project(bomgen VERSION 0.1.0)

include(CTest)
enable_testing()

# add_executable(base64 06-base64/base64.cpp )
# target_include_directories(base64 PRIVATE 06-base64)

# add_executable(textbar 07-text_bar_chart/textbarchart.cpp )
# target_include_directories(base64 PRIVATE 07-text_bar_chart)

add_executable(bomgen 08-bom_gen/bomgen.cpp )
target_include_directories(bomgen PRIVATE 08-bom_gen)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
