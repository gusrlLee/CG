cmake_minimum_required(VERSION 3.15)

add_executable(${PROJECT_NAME} 

    LE/glfwAdapter.mm
    LE/Core.cpp
    LE/Display.cpp
    LE/Scene.cpp
    LE/Renderer.cpp
    LE/Shader.cpp

    LE/stb_image.cpp
    Application.cpp
    main.cpp
)

# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/Source)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/ThirdParty)

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} assimp)
target_link_libraries(${PROJECT_NAME} METAL_CPP)
target_link_libraries(${PROJECT_NAME} objc)
target_link_libraries(${PROJECT_NAME} glm::glm-header-only)

if(USE_METAL_API)
    target_compile_definitions(${PROJECT_NAME} PUBLIC USE_METAL_API)
elseif(USE_OPENGL_API)
    target_compile_definitions(${PROJECT_NAME} PUBLIC USE_OPENGL_API)
elseif(USE_VULKAN_API)
    target_compile_definitions(${PROJECT_NAME} PUBLIC USE_VULKAN_API)
elseif(USE_D3D12_API)
    target_compile_definitions(${PROJECT_NAME} PUBLIC USE_D3D12_API)

endif()