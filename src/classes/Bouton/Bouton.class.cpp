// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.cpp)
#ifndef BOUTON_CLASS_CPP
#define BOUTON_CLASS_CPP

    //Bouton class methods implementation

  #include "Bouton.class.h"
	#include "../GraphicComponent/GraphicComponent.class.h"
  #include "../Display/Display.class.h"
	#include <stdio.h>
	

    //class constructor
    Bouton::Bouton(SDL_Renderer *renderer, char* path, int x, int y, int w, int h) {
        // object initialization
    GraphicComponent* bouton = new GraphicComponent(renderer, path);
   	SDL_Rect position =  {x, y, w, h}; //Advice for w and h use bouton->w and bouton->h
   	SDL_RenderCopy(renderer, bouton->texture, NULL, &position);
  	SDL_RenderPresent(renderer);
    }
    
    void Onclick(){
        printf("A bouton is clicked\n");
   }

#endif
