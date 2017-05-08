#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "classes/Emplacement/Emplacement.class.h"
#include "classes/Mouvement/Mouvement.class.h"
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
	Window* window = new Window("Avalam", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	Display* intro = new Display(window);
	GraphicComponent* background = new GraphicComponent(intro->renderer, "../ressources/img/Avalam-menu.bmp");
	SDL_Rect position = {300, 300, 0, 0};
	SDL_RenderCopy(intro->renderer, background->texture, NULL, &position);
    SDL_BlitSurface(background->surface, NULL, background->surface, &position);
    SDL_RenderPresent(intro->renderer);

    window->setIcon("../ressources/img/chess.bmp");

	while(true) {
		window->update();
	}

	return 0;
}