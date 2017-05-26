#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "classes/Emplacement/Emplacement.class.h"
#include "classes/Mouvement/Mouvement.class.h"
#include "classes/GC_Play/Play.class.hpp"
#include "classes/Player/Player.class.h"
#include "classes/Window/Window.class.h"
#include "config/macros.h"
#include "config/constants.h"
#include "SDL2/SDL.h"
#include "classes/GameInstance/GameInstance.class.h"
#undef main

using namespace std;

int main(int argc, char const *argv[])
{

	Window* window = new Window("Avalam by Joly and Monga", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1012, 568, SDL_WINDOW_SHOWN); //Window init
	window->setIcon("ressources/img/chess.bmp"); //Icon init
	
	Display* menu = new Display(window);
  	
	menu->createmenu();
	window->handleEvent(menu);
    //todo : transform to window->handleEvent(menu, background)
    //handleEvent(window, menu, background);
  SDL_DestroyWindow(window->window);
  SDL_Quit(); 
	
  while(true) {
		window->update();
	}

	return 0;
}