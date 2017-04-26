#ifndef PLAYERIA_CPP
#define PLAYERIA_CPP

#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <time.h>
#include <stdlib.h>

#include "../Emplacement/Emplacement.class.h"
#include "../MovePlan/MovePlan.class.h"
#include "PlayerIA.class.h"

#define TAILLE 9

using namespace std;

/* Version en dev de l'IA */

int PlayerIA::init(int newTeam, string newName) {
	srand(time(NULL));
	team = newTeam;
	name = newName;
	points = 0;
	cout << "Bot " << name << " initialisé ! (équipe : "<< team <<")\n";


	return 1;
}

int PlayerIA::getScore(Emplacement grille[TAILLE][TAILLE]) {
	int score=0, x, y;
	for (x = 0; x < TAILLE; ++x)
		for (y = 0; y < TAILLE; ++y)
			if(grille[x][y].valeur == team)
				score+=grille[x][y].hauteur;
			return score;
}

int PlayerIA::randInt(int min, int max) {
	return (int) rand()%(max-min) + min;
}


int PlayerIA::evaluate(Emplacement grille[TAILLE][TAILLE]) {
	int x, y, k, l, len=0;
	MovePlan bestmove, tmp;
	int big = 0;

		//bestmove.score = -1;

	for (x = 0; x < TAILLE; ++x)
	{
		for (y = 0; y < TAILLE; ++y)
		{
			if(grille[x][y].valeur == 2) continue;
			for (k = -1; k <= 1; ++k)
			{
				for (l = -1; l <= 1; ++l)
				{
					if(grille[x+l][y+k].valeur == 2) continue;
					int scr = tmp.init(x, y, x+l, y+k, team, grille);
						//printf("tmp.init(%d, %d, %d, %d, %d, grille) [%d] > bestmove.score [%d]\n", x, y, x+l, y+k, team, scr, bestmove.score);
						//if(scr != -1) printf("score [%d]\n", scr);
					if(scr > bestmove.getScore()){
						bestmove.init(x, y, x+l, y+k, team, grille);
					}
				}	
			}
		}
	}
	bestmove.calcScore(grille);
	if(bestmove.score == -1) return -1;
		//cout << name <<" ";
		//printf("[%d:%d] => [%d:%d] (score:%d)\n", bestmove.mvt.src[0], bestmove.mvt.src[1], bestmove.mvt.des[0], bestmove.mvt.des[1], bestmove.score);
	bestmove.mvt.apply(grille);
	return 0;
}

#endif