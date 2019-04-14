// Header file include
#include "logl_window.h"

// Glad, for setting things up
#include <glad/glad.h>
// GLFW library header
#include <GLFW/glfw3.h>

// Logging
#include <logl_print.h>

void ResizeWindowCallback(GLFWwindow*, int width, int height)
{
    glViewport(0, 0, width, height);
}

logl::Window::~Window()
{
    if (init_) glfwTerminate();
}

int logl::Window::initialize(int width, int height, std::optional<WindowOpts> opts)
{
    startGLFW();
    if (!opts)
    {
        opts = {3, 3};
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, opts->version_major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, opts->version_minor);
    // Always use core profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // This is used for macOS only - should probably macro it in
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window_ = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
    if (window_ == nullptr)
    {
        print(logl::error(), "Could not create a window with GLFW.");
        stopGLFW();
        return -1; 
    }

    glfwMakeContextCurrent(window_);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        print(logl::error(), "Could not initialize GLAD.");
        return -1;
    }

    glViewport(0, 0, width, height);

    glfwSetWindowSizeCallback(window_, ResizeWindowCallback);
    return 0;
}

bool logl::Window::updateWindow()
{
    if (!init_ || glfwWindowShouldClose(window_)) return false;
    glfwSwapBuffers(window_);
    glfwPollEvents();
    return true;
}

void logl::Window::startGLFW()
{
    if (!init_)
    {
        init_ = true;
        glfwInit();
    }
}

void logl::Window::stopGLFW()
{
    if (init_)
    {
        init_ = false;
        glfwTerminate();
    }
}

