// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.hpp)
#ifndef PLAY_HPP
	#define PLAY_HPP
    
    #include "../Bouton/Bouton.class.h"
    #include "../GraphicComponent/GraphicComponent.class.h"
    #include "SDL2/SDL.h"
   
    //Bouton class definition

    class PlayBouton: public Bouton
    {

        public:
        SDL_Renderer* renderer;

        PlayBouton(SDL_Renderer* renderer, const char* pathToImg); //class constructor
        ~PlayBouton();
        void Onclick();
        
    };

    #endif
