#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "classes/Emplacement/Emplacement.class.h"
#include "classes/Mouvement/Mouvement.class.h"
//#include "classes/GC_Play/Play.class.hpp"
#include "classes/Player/Player.class.h"
#include "classes/Window/Window.class.h"
#include "config/macros.h"
#include "config/constants.h"
#include "SDL2/SDL.h"
#include "classes/GameInstance/GameInstance.class.h"
#undef main

using namespace std;

int creategame(Window*, Display*);
void handleEvent(Display*);
void mouvement(SDL_Rect *, Display*);
void onMouseOver(Display *, char*);


void onMouseOver(Display *display, char *path){
    GraphicComponent* gc_over = new GraphicComponent(display->renderer, path);
    SDL_Rect position = {0, 0, gc_over->width, gc_over->height};
    SDL_RenderCopy(display->renderer, gc_over->texture, NULL, &position);
    SDL_RenderPresent(display->renderer);
}

int creategame(Window *window, Display* game){
	Uint8 r,g,b,a;
	int nbcases = 48, select = 0, selectedCase;
  SDL_SetWindowTitle(window->window, "Board");
	
	int rgb[48] = {0}, firstPiece;
	SDL_Rect cases[48];
	
  SDL_SetRenderDrawColor(game->renderer, 0, 87, 122, 255);//Fond bleu
  SDL_RenderClear(game->renderer);

    //Coordonées de chaques pieces
    cases[20].x = cases[28].x = 150;
    cases[2].x = cases[6].x = cases[12].x = cases[21].x  = cases[29].x = 230;
    cases[0].x = cases[3].x = cases[7].x = cases[13].x = cases[22].x = cases[30].x = cases[36].x = 310;
    cases[1].x = cases[4].x = cases[8].x = cases[14].x = cases[23].x = cases[31].x = cases[37].x = 390;
    cases[5].x = cases[9].x = cases[15].x = cases[32].x = cases[38].x = cases[42].x = 470;
    cases[10].x = cases[16].x = cases[24].x = cases[33].x = cases[39].x = cases[43].x = cases[46].x = 550;
    cases[11].x = cases[17].x = cases[25].x = cases[34].x = cases[40].x = cases[44].x = cases[47].x = 630;
    cases[18].x = cases[26].x = cases[35].x = cases[41].x = cases[45].x = 710;
    cases[19].x = cases[27].x = 790;

    cases[0].y = cases[1].y = 100;
    cases[2].y = cases[3].y = cases[4].y = cases[5].y = 180;
    cases[7].y = cases[6].y = cases[8].y = cases[9].y = cases[10].y = cases[11].y = 260;
    cases[12].y = cases[13].y = cases[14].y = cases[15].y = cases[16].y = cases[17].y = cases[18].y = cases[19].y = 340;
    cases[20].y = cases[21].y = cases[22].y = cases[23].y = cases[24].y = cases[25].y = cases[26].y = cases[27].y = 420;
    cases[28].y = cases[29].y = cases[30].y = cases[31].y = cases[32].y = cases[33].y = cases[34].y = cases[35].y = 500;
    cases[36].y = cases[37].y = cases[38].y = cases[39].y = cases[40].y = cases[41].y = 580;
    cases[42].y = cases[43].y = cases[44].y = cases[45].y = 660;
    cases[46].y = cases[47].y = 740;

    for(int i = 0; i < 48; i++){
    	cases[i].w = cases[i].h = 50; //taille d'une case : 50 x 50 pixels

    	if(cases[i].y == 100 || cases[i].y == 260 || cases[i].y == 420 || cases[i].y == 580 || cases[i].y == 740){
    		SDL_SetRenderDrawColor(game->renderer, 206, 170, 62, 255); //Couleur jaune
    		SDL_RenderFillRect(game->renderer, &cases[i]);
    	}

    	else{
    		SDL_SetRenderDrawColor(game->renderer, 121, 17, 100, 255); //Couleur rouge
    		SDL_RenderFillRect(game->renderer, &cases[i]);
    	}
      SDL_RenderPresent(game->renderer);
    }
   
   for(int i = 0; i < 48; i++){
        if(cases[i].y == 180 || cases[i].y == 340 || cases[i].y == 500 || cases[i].y == 660)
    		rgb[i] = 121;
    	else if(cases[i].y == 100 || cases[i].y == 260 || cases[i].y == 420 || cases[i].y == 580 || cases[i].y == 740)
    		rgb[i] = 206;
    }
    
    while(true){
    SDL_Event event;
		SDL_WaitEvent(&event);

		if(event.type == SDL_MOUSEBUTTONUP){
			for(int i = 0; i < 48; i++){
				if(event.button.x >= cases[i].x && event.button.x <= (cases[i].x+cases[i].w) && event.button.y >= cases[i].y && event.button.y <= (cases[i].y+cases[i].h)){
					if(select == 0){
            printf("Select : %d\n", select);
						select = 1;
						selectedCase = i;
            SDL_SetRenderDrawColor(game->renderer, 33, 204, 9, 255);
            SDL_RenderFillRect(game->renderer, &cases[i]);
						firstPiece = rgb[i];
					}

					else if(select == 1){
            printf("Select : %d\n", select);
						printf("Derniere case selectionee est %d et va sur la case %d\n\n", selectedCase, i);
						SDL_GetRenderDrawColor(game->renderer, &r, &g, &b, &a);
						
						if(firstPiece == 206){
              printf("jaune\n");
              SDL_SetRenderDrawColor(game->renderer, 0, 87, 122, 255); //Couleur bleue
    					SDL_RenderFillRect(game->renderer, &cases[selectedCase]);
							SDL_SetRenderDrawColor(game->renderer, 206, 170, 62, 255); //Couleur jaune
    					SDL_RenderFillRect(game->renderer, &cases[i]);
              rgb[i] = 206;
    					cases[selectedCase].x = 0;
							cases[selectedCase].y = 0;
    				}
    				else{
              printf("rouge\n");
    					SDL_SetRenderDrawColor(game->renderer, 0, 87, 122, 255); //Couleur bleue
    					SDL_RenderFillRect(game->renderer, &cases[selectedCase]);
    					SDL_SetRenderDrawColor(game->renderer, 121, 17, 100, 255); //Couleur rouge
    					SDL_RenderFillRect(game->renderer, &cases[i]);
              rgb[i] = 121;
    					cases[selectedCase].x = 0;
							cases[selectedCase].y = 0;
    					}
              select = 0;
					}
				}	
			}
		}
		SDL_RenderPresent(game->renderer);
    }
}

void handleEvent(Display* menu){
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
              if((event.button.x >= 200 && event.button.x <= 500) && (event.button.y >= 135 && event.button.y <= 545)){
              	printf("GAAAME\n");
              }
          break;

          /*case SDL_MOUSEMOTION :
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
            break;*/
        }
    }
}


int main(int argc, char const *argv[])
{

	Window* window = new Window("Avalam by Joly and Monga", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1012, 800, SDL_WINDOW_SHOWN); //Window init
	window->setIcon("ressources/img/chess.bmp"); //Icon init
	
	Display* menu = new Display(window);
  	//menu->createmenu();
  	creategame(window, menu);
  	handleEvent(menu);
  	
	//window->handleEvent(menu);

    //todo : transform to window->handleEvent(menu, background)
    //handleEvent(window, menu, background);
  	SDL_DestroyWindow(window->window);
  	SDL_Quit(); 
	


	return 0;
}