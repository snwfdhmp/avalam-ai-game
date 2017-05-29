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
    rulesBouton::rulesBouton(SDL_Renderer *renderer, char* path, int _x, int _y, int width, int heigth){
        // object initialization
      
     Bouton *rulesBouton = new Bouton(renderer, path, x, y, w, h);
       
       x = _x;
       y = _y;
       w = width;
       h = height;
    }
    
    rulesBouton::~rulesBouton(){};

    void rulesBouton::Onclick(){
        printf("Rules a a ete clique\n");
    }

     #endif