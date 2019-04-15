#include "logl_print.h"
#include "logl_window.h"

int main() 
{
    logl::Window window;
    if (window.initialize(800, 600) != 0) return -1;
    window.setColour(0.2f, 0.3f, 0.3f, 1.0f);
    do
    {
        if (window.keyDown(logl::Key::Escape)) window.close();
        
        // Logic goes here
        
        // Clear the window
        window.clear();
    }
    while (window.updateWindow());
    return 0;    
}

