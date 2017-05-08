#ifndef GRAPHICCOMPONENT_CPP
#define GRAPHICCOMPONENT_CPP

#include <stdio.h>
#include "SDL2/SDL.h"
#include <string>
#include "GraphicComponent.class.h"
#include "../Emplacement/Emplacement.class.h"

GraphicComponent::GraphicComponent(SDL_Renderer* renderer, const char* pathToImg) {
	surface = SDL_LoadBMP(pathToImg);
	if(surface == NULL)
		printf("surface non cree\n");

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if(texture == NULL)
		printf("texture non cree\n");

	width = surface->w;
	height = surface->h;
}

GraphicComponent::GraphicComponent(SDL_Renderer* renderer, SDL_Surface* set_surface) {
	surface = set_surface;
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}

GraphicComponent::~GraphicComponent(){};

GraphicComponent* destroyTexture(SDL_Texture *texture){
	SDL_DestroyTexture(texture);
	return NULL;
}

/*GraphicComponent* createboard(SDL_Renderer *renderer){
	 SDL_Rect cases[TAILLE];
	 SDL_SetRenderDrawColor(renderer, 55, 194, 31, 255); //Background color(green)
     SDL_RenderClear(renderer); //Apply the color

     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
     cases[0].x = cases[0].y = 320;
     for(int i = 0; i < 9; i++)
     	cases[i].w = cases[i].h = 100;

}

GraphicComponent* createmenu(SDL_window *window){
	
}*/

void GraphicComponent::onClick(){
	//printf("GraphicComponent at [%d;%d] has fired the onClick() function.\n", x, y);
}

void GraphicComponent::onMouseOver(){
	//printf("GraphicComponent at [%d;%d] has fired the onMouseOver() function.\n", x, y);
}

void GraphicComponent::onMouseOut() {
	//printf("GraphicComponent at [%d;%d] has fired the onMouseOut() function.\n", x, y);
}

#endif