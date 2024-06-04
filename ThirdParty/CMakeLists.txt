cmake_minimum_required(VERSION 3.15)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw)

add_subdirectory(assimp)

if(WIN32)
    add_subdirectory(glad)

    set(GLM_BUILD_TESTS OFF)
    set(BUILD_SHARED_LIBS ON)
    add_subdirectory(glm)
endif()

# Metal API
if (APPLE)
    add_subdirectory(metal-cmake)
endif()