#include "SDL2/SDL.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "classes/Emplacement/Emplacement.class.h"
#include "classes/Mouvement/Mouvement.class.h"
#include "classes/Player/Player.class.h"
#include "classes/Display/Display.class.h"
#include "classes/GraphicComponent/GraphicComponent.class.h"
#include "config/macros.h"
#include "config/constants.h"
#undef main

using namespace std;

//GRILLE[X][Y]

void clearConsole() {
	int i;
	for (i = 0; i < CONSOLE_HEIGHT/5; ++i)
		printf("\n\n\n\n\n");
}

int createMenu(SDL_Window *window){
	Display intro(0, 0, 800, 600, window);
	GraphicComponent *background, *menu;
	string path = "ressources/img/avalam_FI.bmp";
	//background.initSurface("resources/img/avalam_FI.bmp");
	background->surface = SDL_LoadBMP("ressources/img/avalam_FI.bmp");
	background->initTexture(intro.renderer, background->surface);
	SDL_Rect position = {300, 300, 0, 0};
	SDL_Delay(3000);
	SDL_RenderCopy(intro.renderer, background->texture, NULL, &position);
    SDL_BlitSurface(background->surface, NULL, background->surface, &position);
    SDL_RenderPresent(intro.renderer);
    //menu->initRenderer(window);
    menu->surface = SDL_LoadBMP("ressources/img/menu.bmp");
    SDL_Rect menu_pos = {300, 300, 0, 0};
    

	//First Image of the Game
	/*SDL_Renderer *renderer = initrenderer(window);
	
	SDL_Rect image_pos = {640/2 - surface->w/2, 480/2 - surface->h/2, surface->w, surface->h};
	SDL_Texture* texture = intiTexture(window, surface); // Préparation du sprite
	SDL_RenderCopy(renderer, texture, NULL, &image_pos);
	SDL_RenderPresent(pRenderer);
	SDL_Delay(2500);
	DestroyTexture(texture);
	DestroyRenderer(renderer);

	Menu interface
	 SDL_Renderer *menu_renderer = initrenderer(window);
	 SDL_Surface *menu_background = SDL_LoadBMP("resources/img/menu_background.bmp");*/
    return 0;
}

int printGrille(Emplacement grille[TAILLE][TAILLE]) {
	printf("=========================\n");
	printf("======== PLATEAU ========\n");
	printf("=========================\n");
	int x,y;
	int score[2] = {0, 0};
	printf("=    ==0== ==1== ==2== ==3== ==4== ==5== ==6== ==7== ==8==  =\n");
	for (y = 0;y < TAILLE; ++y)
	{
		printf("= %d: ", y);
		for (x = 0; x < TAILLE; ++x)
		{
			if (grille[x][y].valeur != 2) {
				(grille[x][y].valeur)?printf("\033[31m"):printf("\033[32m");
				printf("(%d:%d) ", grille[x][y].valeur, grille[x][y].hauteur);
				printf("\033[39m");
				score[grille[x][y].valeur]+=grille[x][y].hauteur;
			}
			else
				printf("      ");
		}
		printf(" =\n");
	}
	printf("==== 0 : %d | 1 : %d ====\n", score[0], score[1]);
	return 0;
}

void initGrille(Emplacement grille[TAILLE][TAILLE]) {
	int x,y;

	//on remplit case par case en changeant de couleur à chaque ligne
	for (y = 0; y < TAILLE; ++y)
		for (x = 0; x < TAILLE; ++x)
			grille[x][y].init(y%2);

	//maintenant on définit les cases qui sont vides par défaut
	APPLY_DEFAULT_EMPTY(grille);

}

int onFinish(Emplacement grille[TAILLE][TAILLE], Player* playerA, Player* playerB) {
	printf("OnFinish !\n");
	printGrille(grille);
	//getchar();
	if(playerA->getScore(grille) > playerB->getScore(grille))
		cout << playerA->getName() << " remporte la partie ! (points -> "<< playerA->points++ << "+1)\n";
	else if (playerA->getScore(grille) < playerB->getScore(grille))
		cout << playerB->getName() << " remporte la partie ! (points -> "<< playerB->points++ << "+1)\n";
	else
		printf("Egalité !");

	printf("M:%d | L:%d\n", playerA->points, playerB->points);

	initGrille(grille);
	return 0;
}

int play(int playerAType = PLAYER_TYPE_HUMAN, int playerBType = PLAYER_TYPE_HUMAN) {
	Player playerA, playerB;

	Emplacement grille[TAILLE][TAILLE];

	initGrille(grille);
	//PlayerBot* actual;
	if(ENV_DEV) {
		playerA.init(0, "Martin", playerAType);
		playerB.init(1, "Landry", playerBType);
	} else {
		string nameA, nameB;
		cout << "Player 1 name : ";
		cin >> nameA;
		cout << "Player 2 name : ";
		cin >> nameB;
		playerA.init(0, nameA,playerAType);
		playerB.init(1, nameB,playerBType);
	}

	//TODO : explain C++ tricks
	while(true)
		if(printGrille(grille) && playerA.evaluate(grille) == -1 &&
			printGrille(grille) && playerB.evaluate(grille) == -1)
			onFinish(grille, &playerA, &playerB);
	return 0;
}

int main(int argc, char const *argv[])
{
	SDL_Window *window = NULL;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    bool terminer = false;
    window = SDL_CreateWindow("Avalam by Joly and Monga", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	SDL_Surface *icone = SDL_LoadBMP("ressources/img/chess.bmp");
  	SDL_SetWindowIcon(window, icone);
  	SDL_Event evenements;

    SDL_WaitEvent(&evenements);

  	/*while(!terminer)
    {
        SDL_WaitEvent(&evenements);
		
        if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
        terminer = true;
    }*/
	
	SDL_Delay(3000);

	return 0;
}