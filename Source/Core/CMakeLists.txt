cmake_minimum_required(VERSION 3.15)

add_library(Core 
    Application.cpp
)

target_link_libraries(Core glfw)
# target_include_directories(Core PUBLIC ${ROOT_PATH})