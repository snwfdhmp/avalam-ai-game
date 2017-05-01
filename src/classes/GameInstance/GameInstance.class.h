#ifndef GAMEINSTANCE_CLASS_H
#define GAMEINSTANCE_CLASS_H

#include "../Display/Display.class.h"
#include "../Player/Player.class.h"
#include "../Emplacement/Emplacement.class.h"

class GameInstance
{
public:
	Emplacement grille[TAILLE][TAILLE];
	int state;
	Display* disp;
	Player *playerA, *playerB;
	GameInstance(Display* setDisp, Player* setPlayerA, Player* setPlayerB);
	~GameInstance();
	void* (GameInstance::*start)(void*);


	void* startGame(void* arg); //starts a game playerA vs player

	void* askNames(void* arg);

	void initGrille();

	int currentState();
	/*	returns game instance state.
		States :
		GAME_WAIT -> game waiting to start
		GAME_PLAYING -> a game is actually being played
		GAME_OVER -> last game has finished and currently waiting for event
		GAME_QUITTED -> game is quitted
	*/
	
	void *inputMovement(); 
};

#endif