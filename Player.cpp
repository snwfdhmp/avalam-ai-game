#include <stdio.h>
#include <iostream>
#include <string>
#include "Emplacement.cpp"
#include "Mouvement.cpp"

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

	int init(int newTeam, string newName) {
		team = newTeam;
		name = newName;
		points = 0;
		cout << name << " a rejoint la partie ! (équipe : "<< team <<")\n";


		return 1;
	}

	int getScore(Emplacement grille[TAILLE][TAILLE]) {
		int score=0, x, y;
		for (x = 0; x < TAILLE; ++x) {
			for (y = 0; y < TAILLE; ++y) {
				if(grille[x][y].valeur == team) score++;
			}
		}
		return score;
	}


	int evaluate(Emplacement grille[TAILLE][TAILLE]) {
		Mouvement mvt;
		int x_s, y_s, x_d, y_d;

		printf("====Quel pion bouger?====\n");
		printf("> x : ");
		scanf("%d", &x_s);
		printf("> y : ");
		scanf("%d", &y_s);
		printf("==Vers quelle position?==\n");
		printf("> x : ");
		scanf("%d", &x_d);
		printf("> y : ");
		scanf("%d", &y_d);
		if(!mvt.init(x_s, y_s, x_d, y_d, grille)) {
			printf("==!Mouvement incorrect!==\n");
		} else {
			printf("===!Mouvement correct!===\n");
			mvt.apply(grille);
		}
		return 0;
	}
};