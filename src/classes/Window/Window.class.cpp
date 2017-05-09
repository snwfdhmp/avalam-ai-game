// Project MPI [duck managed]
// Class Window (src/classes/Window/Window.class.cpp)
#ifndef WINDOW_CLASS_CPP
#define WINDOW_CLASS_CPP

//Window class methods implementation

#include <stdio.h>
#include "../../SDL2/SDL.h"
#include "Window.class.h"

//class constructor
Window::Window(const char* title, int x, int y, int w, int h, Uint32 flags) {
	window = NULL;
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    if(window == NULL)
    	printf("Erreur à la création de la fenêtre : %s\n", SDL_GetError());
}

int Window::show() {
	return SDL_WaitEvent(&event);
}

int Window::update() {
	show();

	if(event.type==SDL_QUIT||event.type==SDL_APP_TERMINATING)
		return -1;

	return 0;
}

void Window::setIcon(const char* pathToIcon) {
	SDL_Surface *icon = SDL_LoadBMP(pathToIcon);
  	SDL_SetWindowIcon(window, icon);
}

#endif
