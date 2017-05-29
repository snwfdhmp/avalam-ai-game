// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.hpp)
#ifndef PLAY_HPP
    #define PLAY_HPP
    
    #include "../Bouton/Bouton.class.h"
    #include "../GraphicComponent/GraphicComponent.class.h"
    #include "SDL2/SDL.h"
   
    //Bouton class definition

    class playBouton: public Bouton
    {

        public:

        playBouton(SDL_Renderer *renderer, char* path, int _x, int _y, int width, int height); //class constructor
        ~playBouton();

        void onMouseOver();
        void Onclick();
        
    };

    #endif
