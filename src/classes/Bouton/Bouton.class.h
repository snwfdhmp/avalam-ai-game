// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.hpp)
#ifndef BOUTON_CLASS_HPP
	#define BOUTON_CLASS_HPP
    
    #include "../GraphicComponent/GraphicComponent.class.h"
    #include "../Display/Display.class.h"
    #include "SDL2/SDL.h"
    //Bouton class definition    
    class Bouton : public GraphicComponent
    {
        public:
        SDL_Texture *texture;
        SDL_Surface *surface;
        int x, y, w, h;
        char* type;

        Bouton(SDL_Renderer* renderer, const char* pathToImg);
        Bouton(SDL_Renderer* renderer, SDL_Surface* set_surface);
        Bouton(SDL_Renderer *renderer, SDL_Surface, int x, int y, int w, int h);
        Bouton(Display* display, char* path, int x, int y, int w,int h);

       
        Bouton(); //class constructor
        ~Bouton();
        void Onclick();
        SDL_Surface* createBouton(Display* display, int x, int y, int w, int h);
    };

    #endif
