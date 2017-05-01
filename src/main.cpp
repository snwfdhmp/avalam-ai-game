#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "classes/Emplacement/Emplacement.class.h"
#include "classes/Mouvement/Mouvement.class.h"
#include "classes/Player/Player.class.h"
#include "classes/GameInstance/GameInstance.class.h"
#include "config/macros.h"
#include "config/constants.h"

using namespace std;

//GRILLE[X][Y]

void clearConsole() {
	int i;
	for (i = 0; i < CONSOLE_HEIGHT/5; ++i)
		printf("\n\n\n\n\n");
}



int main(int argc, char const *argv[])
{
	Display* disp = new Display(0,0,500,500);
	printf("Welcome to AVALAM Game !\n");
	printf("Select a game mode :\n");

	Player playerA, playerB;

	playerA.init(0, "Martin", PLAYER_TYPE_HUMAN);
	playerB.init(1, "Landry", PLAYER_TYPE_HUMAN);

	GameInstance* game = new GameInstance(disp, &playerA, &playerB);
	game->startGame(NULL);

	/*

	do{
	printf("1:Human vs Human\n2:Human vs IA\n3:IA vs IA\n");
	printf("4:Quit\nChoice : ");
	scanf("%d", &choice);
	switch(choice) {
		case 1:
			GameInstance* game = new GameInstance(disp, );
			pthread_t thread;

			pthread_create(&thread, NULL, (game->*start)(void*), NULL);

			pthread_join(thread, NULL);
			break;
		case 2:
			play(PLAYER_TYPE_HUMAN, PLAYER_TYPE_IA);
			break;
		case 3:
			play(PLAYER_TYPE_IA, PLAYER_TYPE_IA);
			break;
		case 4:
			printf("See you soon !\n");
			break;
		default :
			printf("Please enter a choice between 1 and 4...\n");
			break;
	}
	} while(choice != 4);*/

	return 0;
}