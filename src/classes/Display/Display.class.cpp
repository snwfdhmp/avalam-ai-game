#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>

#include "Display.class.h"
#include "../Emplacement/Emplacement.class.h"
#include "../GraphicComponent/GraphicComponent.class.h"
#include "../../SDL2/SDL.h"
#include "../Window/Window.class.h"

// include global constants
#include "../../config/constants.h"

Display::Display(int set_x, int set_y, int set_width, int set_height, Window* window) {
	size = 0;
	x = set_x;
	y = set_y;
	width = set_width;
	height = set_height;
	renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(renderer == NULL)
		printf("Erreur : Renderer non cree\n");
};

Display::Display(Window* window) {
	renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(renderer == NULL)
		printf("Erreur : Renderer non cree\n");
};

Display::~Display() {};

void Display::destroyRenderer(){
	SDL_DestroyRenderer(renderer);
}

/*int Display::printGridToConsole(Emplacement grille[TAILLE][TAILLE]) {
	printf("=========================\n");
	printf("======== PLATEAU ========\n");
	printf("=========================\n");
	int x,y;
	int score[2] = {0, 0};
	printf("=    ==0== ==1== ==2== ==3== ==4== ==5== ==6== ==7== ==8==  =\n");
	for (y = 0;y < TAILLE; ++y)
	{
		printf("= %d: ", y);
		for (x = 0; x < TAILLE; ++x)
		{
			if (grille[x][y].valeur != 2) {
				(grille[x][y].valeur)?printf("\033[31m"):printf("\033[32m");
				printf("(%d:%d) ", grille[x][y].valeur, grille[x][y].hauteur);
				printf("\033[39m");
				score[grille[x][y].valeur]+=grille[x][y].hauteur;
			}
			else
				printf("      ");
		}
		printf(" =\n");
	}
	printf("==== 0 : %d | 1 : %d ====\n", score[0], score[1]);
	return 0;
}*/

/*Display* destroyRenderer(SDL_Renderer *renderer){
	SDL_DestroyRenderer(renderer);
	return NULL;
}*/


void Display::printGrille(Emplacement grille[TAILLE][TAILLE]){
	
	SDL_Rect pion, heightpositon;
	x = 120; 
	SDL_SetRenderDrawColor(renderer, 0, 87, 122, 255);//Fond bleu
	SDL_RenderClear(renderer);
	char imageName[10];
	char caseHauteur[10];

	for(int i = 0; i < TAILLE; i++){
		y = 80;
		SDL_Rect pion;
		for(int j = 0; j < TAILLE; j++) {
			if(grille[i][j].valeur == 2) {
				y+=GAP;
				continue;
			}
			pion.x = x;
			pion.y = y;
			pion.w = pion.h = PAWN_SIZE;
			if(grille[i][j].valeur == 1) {
				if(grille[i][j].selected == 1){
					SDL_SetRenderDrawColor(renderer, 33, 204, 9, 255);
					SDL_RenderFillRect(renderer, &pion);
					sprintf(imageName, "ressources/img/gheight%d.bmp", grille[i][j].hauteur);

					SDL_Surface* caseheight = SDL_LoadBMP(imageName);
					SDL_Texture* caseTexture = SDL_CreateTextureFromSurface(renderer, caseheight);
					heightpositon = {x, y, PAWN_SIZE, PAWN_SIZE};
					SDL_RenderCopy(renderer, caseTexture, NULL, &heightpositon);
				}
				else {
					SDL_SetRenderDrawColor(renderer, 206, 170, 62, 255); //Couleur jaune
					SDL_RenderFillRect(renderer, &pion);
					sprintf(imageName, "ressources/img/yheight%d.bmp", grille[i][j].hauteur);

					SDL_Surface* caseheight = SDL_LoadBMP(imageName);
					SDL_Texture* caseTexture = SDL_CreateTextureFromSurface(renderer, caseheight);
					heightpositon = {x, y, PAWN_SIZE, PAWN_SIZE};
					SDL_RenderCopy(renderer, caseTexture, NULL, &heightpositon);
				}
			}
			else {
				if(grille[i][j].selected == 1){
					SDL_SetRenderDrawColor(renderer, 33, 204, 9, 255);
					SDL_RenderFillRect(renderer, &pion);

					sprintf(imageName, "ressources/img/gheight%d.bmp", grille[i][j].hauteur);
					SDL_Surface* caseheight = SDL_LoadBMP(imageName);
					SDL_Texture* caseTexture = SDL_CreateTextureFromSurface(renderer, caseheight);
					heightpositon = {x, y, PAWN_SIZE, PAWN_SIZE};
					SDL_RenderCopy(renderer, caseTexture, NULL, &heightpositon);
				}
				else {
					SDL_SetRenderDrawColor(renderer, 121, 17, 100, 255); //Couleur rouge
					SDL_RenderFillRect(renderer, &pion);
					sprintf(imageName, "ressources/img/rheight%d.bmp", grille[i][j].hauteur);
					SDL_Surface* caseheight = SDL_LoadBMP(imageName);
					if(caseheight == NULL)
						printf("%s\n", imageName);
					SDL_Texture* caseTexture = SDL_CreateTextureFromSurface(renderer, caseheight);
					heightpositon = {x, y, PAWN_SIZE, PAWN_SIZE};
					SDL_RenderCopy(renderer, caseTexture, NULL, &heightpositon);
				}
			}
			y+=GAP;
		}
		x+=GAP;
	}
	SDL_RenderPresent(renderer);
}

