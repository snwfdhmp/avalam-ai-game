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
    creditsBouton::creditsBouton(SDL_Renderer* renderer, const char* pathToImg){
        // object initialization
        surface = SDL_LoadBMP(pathToImg);
        if(surface == NULL)
            printf("surface non cree\n");

        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if(texture == NULL)
            printf("texture non cree\n");

        width = surface->w;
        height = surface->h;
    }

    void onMouseOver(SDL_Renderer* renderer, const char* path){
        GraphicComponent* gc_over = new GraphicComponent(renderer, path);
        SDL_Rect position = {0, 0, gc_over->width, gc_over->height};
        SDL_RenderCopy(renderer, gc_over->texture, NULL, &position);
        SDL_RenderPresent(renderer);
    }
    
    void Onclick(){
        printf("Credits a a ete clique\n");
    }
 
    #endif
