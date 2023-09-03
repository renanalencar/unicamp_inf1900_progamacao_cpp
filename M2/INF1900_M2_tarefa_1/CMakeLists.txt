cmake_minimum_required(VERSION 3.27)
project(jewel_collector VERSION 1.0.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES item.cpp item.h food.cpp food.h jewel.cpp jewel.h map.cpp map.h treasure.cpp treasure.h)
add_executable(jewel_collector main.cpp ${SOURCES})

set_target_properties(jewel_collector PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)