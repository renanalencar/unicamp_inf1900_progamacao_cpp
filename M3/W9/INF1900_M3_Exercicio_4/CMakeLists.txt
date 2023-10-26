cmake_minimum_required(VERSION 3.27)
project(INF1900_M3_Exercicio_4 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(INF1900_M3_Exercicio_4 main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
