// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.hpp)
#ifndef BOUTON_CLASS_HPP
	#define BOUTON_CLASS_HPP
    
    #include "../Bouton/Bouton.class.h"
    //Bouton class definition

    class PlayBouton: public Bouton
    {
        public:
        PlayBouton(); //class constructor
        ~PlayBouton();
        void Onclick();
    };

    #endif
