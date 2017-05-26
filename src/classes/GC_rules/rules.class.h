// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.hpp)
#ifndef RULES_H
	#define RULES_H
    
    #include "../Bouton/Bouton.class.h"
    #include "../GraphicComponent/GraphicComponent.class.h"
    #include "SDL2/SDL.h"
   
    //Bouton class definition

    class rulesBouton: public Bouton
    {

        public:
        SDL_Renderer* renderer;

        rulesBouton(SDL_renderer* renderer, const char* pathToImg); //class constructor
        ~rulesBouton();
        void Onclick();
        
    };

    #endif
