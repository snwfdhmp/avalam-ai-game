#ifndef GAMEINSTANCE_TEST_CPP
#define GAMEINSTANCE_TEST_CPP

#include <stdio.h>
#include <pthread.h>

#include "../Display/Display.class.h"
#include "../Player/Player.class.h"
#include "../Emplacement/Emplacement.class.h"
#include "../GameInstance/GameInstance.class.h"
#include "../../config/constants.h"

int main(int argc, char const *argv[])
{
	Display* disp = new Display(0, 0, 500, 500);
	Player playerA, playerB;
	playerA.init(0, "Martin", PLAYER_TYPE_HUMAN);
	playerB.init(1, "Landry", PLAYER_TYPE_HUMAN);
	GameInstance* game = new GameInstance(disp, &playerA, &playerB);
	void* (GameInstance::*start)(void*) = &GameInstance::startGame;
	pthread_t thread;

	pthread_create(&thread, NULL, (game->*start)(void*), NULL);

	pthread_join(thread, NULL);

	return 0;
}

#endif