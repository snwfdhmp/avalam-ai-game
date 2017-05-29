// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.hpp)
#ifndef BOUTON_HPP
	#define BOUTON_HPP
    
    #include "../GraphicComponent/GraphicComponent.class.h"
    #include "../Display/Display.class.h"
    #include "SDL2/SDL.h"
    //Bouton class definition  

    class Bouton : public GraphicComponent
    {
        public:
        SDL_Renderer* renderer;
        int x, y, w, h;
        char* type;

        Bouton(SDL_Renderer *renderer, char* path, int x, int y, int w, int h);
        
        Bouton()=default; //class constructor
        ~Bouton();
        //void Onclick();
        SDL_Surface* createBouton(Display* display, int x, int y, int w, int h);
    };

    #endif
