#ifndef GRAPHICCOMPONENT_H
#define GRAPHICCOMPONENT_H

#include "SDL2/SDL.h"
//#include "../Display/Display.class.h"
#include <string>

class GraphicComponent
{
public:
	
	SDL_Texture *texture;
	SDL_Surface *surface;
	//Display *display;
	int x, y, width, height;
	char* type;


	GraphicComponent(SDL_Renderer* renderer, const char* pathToImg);
	GraphicComponent(SDL_Renderer* renderer, SDL_Surface* set_surface);
	GraphicComponent(SDL_Renderer *renderer, SDL_Surface, int x, int y, int w, int h);
	GraphicComponent(SDL_Renderer *renderer, char* path, int x, int y, int w, int h);
	GraphicComponent(char* type, SDL_Renderer* renderer, SDL_Surface* set_surface);
	//GraphicComponent(Display* display, char* path, int x, int y, int w, int h);

	~GraphicComponent();
	
	//void initTexture(SDL_Renderer *renderer, SDL_Surface *surface);
	void destroyTexture(SDL_Texture *texture);
	void destroySurface(SDL_Surface *surface);
	//void initSurface(std::string path);
	//GraphicComponent::destroyTexture(SDL_Texture *texture);
	//GraphicComponent::destroySurfacr(SDL_Surface *surface);
	void onClick(); // click handler function

	//void onMouseOver(SDL_Renderer* renderer, const char* path); // mouseover handler function

	void onMouseOut(); //mouseout handler function

	//void isAttachedto(SDL_Display *gc_display);
	
};
#endif