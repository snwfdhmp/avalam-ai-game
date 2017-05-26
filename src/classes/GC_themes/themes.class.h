// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.hpp)
#ifndef THEMES_H
	#define THEMES_H
    
    #include "../Bouton/Bouton.class.h"
    #include "../GraphicComponent/GraphicComponent.class.h"
    #include "SDL2/SDL.h"
   
    //Bouton class definition

    class themesBouton: public Bouton
    {
        public:
        SDL_Renderer* renderer;

        themesBouton(SDL_renderer* renderer, const char* pathToImg); //class constructor
        ~themesBouton();
        void Onclick();
    };

    #endif
