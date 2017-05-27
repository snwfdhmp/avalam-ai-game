// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.cpp)
   #ifndef OPTIONS_CPP
    #define OPTIONS_CPP

    //Bouton class methods implementation

    #include "options.class.h"
    #include "../GraphicComponent/GraphicComponent.class.h"
    #include "../Display/Display.class.h"
    #include "SDL2/SDL.h"
    #include <stdio.h>
    
    //class constructor
    optionsBouton::optionsBouton(SDL_Renderer* renderer, const char* pathToImg){
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
    
    void options::onMouseOver(SDL_Renderer* renderer){
        GraphicComponent* gc_over = new GraphicComponent(renderer, "ressources/img/mock-option-mouseover.bmp");
        SDL_Rect position = {0, 0, gc_over->width, gc_over->height};
        SDL_RenderCopy(renderer, gc_over->texture, NULL, &position);
        SDL_RenderPresent(renderer);
    }
    void Onclick(){
        printf("options a a ete clique\n");
    }

#endif