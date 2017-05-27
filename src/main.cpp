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

void onMouseOver(Display *display, char *path){
    GraphicComponent* gc_over = new GraphicComponent(display->renderer, path);
    SDL_Rect position = {0, 0, gc_over->width, gc_over->height};
    SDL_RenderCopy(display->renderer, gc_over->texture, NULL, &position);
    SDL_RenderPresent(display->renderer);
}

/*void handleEvent(Display* menu){
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
              if((event.motion.x >= 200 && event.motion.x <= 500) && event.motion.y >= 135 && event.motion.y <= 545){
              	menu
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
}*/


int main(int argc, char const *argv[])
{

	Window* window = new Window("Avalam by Joly and Monga", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1012, 568, SDL_WINDOW_SHOWN); //Window init
	window->setIcon("ressources/img/chess.bmp"); //Icon init
	
	Display* menu = new Display(window);
  	menu->createmenu();
  	menu->handleEvent(menu);
	//menu->createmenu();
	//window->handleEvent(menu);

    //todo : transform to window->handleEvent(menu, background)
    //handleEvent(window, menu, background);
  	SDL_DestroyWindow(window->window);
  	SDL_Quit(); 
	
  while(true) {
		window->update();
	}

	return 0;
}