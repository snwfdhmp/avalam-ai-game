#ifndef GRAPHICCOMPONENT_H
#define GRAPHICCOMPONENT_H

#include "SDL2/SDL.h"
#include <string>

class GraphicComponent
{
public:
	
	SDL_Texture *texture;
	SDL_Surface *surface;
	int x, y, width, height;
	
	GraphicComponent(SDL_Renderer* renderer, const char* pathToImg);
	GraphicComponent(SDL_Renderer* renderer, SDL_Surface* set_surface);

	~GraphicComponent();
	
	//void initTexture(SDL_Renderer *renderer, SDL_Surface *surface);
	void destroyTexture(SDL_Texture *texture);
	void destroySurface(SDL_Surface *surface);
	//void initSurface(std::string path);
	//GraphicComponent::destroyTexture(SDL_Texture *texture);
	//GraphicComponent::destroySurfacr(SDL_Surface *surface);
	void onClick(); // click handler function

	void onMouseOver(); // mouseover handler function

	void onMouseOut(); //mouseout handler function

		

};
#endif