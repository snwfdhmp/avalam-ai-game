// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.cpp)
#ifndef BOUTON_CLASS_CPP
#define BOUTON_CLASS_CPP

  //Bouton class methods implementation
  #include "Bouton.class.h"
  #include <stdio.h>
	
    //class constructor
    Bouton::Bouton(SDL_Renderer *renderer, char* path, int x, int y, int width, int heigth) 
    {
      // object initialization
      GraphicComponent* bouton = new GraphicComponent(renderer, path, x, y, width, heigth);
      // surface = SDL_LoadBMP(path);
      // texture = SDL_CreateTextureFromSurface(renderer, surface);
      // SDL_Rect position =  {x, y, w, h}; //Advice for w and h use bouton->w and bouton->h
      // SDL_RenderCopy(renderer, texture, NULL, &position);
      // SDL_RenderPresent(renderer);

      w = width;
      h = heigth;
    }
    
    Bouton::~Bouton(){}; 

   /* void Onclick(){
        printf("A bouton is clicked\n");
   }*/

#endif
