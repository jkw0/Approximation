cmake_minimum_required(VERSION 3.0.0)
project(Approximation VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Approximation main.cpp PointsGenerator.cpp Approximation.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
