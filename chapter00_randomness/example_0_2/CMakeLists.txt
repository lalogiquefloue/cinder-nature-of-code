ci_make_app(
    APP_NAME    "example_0_2"
    CINDER_PATH ${CINDER_PATH}
    SOURCES     ${CMAKE_CURRENT_SOURCE_DIR}/src/example_0_2.cpp
    INCLUDES    ${CMAKE_SOURCE_DIR}/include
    # RESOURCES   ${APP_PATH}/resources
)