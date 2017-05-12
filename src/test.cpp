#include "SDL2/SDL.h"
#include <stdio.h>
#undef main

class GCWindow
{
public:
	int w, h, x, y;
	char* title;

	GCWindow(const char* title, int w, int h){
		SDL_Window *window = NULL;
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
	    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
	    SDL_Renderer *render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
   		SDL_RenderPresent(render);
   		SDL_Delay(3000);
    }
};

int main(int argc, char const *argv[])
{
	GCWindow window("TEST", 800, 800);
	return 0;
}