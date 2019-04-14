#include "logl_print.h"
#include "logl_window.h"

int main() 
{
    logl::Window window;
    if (window.initialize(800, 600) != 0) return -1;
    while (window.updateWindow());
    return 0;    
}

