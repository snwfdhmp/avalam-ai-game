#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "Display.class.h"
#include "../Emplacement/Emplacement.class.h"
#include "../GraphicComponent/GraphicComponent.class.h"
#include "../../SDL2/SDL.h"
#include "../Window/Window.class.h"

// include global constants
#include "../../config/constants.h"

Display::Display(int set_x, int set_y, int set_width, int set_height, Window* window) {
	components = (GraphicComponent**) malloc(sizeof(GraphicComponent*));
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
	components = (GraphicComponent**) malloc(sizeof(GraphicComponent*));
	renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(renderer == NULL)
		printf("Erreur : Renderer non cree\n");
};

Display::~Display() {};

Display* destroyRenderer(SDL_Renderer *renderer){
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
	SDL_Rect pion;
	x = 120; 
	SDL_SetRenderDrawColor(renderer, 0, 87, 122, 255);//Fond bleu
	SDL_RenderClear(renderer);

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
				}
				else {
				SDL_SetRenderDrawColor(renderer, 206, 170, 62, 255); //Couleur jaune
				SDL_RenderFillRect(renderer, &pion);
			}
			}
			else {
				if(grille[i][j].selected == 1){
					SDL_SetRenderDrawColor(renderer, 33, 204, 9, 255);
					SDL_RenderFillRect(renderer, &pion);
				}
				else {
				SDL_SetRenderDrawColor(renderer, 121, 17, 100, 255); //Couleur rouge
				SDL_RenderFillRect(renderer, &pion);
			}
			}
			y+=GAP;
		}
		x+=GAP;
	}
	SDL_RenderPresent(renderer);
}

Display::getSelect(Emplacement grille[TAILLE][TAILLE]){
	int xClick, yClick;
	SDL_Event click;
	printGrille(grille);

	while(true) {
		SDL_WaitEvent(&click);

		if(click.type == SDL_MOUSEBUTTONUP){
			if(click.button.x-120 < 0 && click.button.y-80 < 0)
				return NULL;
			xClick = (click.button.x-120)/(GAP);
			yClick = (click.button.y-80)/(GAP);
			printf("X : %d Y: %d\n", xClick, yClick);
			if(xClick >= TAILLE || yClick >= TAILLE)
				return NULL;

			if((click.button.x-120)%(GAP)-(PAWN_SIZE) > 0 || (click.button.y-80)%(GAP)-(PAWN_SIZE) > 0) {
				printf("Click incorrect\n");
				return NULL;
			}
			printf("Click correct\n");
			std::vector<int>(2) rep;
			rep[0]=xClick;
			rep[1]=yClick;
			grille[xClick][yClick].selected = 1;
			return rep;
		}
		return NULL;
	}
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

/*void Display::handleEvent(Display* menu){
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            //Si il appuie sur la croix on ferme
            case SDL_QUIT:
                printf("Quitter\n");
                continuer = 0;
                break;
            
            case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
              //SI on appuie sur echap ou q on save et on quitte..
                case SDLK_ESCAPE: 
                    //save();
                    printf("Quitter\n");
                    continuer = 0;
                    break;
                case SDLK_q : 
                  //save();
                  printf("Quitter\n");
                  continuer = 0;
                  break;
            }
            break;

            case SDL_MOUSEBUTTONUP : 
              printf("Position en x : %d\n", event.motion.x);
              printf("Position en y : %d\n", event.motion.y);
               if((event.button.x >= 200 && event.button.x <= 500) && event.button.y >= 135 && event.button.y <= 545){
              	printf("C'est parti pour jouer!\n");
              }
          break;

          case SDL_MOUSEMOTION :
            if((event.motion.x >= 200 && event.motion.x <= 500) && event.motion.y >= 135 && event.motion.y <= 545){
              printf("Jouer over!\n");
              onMouseOver(menu, "ressources/img/mock-jouer-mouseover.bmp");
            }
            else if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 135 && event.motion.y <= 315){
              printf("Options over\n");
              onMouseOver(menu, "ressources/img/mock-jouer-mouseover.bmp");
            }
            else if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 330 && event.motion.y <= 435){
              printf("Window: themes over\n");
              onMouseOver(menu, "ressources/img/mock-jouer-mouseover.bmp");
            }
            else if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 445 && event.motion.y <= 495){
              printf("Regles over\n");
              onMouseOver(menu, "ressources/img/mock-jouer-mouseover.bmp");
            }
            else if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 505 && event.motion.y <= 550){
              printf("About over\n");
              onMouseOver(menu, "ressources/img/mock-jouer-mouseover.bmp");
            }
            break;
        }
    }
};*/

	GraphicComponent* Display::addComponent(GraphicComponent* componentToAdd) {
		components = (GraphicComponent**) realloc(components, sizeof(GraphicComponent*) * size + 1);
		components[size] = componentToAdd;
	//printf("Component [%d;%d] has been added to display [%d;%d] (%d:%d) [size : %d]\n", components[size]->x, components[size]->y, x, y, width, height, size);
	return components[size++]; //size is incremented after he gets injected as index of array (post inc)
};

#endif