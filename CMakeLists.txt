cmake_minimum_required(VERSION 3.15)
project(opengl_cookbook)

set(CMAKE_CXX_STANDARD 17)
# Disable GLFW tests.
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)

add_custom_target(generate_opengl
        COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/generate_opengl.py)

add_executable(example
        GL/src/glad.c src/main.cpp src/Window.cpp src/Window.h)
add_dependencies(example generate_opengl)

target_include_directories(example PRIVATE GL/include glfw/include)
target_link_libraries(example PRIVATE glfw)

