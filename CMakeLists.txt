cmake_minimum_required(VERSION 3.6)
project(OGL)

#find_package(GLUT)
#find_package(OpenGL)

#include_directories(${OPENGL_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
set(SOURCE_FILES main.cpp)

link_directories(${PROJECT_SOURCE_DIR}/bin ${PROJECT_SOURCE_DIR}/lib)

add_executable(OGL ${SOURCE_FILES})

target_link_libraries(OGL glew32s opengl32 glfw3)
