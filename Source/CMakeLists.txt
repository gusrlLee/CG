cmake_minimum_required(VERSION 3.15)

Project(RenderingEngine)

set(CMAKE_CXX_STANDARD 17)
set(ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(ThirdParty)
# add_subdirectory(Core)
add_subdirectory(Utils)
add_subdirectory(Renderer)
add_subdirectory(Platform)

add_executable(${PROJECT_NAME} 
    main.cpp
    Application.cpp
)

target_link_libraries(${PROJECT_NAME} Platform Renderer) 
