cmake_minimum_required(VERSION 3.15)
project(OWN_ENGINE)
set(CMAKE_CXX_STANDARD 17)

option(USE_OPENGL_API "Using OpenGL API of RendererAPI" OFF)
option(USE_METAL_API "Using Metal API of RendererAPI" ON)
option(USE_VULKAN_API "Using Vulkan API of RendererAPI" OFF)
option(USE_D3D12_API "Using DirectX 12 API of RendererAPI" OFF)

add_subdirectory(ThirdParty)

add_subdirectory(Source)
