// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.cpp)
   #ifndef THEMES_CPP
    #define THEMES_CPP

    //Bouton class methods implementation

    #include "themes.class.h"
    #include "../GraphicComponent/GraphicComponent.class.h"
    #include "../Display/Display.class.h"
    #include "SDL2/SDL.h"
    #include <stdio.h>
	
    //class constructor
    themesBouton::themesBouton(SDL_Renderer *renderer, char* path, int _x, int _y, int width, int heigth){
        // object initialization
      
     Bouton *themesBouton = new Bouton(renderer, path, x, y, w, h);
       
       x = _x;
       y = _y;
       w = width;
       h = height;
    }
    
    themesBouton::~themesBouton(){};

    void themesBouton::Onclick(){
        printf("Rules a a ete clique\n");
    }

    #endif