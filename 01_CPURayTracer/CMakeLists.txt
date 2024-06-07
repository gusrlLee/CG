cmake_minimum_required(VERSION 3.15)

set(SAMPLE_PROJECT_NAME 01_CPURayTracer)

file(GLOB SAMPLE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${SAMPLE_PROJECT_NAME}
    ${SAMPLE_SOURCES}
)

target_include_directories(${SAMPLE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories(${SAMPLE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/ThirdParty/glad/include)
target_include_directories(${SAMPLE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/ThirdParty)

target_link_libraries(${SAMPLE_PROJECT_NAME} Lee)
target_link_libraries(${SAMPLE_PROJECT_NAME} GLAD_LIB)
target_link_libraries(${SAMPLE_PROJECT_NAME} glm::glm-header-only)