#ifndef GRAPHICCOMPONENT_H
#define GRAPHICCOMPONENT_H

#include "SDL2/SDL.h"
#include <string>

class GraphicComponent
{
public:
	
	SDL_Texture *texture;
	SDL_Surface *surface;
	int x, y;
	int height, width;

	
	GraphicComponent(int set_x, int set_y, int set_width, int set_height);

	~GraphicComponent();
	
	void initTexture(SDL_Renderer *renderer, SDL_Surface *surface);
	GraphicComponent* destroyTexture(SDL_Texture *texture);
	//GraphicComponent* initSurface(std::string path);
	void onClick(); // click handler function

	void onMouseOver(); // mouseover handler function

	void onMouseOut(); //mouseout handler function

		

};
#endif