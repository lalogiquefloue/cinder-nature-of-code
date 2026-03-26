cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(cinder-nature-of-code)

get_filename_component(CINDER_PATH "C:/DEV/Cinder" ABSOLUTE)
add_subdirectory("${CINDER_PATH}" "${CMAKE_BINARY_DIR}/cinder")
include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

include_directories(include)

add_subdirectory(chapter00_randomness/example_0_1)
add_subdirectory(chapter00_randomness/example_0_2)
add_subdirectory(chapter00_randomness/example_0_3)
