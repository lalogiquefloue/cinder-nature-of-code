cmake_minimum_required( VERSION 3.10 FATAL_ERROR )
project( cinder-nature-of-code )

#if(MSVC)
#    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
#endif()

get_filename_component( CINDER_PATH "C:/DEV/Cinder" ABSOLUTE )
add_subdirectory( "${CINDER_PATH}" "${CMAKE_BINARY_DIR}/cinder" )
include( "${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake" )

add_subdirectory( chapter00/example_0_1 )
add_subdirectory( chapter00/example_0_2 )
