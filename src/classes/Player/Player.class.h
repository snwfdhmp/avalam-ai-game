#ifndef PLAYER_H
#define PLAYER_H

#include "../Emplacement/Emplacement.class.h"
#define TAILLE 9

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

	int getScore(Emplacement grille[TAILLE][TAILLE]); //return le score de l'équipe du joueur

	int evaluate(Emplacement grille[TAILLE][TAILLE]); //input un mouvement par le choisir
};

#endif