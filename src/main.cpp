#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "classes/Emplacement/Emplacement.class.h"
#include "classes/Mouvement/Mouvement.class.h"
#include "classes/Player/Player.class.h"
#include "classes/Window/Window.class.h"
#include "config/macros.h"
#include "config/constants.h"
#include "SDL2/SDL.h"
#include "classes/GameInstance/GameInstance.class.h"
#undef main

using namespace std;
void events(Window *window){
	int continuer = 1;
    SDL_Event event;
 
    while (continuer == 1)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            //Si il appuie sur la croix on ferme cc
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

            case SDL_MOUSEBUTTONDOWN : 
            	/*printf("Position en x : %d\n", event.motion.x);
       			printf("Position en y : %d\n", event.motion.y);*/
            if (event.button.button == SDL_BUTTON_LEFT){
       			if((event.motion.x >= 200 && event.motion.x <= 500) && event.motion.y >= 135 && event.motion.y <= 545)
       				printf("Jouer!\n");
       			if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 135 && event.motion.y <= 315)
       				printf("Options\n");
       			if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 330 && event.motion.y <= 435)
       				printf("themes\n");
       			if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 445 && event.motion.y <= 495)
       				printf("Regles\n");
       			if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 505 && event.motion.y <= 550)
       				printf("About\n");
       		}
        }
    }
    SDL_DestroyWindow(window->window);
    SDL_Quit(); 
}

int main(int argc, char const *argv[])
{
	Window* window = new Window("Avalam", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1012, 568, SDL_WINDOW_SHOWN);
	window->setIcon("ressources/img/chess.bmp");
	
	Display* menu = new Display(window);
	GraphicComponent* background = new GraphicComponent(menu->renderer, "ressources/img/Avalam-menu.bmp");
	SDL_Rect position = {0, 0, background->width, background->height};
	SDL_RenderCopy(menu->renderer, background->texture, NULL, &position);
    SDL_RenderPresent(menu->renderer);
    events(window);

	/*while(true) {
		window->update();
	}*/

	return 0;
}