ci_make_app(
        APP_NAME "example_0_6"
        CINDER_PATH ${CINDER_PATH}
        SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/example_0_6.cpp
        INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include
        # RESOURCES   ${CMAKE_CURRENT_SOURCE_DIR}/resources
)
