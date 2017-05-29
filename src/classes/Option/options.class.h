// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.hpp)
#ifndef OPTIONS_H
	#define OPTIONS_H
    
    #include "../Bouton/Bouton.class.h"
    #include "../GraphicComponent/GraphicComponent.class.h"
    #include "SDL2/SDL.h"
   
    //Bouton class definition

    class optionsBouton: public Bouton
    {

        public:
        int x, y, w, h;
        SDL_Renderer* renderer;

        optionsBouton(SDL_Renderer *renderer, char* path, int _x, int _y, int width, int height); //class constructor
        ~optionsBouton();
        
        void Onclick();
        void onMouseOver(SDL_Renderer *renderer);
        
    };

    #endif
