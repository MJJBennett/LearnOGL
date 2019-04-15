#ifndef LOGL_WINDOW
#define LOGL_WINDOW

#include <optional>
class GLFWwindow;

namespace logl
{

struct Key
{
    using Type = int;
    constexpr static Type Escape = 256;
};

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
    bool keyDown(const Key::Type& key);
    void close();
    void clear();
    void setColour(double r, double g, double b, double a);
    ~Window();
private:
    void startGLFW();
    void stopGLFW();
    bool init_ = false;
    GLFWwindow* window_ = nullptr;
};

}

#endif // LOGL_WINDOW
