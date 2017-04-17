#ifndef PLAN_H
#define PLAN_H


#include <time.h>
#include <stdlib.h>
#include "Emplacement.cpp"
#include "Mouvement.cpp"

#define TAILLE 9

class Plan
{
public:
	Mouvement mvt;
	int score, team;

	Plan() {
		score = -1;
		team = -1;
	}

	int init(int x_s, int y_s, int x_d, int y_d, int newTeam, Emplacement grille[TAILLE][TAILLE]) {
		team = newTeam;
		if(!mvt.init(x_s, y_s, x_d, y_d, grille)) return -1;
		return calcScore(grille);
	}

	int getPoints(Emplacement grille[TAILLE][TAILLE], int whichTeam) {
		int score=0, x, y;
		for (x = 0; x < TAILLE; ++x)
			for (y = 0; y < TAILLE; ++y)
				if(grille[x][y].valeur == whichTeam)
					score++;
		return score;
	}


	
	int calcScore(Emplacement grille[TAILLE][TAILLE]) {
		int x,y;
		Emplacement tmp[TAILLE][TAILLE];

		//copying
		for (x = 0; x < TAILLE; ++x)
		{
			for (y = 0; y < TAILLE; ++y)
			{
				tmp[x][y] = grille[x][y];
			}
		}

		//applying
		mvt.apply(tmp);
		score = getPoints(tmp, team);
		return score;
	}

	int getScore() {
		return score;
	}
};

#endif