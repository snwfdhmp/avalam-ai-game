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

GraphicComponent::GraphicComponent(char* type, SDL_Renderer* renderer, SDL_Surface* set_surface){
	surface = set_surface;
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}

GraphicComponent::GraphicComponent(SDL_Renderer *renderer, char* path, int _x, int _y, int w, int h){
	surface = SDL_LoadBMP(path);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect position =  {x, y, w, h}; //Advice for w and h use bouton->w and bouton->h
   	SDL_RenderCopy(renderer, texture, NULL, &position);
  	SDL_RenderPresent(renderer);

  	x = _x;
  	printf("X du GraphicComponent : %d\n", x);
  	y = _y;
  	printf("Y du GraphicComponent : %d\n", y);
  	width = surface->w;
  	height = surface->h;
}

GraphicComponent::~GraphicComponent(){};

void GraphicComponent::destroyTexture(){
	SDL_DestroyTexture(texture);
}

void GraphicComponent::destroySurface(){
	SDL_FreeSurface(surface);
}

/*void GraphicComponent::onMouseOver(SDL_Renderer* renderer, const char* path){
	 GraphicComponent* gc_over = new GraphicComponent(renderer, path);
     SDL_Rect position = {0, 0, gc_over->width, gc_over->height};
     SDL_RenderCopy(renderer, gc_over->texture, NULL, &position);
     SDL_RenderPresent(renderer);
}*/

/*void isAttachedto(SDL_Display *gc_display){
	this.display = gc_display;
}*/

/*GraphicComponent* createboard(SDL_Renderer *renderer){
	 SDL_Rect cases[TAILLE];
	 SDL_SetRenderDrawColor(renderer, 55, 194, 31, 255); //Background color(green)
     SDL_RenderClear(renderer); //Apply the color

     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
     cases[0].x = cases[0].y = 320;
     for(int i = 0; i < 9; i++)
     	cases[i].w = cases[i].h = 100;

}

GraphicComponent::destroyTexture(SDL_Texture *texture){
	SDL_DestroyTexture(texture);
}

GraphicComponent::destroySurfacr(SDL_Surface *surface){
	SDL_FreeSurface(surface);
}
	
}*/

void GraphicComponent::onClick(){
	printf("A fonction is being active");
}

/*void GraphicComponent::onMouseOver(){
	//printf("GraphicComponent at [%d;%d] has fired the onMouseOver() function.\n", x, y);
}*/

void GraphicComponent::onMouseOut() {
	//printf("GraphicComponent at [%d;%d] has fired the onMouseOut() function.\n", x, y);
}

#endif