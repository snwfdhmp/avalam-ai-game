// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.cpp)
   #ifndef RULES_CPP
    #define RULES_CPP

    //Bouton class methods implementation

    #include "rules.class.h"
    #include "../GraphicComponent/GraphicComponent.class.h"
    #include "../Display/Display.class.h"
    #include "SDL2/SDL.h"
    #include <stdio.h>
	
    //class constructor
    rulesBouton::rulesBouton(SDL_Renderer* renderer, const char* pathToImg){
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
    
    void Onclick(){
        printf("Rules a a ete clique\n");
    }

     #endif