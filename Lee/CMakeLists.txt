cmake_minimum_required(VERSION 3.15)
add_library(Lee
    Core/Application.cpp
    Core/Window.cpp
)

target_link_libraries(Lee glfw)
target_link_libraries(Lee assimp)

if (WIN32)
    target_link_libraries(Lee GLAD_LIB)
    target_link_libraries(Lee glm::glm-header-only)
endif()

if (APPLE)
    target_link_libraries(Lee METAL_CPP)
endif()



