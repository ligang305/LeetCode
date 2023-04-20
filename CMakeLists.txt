cmake_minimum_required(VERSION 3.0.0)
project(my_leet_code VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(my_leet_code 061-090/67_赎金.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
