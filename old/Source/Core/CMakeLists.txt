cmake_minimum_required(VERSION 3.15)

add_library(Core 
)

target_link_libraries(Core glfw assimp)
target_include_directories(Core PUBLIC ${CMAKE_SOURCE_DIR}/Source)
# target_include_directories(Core PUBLIC ${ROOT_PATH})