#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "../Emplacement/Emplacement.class.h"

// include global constants
#include "../../config/constants.h"

using namespace std;

class Player
{
public:

	int team;
	string name;
	int delay;
	int points;

	//int pions[TAILLE*TAILLE][2] = {-1};

	int init(int newTeam, string newName); //initialise le joueur

	string getName(); //returns name

	int getScore(Emplacement grille[TAILLE][TAILLE]); //return le score de l'équipe du joueur

	int evaluate(Emplacement grille[TAILLE][TAILLE]); //input un mouvement par le choisir
};

#endif