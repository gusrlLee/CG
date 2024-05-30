cmake_minimum_required(VERSION 3.15)


add_library(Metal_Renderer
    # Metal_Renderer.mm
    MtGraphicsContext.mm
    MtDevice.mm
    MtCommandQueue.mm
    MtRenderPipeline.mm
    MtBuffer.mm
)

target_link_libraries(Metal_Renderer METAL_CPP glfw)
# target_include_directories(Renderer PUBLIC ${ROOT_PATH})
target_include_directories(Metal_Renderer PUBLIC ${CMAKE_SOURCE_DIR}/Source)