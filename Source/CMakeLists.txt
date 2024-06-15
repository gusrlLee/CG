cmake_minimum_required(VERSION 3.15)

add_executable(${PROJECT_NAME} 
    main.cpp

    Graphics/Metal/MtDevice.cpp

    Renderer/Device.cpp
    Renderer/RendererAPI.cpp
    # Renderer/SwapChain.cpp

    Application.cpp
    Window.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/Source)

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