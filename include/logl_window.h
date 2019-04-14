#ifndef LOGL_WINDOW
#define LOGL_WINDOW

#include <optional>
class GLFWwindow;

namespace logl
{

struct WindowOpts
{
    int version_major;
    int version_minor;
};

// This is a simple GLFW wrapper
class Window 
{
public:
    int initialize(int width, int height, std::optional<WindowOpts> opts = {}); 
    bool updateWindow();
    ~Window();
private:
    void startGLFW();
    void stopGLFW();
    bool init_ = false;
    GLFWwindow* window_ = nullptr;
};

}

#endif // LOGL_WINDOW