std::vector<int> Display::getSelect(Emplacement grille[TAILLE][TAILLE]){
	
	int xClick, yClick;
	SDL_Event click;
	std::vector<int> rep;
	
	SDL_WaitEvent(&click);
	
	if(click.type == SDL_MOUSEBUTTONUP){
		if(click.button.x-120 < 0 && click.button.y-80 < 0){
			printf("Click en dehors de l'ecran %d\n", rep[0]);
			return rep;
		}

		xClick = (click.button.x- 120)/(GAP);
		yClick = (click.button.y-80)/(GAP);
		printf("X : %d Y: %d\n", xClick, yClick);

		if(xClick >= TAILLE || yClick >= TAILLE)
			return rep;

		if((click.button.x- 120)%(GAP)-(PAWN_SIZE) > 0 || (click.button.y-80)%(GAP)-(PAWN_SIZE) > 0){
			printf("Click incorrect\n");
			return rep;
		}

		if(grille[xClick][yClick].valeur == 2)
			return rep;

		printf("Click correct\n");

		rep.push_back(xClick);
		rep.push_back(yClick);
		for(int i = 0; i < TAILLE; i++){
			for(int j = 0; j < TAILLE; j++){
				grille[i][j].selected = 0;
			}
		}
		if(click.button.button == SDL_BUTTON_LEFT)
			grille[xClick][yClick].selected = 1;

		if(click.button.button == SDL_BUTTON_RIGHT)
			grille[xClick][yClick].selected = 0;

		printf("rep[0] : %d rep[1] : %d\n", rep[0], rep[1]);
		printGrille(grille);

		return rep;
	}
	return rep;
}

void Display::createmenu(){

	GraphicComponent* background = new GraphicComponent(renderer, "ressources/img/Avalam-menu.bmp"); //Init of surface and texture
	this->addComponent(background);
	SDL_Rect position = {0, 0, background->width, background->height};
	SDL_RenderCopy(renderer, background->texture, NULL, &position);
	SDL_RenderPresent(renderer);
}

Display* Display::initWindow() { //TODO merge to initRenderer();
	bool error = false;
	//initRenderer(); 
		/*
			 SDL initialisation de la fenêtre

			 Mettre error = true s'il y a eu une erreur
			 				(qui empeche de continuer)

		*/

	if(error)
		return NULL;
	return this;
};

GraphicComponent* Display::getTargeted(int mouse_x, int mouse_y) {
	if(mouse_x < x || mouse_x > x+width || mouse_y < y || mouse_y > y+height)
		return NULL;
	else
		for (int i = 0; i < (sizeof(components)/sizeof(components[0])); ++i){
			if(mouse_x < components[i]->x || mouse_x > components[i]->x+components[i]->width || mouse_y < components[i]->y || mouse_y > components[i]->y+components[i]->height)
				continue;
			else
				return components[i];
		}
		return NULL;
	}

	int Display::update() {
	//Move to Window class
		SDL_Event event;
		if(event.type == SDL_MOUSEBUTTONUP){
			GraphicComponent* target = getTargeted(event.button.x, event.button.y);
			if(target == NULL)
				return -1;
			else 
				target->onClick();
		}

		if(updateWindow() == NULL)
			return -1;

		return 0;
	}

	Display* Display::updateWindow() {
		bool error = false;
		// SDL clear la fenetre

		for (int i = 0; i < size; ++i)
		{
			// Ajouter le components[i] à la fenetre
			// error = true si erreur
		}

		if(error)
			return NULL;
		return this;
	};

	GraphicComponent* Display::addComponent(GraphicComponent* componentToAdd) {
		components.push_back(componentToAdd);
		//printf("Component [%d;%d] has been added to display [%d;%d] (%d:%d) [size : %d]\n", components[size]->x, components[size]->y, x, y, width, height, size);
	return components[components.size()];
};
#endif