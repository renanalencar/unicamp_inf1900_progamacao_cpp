cmake_minimum_required(VERSION 3.27)
project(matriz VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(matriz matriz.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
