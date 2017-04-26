#ifndef PLAYERBOT_H
#define PLAYERBOT_H

#include <string>

#include "../Emplacement/Emplacement.class.h"

#define TAILLE 9

using namespace std;

/*
	Premier algo de bot
*/

class PlayerBot
{
public:

	int team;
	string name;
	int delay;
	int points;

	//int pions[TAILLE*TAILLE][2] = {-1};

	int init(int newTeam, string newName); //initialise le PlayerBot

	int getScore(Emplacement grille[TAILLE][TAILLE]); //return le score de l'équipe du PlayerBot

	int randInt(int min, int max); // return randomInt entre bornes

	int evaluate(Emplacement grille[TAILLE][TAILLE]); // apply le Plan.mvt avec scoremax
};

#endif