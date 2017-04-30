#ifndef GAMEINSTANCE_CLASS_CPP
#define GAMEINSTANCE_CLASS_CPP

#include <stdio.h>
#include <pthread.h>

#include "../Mouvement/Mouvement.class.h"
#include "../MovePlan/MovePlan.class.h"
#include "../Display/Display.class.h"
#include "../Player/Player.class.h"
#include "../Emplacement/Emplacement.class.h"
#include "../GameInstance/GameInstance.class.h"
#include "../../config/constants.h"
#include "../../config/macros.h"

GameInstance::GameInstance(Display* setDisp, Player* setPlayerA = NULL, Player* setPlayerB = NULL) {
	disp = setDisp;
	playerA = setPlayerA;
	playerB = setPlayerB;
}

void GameInstance::initGrille() {
	int x,y;

	//on remplit case par case en changeant de couleur à chaque ligne
	for (y = 0; y < TAILLE; ++y)
		for (x = 0; x < TAILLE; ++x)
			grille[x][y].init(y%2);

	//maintenant on définit les cases qui sont vides par défaut
	APPLY_DEFAULT_EMPTY(grille);
}

void* GameInstance::startGame(void *arg) {
	if(playerA == NULL || playerB == NULL)
		pthread_exit(NULL);
	
	initGrille();

	while(true)
		if(disp->update() && playerA->evaluate(grille) == -1 &&
			disp->update() && playerB->evaluate(grille) == -1)
			
			//onFinish(grille, &playerA, &playerB);

	(void) arg;
	pthread_exit(NULL);
}

#endif