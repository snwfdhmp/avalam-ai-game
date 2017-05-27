// Project MPI [duck managed]
// Class Window (src/classes/Window/Window.class.hpp)
#ifndef WINDOW_CLASS_HPP
#define WINDOW_CLASS_HPP

#include <string>

#include "../../SDL2/SDL.h"
#include "../GraphicComponent/GraphicComponent.class.h"
//#include "../Display/Display.class.h"

//Window class definition
class Window
{
public:
	std::string name;
	SDL_Window* window; //SDL_Window for object
	SDL_Event event; //For event handling
	//Display** DisplayList; //Array of <Display> used in the object


    Window(const char* title, int x, int y, int w, int h, Uint32 flags); //class constructor
    ~Window(); //class destructor
    int show(); //show window (doesn't catch events), returns status
    int update(); //window update function, returns status
    //void handleEvent(Display* display);
    void setIcon(const char* pathToIcon); //set app window icon

    //Display* addDisplay(Display* toAdd); //add Display to List, returns it
};

#endif