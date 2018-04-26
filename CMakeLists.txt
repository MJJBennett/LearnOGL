cmake_minimum_required(VERSION 3.2)
project(LearnOpenGL)

add_subdirectory("${PROJECT_SOURCE_DIR}/lib/glfw-3.2.1")

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/lib/glfw-3.2.1/include")
include_directories("${PROJECT_SOURCE_DIR}/lib/glad/include")
include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(LearnOpenGL
    main.cpp
    glad.c
    src/logl_print.cpp src/logl_print.h
)

target_link_libraries(LearnOpenGL glfw ${GLFW_LIBRARIES})