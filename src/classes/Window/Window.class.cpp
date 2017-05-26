// Project MPI [duck managed]
// Class Window (src/classes/Window/Window.class.cpp)
#ifndef WINDOW_CLASS_CPP
#define WINDOW_CLASS_CPP

//Window class methods implementation

#include <stdio.h>
#include "../../SDL2/SDL.h"
#include "../Display/Display.class.h"
#include "Window.class.h"

//class constructor
Window::Window(const char* title, int x, int y, int w, int h, Uint32 flags) {
	window = NULL;
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    if(window == NULL)
    	printf("Erreur à la création de la fenêtre : %s\n", SDL_GetError());
}

int Window::show() {
	return SDL_WaitEvent(&event);
}

int Window::update() {
	show();

	if(event.type==SDL_QUIT||event.type==SDL_APP_TERMINATING)
		return -1;

	return 0;
}

void Window::setIcon(const char* pathToIcon) {
	SDL_Surface *icon = SDL_LoadBMP(pathToIcon);
  	SDL_SetWindowIcon(window, icon);
}

void Window::handleEvent(Display* menu){
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
            /*GraphicComponent* target = menu->getTargeted(event.motion.x, event.motion.y);
            if(target == NULL) break;
            target->onClick();*/
          break;

          case SDL_MOUSEMOTION :
            if((event.motion.x >= 200 && event.motion.x <= 500) && event.motion.y >= 135 && event.motion.y <= 545){
              printf("Jouer over!\n");
              mouseOver(menu, "ressources/img/mock-jouer-mouseover.bmp");
            }
            else if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 135 && event.motion.y <= 315){
              printf("Options over\n");
              mouseOver(menu, "ressources/img/mock-jouer-mouseover.bmp");
            }
            else if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 330 && event.motion.y <= 435){
              printf("Window: themes over\n");
              mouseOver(menu, "ressources/img/mock-jouer-mouseover.bmp");
            }
            else if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 445 && event.motion.y <= 495){
              printf("Regles over\n");
              mouseOver(menu, "ressources/img/mock-jouer-mouseover.bmp");
            }
            else if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 505 && event.motion.y <= 550){
              printf("About over\n");
              mouseOver(menu, "ressources/img/mock-jouer-mouseover.bmp");
            }
            break;
        }
    }
    
}

#endif
