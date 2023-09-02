cmake_minimum_required(VERSION 3.27)
project(jewel_collector VERSION 1.0.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(jewel_collector jogo.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
