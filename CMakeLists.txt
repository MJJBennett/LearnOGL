cmake_minimum_required(VERSION 3.2)
set (CMAKE_CXX_STANDARD 17)
project(LearnOpenGL)

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/3rd/glad/include")
include_directories("${PROJECT_SOURCE_DIR}/include")

include_directories("/usr/local/include")

add_executable(LearnOpenGL
    3rd/glad/glad.c
    include/logl_print.h
    src/logl_fio.cpp include/logl_fio.h
    src/logl_window.cpp include/logl_window.h
    src/main.cpp
)

find_library(GLFW_LIBRARY glfw HINTS /usr/local/lib)
target_link_libraries(LearnOpenGL PUBLIC ${GLFW_LIBRARY})
