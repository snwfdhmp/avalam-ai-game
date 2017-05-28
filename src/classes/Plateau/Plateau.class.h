// Project MPI [duck managed]
// Class Plateau (src/classes/Plateau/Plateau.class.h)
#ifndef PLATEAU_CLASS_H
    #define PLATEAU_CLASS_H
    
    //Plateau class definition
	#include "SDL2/SDL.h"
	#include "../Pion/Pion.class.hpp"
	#include "../Window/Window.class.h"
	#include "../Display/Display.class.h"
    class Plateau
    {
        public:

        Pion* cases[48];
		int hauteur;
        Plateau(Display*); //class constructor
        ~Plateau();
        
    };

    #endif
