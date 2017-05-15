// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.cpp)
#ifndef BOUTON_CLASS_CPP
#define BOUTON_CLASS_CPP

    //Bouton class methods implementation

    #include "Bouton.class.h"
	#include "../GraphicComponent/GraphicComponent.class.h"
	#include <stdio.h>
	

    //class constructor
    Bouton::Bouton(Display* display, char* path, int x, int y, int w,int h) {
        // object initialization
    GraphicComponent* bouton = new GraphicComponent(display->renderer, path);
   	SDL_Rect position =  {x, y, w, h}; //Advice for w and h use bouton->w and bouton->h
   	SDL_RenderCopy(display->renderer, bouton->texture, NULL, &position);
  	SDL_RenderPresent(display->renderer);
    }
    
    void Onclick(){
        printf("A bouton is clicked\n");
   }

#endif
