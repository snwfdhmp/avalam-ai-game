#ifndef PLAYER_CPP
#define PLAYER_CPP

#include <stdio.h>
#include <iostream>
#include <string>
#include "../Display/Display.class.h"
#include "../Emplacement/Emplacement.class.h"
#include "../Mouvement/Mouvement.class.h"
#include "../MovePlan/MovePlan.class.h"
#include "Player.class.h"
#include <vector>
#include "SDL2/SDL.h"

// include global constants
#include "../../config/constants.h"
#include "../../config/macros.h"

using namespace std;

int Player::init(Display* display, int newTeam, string newName, int newType) {
	if((!AVAILABLE_TEAM(newTeam)) || newName.empty() || (!AVAILABLE_TYPE(newType)))
		return -1;
	team = newTeam;
	name = newName;
	type = newType;
	playerDisplay = display;
	/* TODO : int(Player::*evaluate)(Emplacement[TAILLE][TAILLE]) function pointer
	switch(type) {
		case PLAYER_TYPE_HUMAN:
			evaluate=&Player::HumanEvaluate;
		break;
		case PLAYER_TYPE_IA:
			evaluate=&Player::IAEvaluate;
		break;
		default :
			evaluate=&Player::HumanEvaluate;
		break;
	}*/
	points = 0;
	//cout << name << " a rejoint la partie ! (équipe : "<< team <<")\n";
	return 0;
}

string Player::getName() {
	return name;
}

int Player::getScore(Emplacement grille[TAILLE][TAILLE]) {
	int score=0, x, y;
	for (x = 0; x < TAILLE; ++x)
		for (y = 0; y < TAILLE; ++y)
			if(grille[x][y].valeur == team) score++;
		return score;
}

int Player::HumanEvaluate(Emplacement grille[TAILLE][TAILLE]) {
	/*
	Mouvement mvt;
	int x_s, y_s, x_d, y_d;
	vector<int> click(1);
	Emplacement* first;
	Emplacement* second;

	puts("====Quel pion bouger?====\n");
	puts("> x : ");
	scanf("%d", &x_s);
	puts("> y : ");
	scanf("%d", &y_s);
	puts("==Vers quelle position?==\n");
	puts("> x : ");
	scanf("%d", &x_d);
	puts("> y : ");
	scanf("%d", &y_d);

	if(mvt.init(x_s, y_s, x_d, y_d, grille) == -1)
		return -1;

	mvt.apply(grille);

	*/
	
	Mouvement move;
	int x_s, y_s, x_d, y_d;

	std::vector<std::vector<int>> first;
	std::vector<std::vector<int>> second;

	int continuer = 1;
    SDL_Event event;
    
 	if(playerDisplay != NULL)
 		printf("Le joueur a un display\n");

	/*while(first.size() == 0 && second.size() == 0){
		printf("HumanEvaluate\n");
		if(first.size() == 0){
			if(first.push_back(playerDisplay->getSelect(grille)));
				printf("First : %d\n", first[0]);
			else
				printf("Probleme dans le getselect\n");
		}
		else{
			if(second.push_back(playerDisplay->getSelect(grille)));
				printf("Second %d\n", second[0]);
			else printf("Probleme dans le getSelect\n");
		}
	}

	if(move.init(first[0], first[0], second[0], second[0], grille) != -1)
		move.apply(grille);

		grille[first[0]][first[1]].selected = 0;
		grille[second[0]][second[1]].selected = 0;
		playerDisplay->printGrille(grille);*/

	return 0;
}

int Player::evaluate(Emplacement grille[TAILLE][TAILLE]) {
	
	switch(type) {
		case PLAYER_TYPE_HUMAN:
			printf("HumanEvaluate\n");
			return HumanEvaluate(grille);
			break;
		case PLAYER_TYPE_IA:
			printf("IAEvaluate\n");
			return IAEvaluate(grille);
			break;
		default:
			return HumanEvaluate(grille);
			break;
	}
}

int Player::IAEvaluate(Emplacement grille[TAILLE][TAILLE]) {
	int x, y, k, l;
	MovePlan bestmove, tmp;

	for (x = 0; x < TAILLE; ++x)
		for (y = 0; y < TAILLE; ++y)
			if(grille[x][y].valeur == 2)
				continue;
			else
				for (k = -1; k <= 1; ++k)
					for (l = -1; l <= 1; ++l)
						if(grille[x+l][y+k].valeur == 2) continue;
					else
						if(tmp.init(x, y, x+l, y+k, team, grille) > bestmove.getScore())
							bestmove.init(x, y, x+l, y+k, team, grille);

						bestmove.calcScore(grille);
						if(bestmove.score == -1) return -1;
						bestmove.mvt.apply(grille);
						return 0;
	}

#endif