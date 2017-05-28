// Project MPI [duck managed]
// Class Pion (src/classes/Pion/Pion.class.cpp)
   #ifndef PION_CLASS_CPP
    #define PION_CLASS_CPP

    //Pion class methods implementation
    #include "Pion.class.hpp"
    #include <stdio.h>
	
    //class constructor
    Pion::Pion(SDL_Rect pion) {
        // object initialization
    	pion.x = x;
    	pion.y = y;
    	pion.w = w;
    	pion.h = h;
    	hauteur = 1;
    }

   #endif
