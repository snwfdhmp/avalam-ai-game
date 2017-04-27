#ifndef PLAN_H
#define PLAN_H

#include "../Emplacement/Emplacement.class.h"
#include "../Mouvement/Mouvement.class.h"

// include global constants
#include "../../config/constants.h"

class Plan
{
public:
	Mouvement mvt;
	int score, team;

	Plan(); //constructeur

	//Initialise le Plan
	int init(int x_s, int y_s, int x_d, int y_d, int newTeam, Emplacement grille[TAILLE][TAILLE]);

	//Calcule les points d'une équipe sur une grille
	int getPoints(Emplacement grille[TAILLE][TAILLE], int whichTeam);

	//Calcule le score du Plan
	int calcScore(Emplacement grille[TAILLE][TAILLE]);

	//Renvoie le score du Plan
	int getScore();
};

#endif