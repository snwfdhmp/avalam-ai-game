// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.cpp)
   #ifndef PLAY_CPP
    #define PLAY_CPP

    //Bouton class methods implementation

    #include "Play.class.hpp"
    #include "../GraphicComponent/GraphicComponent.class.h"
    #include "../Display/Display.class.h"
    #include "SDL2/SDL.h"
    #include <stdio.h>
    
    //class constructor
    playBouton::playBouton(SDL_Renderer *renderer, char* path, int _x, int _y, int width, int height){
        // object initialization
    surface = SDL_LoadBMP(path);
    if(surface == NULL)
        printf("Bouter jouer non charge\n");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
        if(texture == NULL)
            printf("Texture non cree\n");
    SDL_Rect position =  {_x, _y, width, height}; 
  
        x = _x;
        printf("X du bouton jouer : %d\n", x);
        y = _y; 
        printf("Y du bouton jouer : %d\n", y);
        w = width;
        h = height;
    }
    
    void playBouton::Onclick(){
        printf("Le play a ete clique\n");
    }

    /*DestroyRenderer(this.display);*/
    void playBouton::onMouseOver(){
        GraphicComponent* gc_over = new GraphicComponent(renderer, "ressources/img/mock-jouer-mouseover.bmp");
        SDL_Rect position = {0, 0, gc_over->width, gc_over->height};
        SDL_RenderCopy(renderer, gc_over->texture, NULL, &position);
        SDL_RenderPresent(renderer);
    }
    #endif