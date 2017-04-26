#ifndef MOVEPLAN_CPP
#define MOVEPLAN_CPP

#include <time.h>
#include <stdlib.h>

#include "../Emplacement/Emplacement.class.h"
#include "../Mouvement/Mouvement.class.h"
#include "MovePlan.class.h"

#define TAILLE 9

MovePlan::MovePlan() {
	score = -1;
	team = -1;
}

int MovePlan::init(int x_s, int y_s, int x_d, int y_d, int newTeam, Emplacement grille[TAILLE][TAILLE]) {
	team = newTeam;
	if(!mvt.init(x_s, y_s, x_d, y_d, grille)) return -1;
	return calcScore(grille);
}

int MovePlan::getPoints(Emplacement grille[TAILLE][TAILLE], int whichTeam) {
	int score=0, x, y;
	for (x = 0; x < TAILLE; ++x)
		for (y = 0; y < TAILLE; ++y)
			if(grille[x][y].valeur == whichTeam)
				score+= grille[x][y].hauteur;
	return score;
}



int MovePlan::calcScore(Emplacement grille[TAILLE][TAILLE]) {
	if(!mvt.verify(grille)) {
		score = -1;
		return -1;
	}
	int x,y;
	Emplacement tmp[TAILLE][TAILLE];

	//copying
	for (x = 0; x < TAILLE; ++x)
		for (y = 0; y < TAILLE; ++y)
			tmp[x][y] = grille[x][y];

	//applying
	mvt.apply(tmp);
	score = getPoints(tmp, team) - (getPoints(tmp, !team) - getPoints(grille, !team));
	return score;
}

int MovePlan::getScore() {
	return score;
}

#endif