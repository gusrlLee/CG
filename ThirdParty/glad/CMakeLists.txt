cmake_minimum_required(VERSION 3.15)

add_library(GLAD_LIB
    src/glad.c
)

find_package(OpenGL REQUIRED)

target_include_directories( GLAD_LIB
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${OpenGL_INCLUDE_DIRS}
)

target_link_libraries(GLAD_LIB
    ${OPENGL_LIBRARIES}
)
