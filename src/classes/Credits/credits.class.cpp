// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.cpp)
   #ifndef CREDITS_CPP
    #define CREDITS_CPP

    //Bouton class methods implementation

    #include "credits.class.h"
    #include "../GraphicComponent/GraphicComponent.class.h"
    #include "../Display/Display.class.h"
    #include "SDL2/SDL.h"
    #include <stdio.h>
	
    //class constructor
    creditsBouton::creditsBouton(SDL_Renderer *renderer, char* path, int _x, int _y, int width, int height){
       
       // object initialization
       Bouton *creditsBouton = new Bouton(renderer, path, x, y, w, h);
       
       x = _x;
       y = _y;
       w = width;
       h = height;
    }

    void creditsBouton::onMouseOver(SDL_Renderer* renderer){
        GraphicComponent* gc_over = new GraphicComponent(renderer, "ressources/img/mock-jouer-mouseover.bmp");
        SDL_Rect position = {0, 0, gc_over->width, gc_over->height};
        SDL_RenderCopy(renderer, gc_over->texture, NULL, &position);
        SDL_RenderPresent(renderer);
    }
    
    void creditsBouton::Onclick(){
        printf("Credits a a ete clique\n");
    }
 
    #endif
