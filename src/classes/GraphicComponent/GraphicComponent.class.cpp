#ifndef GRAPHICCOMPONENT_CPP
#define GRAPHICCOMPONENT_CPP

#include <stdio.h>
#include "SDL2/SDL.h"
#include <string>
#include "GraphicComponent.class.h"
#include "../Emplacement/Emplacement.class.h"

GraphicComponent::GraphicComponent(int set_x, int set_y, int set_width, int set_height) {
	x = set_x;
	y = set_y;
	width = set_width;
	height = set_height;
}

GraphicComponent::~GraphicComponent(){};

void GraphicComponent::initTexture(SDL_Renderer *renderer, SDL_Surface *surface){
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
}

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
		printf("GraphicComponent at [%d;%d] has fired the onClick() function.\n", x, y);
}

void GraphicComponent::onMouseOver(){
	printf("GraphicComponent at [%d;%d] has fired the onMouseOver() function.\n", x, y);
}

void GraphicComponent::onMouseOut() {
	printf("GraphicComponent at [%d;%d] has fired the onMouseOut() function.\n", x, y);
}

#endif