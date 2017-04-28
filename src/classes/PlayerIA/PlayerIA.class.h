#ifndef PLAYERIA_H
#define PLAYERIA_H

#include <string.h>

#include "../Emplacement/Emplacement.class.h"

// include global constants
#include "../../config/constants.h"

using namespace std;

class PlayerIA
{
public:

	int team;
	string name;
	int delay;
	int points;

	//int pions[TAILLE*TAILLE][2] = {-1};

	int init(int newTeam, string newName = "IA"); // initialise l'IA

	int getScore(Emplacement grille[TAILLE][TAILLE]); //return le score de l'équipe de l'IA

	int randInt(int min, int max); //return random int entre bornes

	int evaluate(Emplacement grille[TAILLE][TAILLE]); //apply le MovePlan.mvt avec score max
};

#endif