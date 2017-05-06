// Project MPI [duck managed]
// Class Window (src/classes/Window/Window.class.hpp)
#ifndef WINDOW_CLASS_HPP
#define WINDOW_CLASS_HPP

#include "../../SDL2/SDL.h"

//Window class definition

class Window
{
public:
	SDL_Window* window;
	SDL_Event event;

    Window(const char* title, int x, int y, int w, int h, Uint32 flags); //class constructor
    ~Window();
    int show(); //show window (doesn't catch events)
    
};

#endif