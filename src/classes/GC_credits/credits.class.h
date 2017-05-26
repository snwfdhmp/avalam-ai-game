// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.hpp)
#ifndef CREDITS_H
	#define CREDITS_H
    
    #include "../Bouton/Bouton.class.h"
    #include "../GraphicComponent/GraphicComponent.class.h"
    #include "SDL2/SDL.h"
   
    //Bouton class definition

    class creditsBouton : public Bouton
    {

        public:
        SDL_Renderer* renderer;

        creditsBouton(SDL_renderer* renderer, const char* pathToImg); //class constructor
        ~creditsBouton();
        void onMouseOver(SDL_Renderer* renderer);
       void Onclick();
        
    };

    #endif
