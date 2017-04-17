#include <stdio.h>
#include <iostream>
#include <string>
#include "Emplacement.cpp"
#include "Mouvement.cpp"
#include <stack>
#include <time.h>
#include <stdlib.h>
#include "Plan.cpp"

#define TAILLE 9

using namespace std;

class PlayerBot
{
public:

	int team;
	string name;
	int delay;
	int points;

	//int pions[TAILLE*TAILLE][2] = {-1};

	int init(int newTeam, string newName) {
		srand(time(NULL));
		team = newTeam;
		name = newName;
		points = 0;
		cout << "Bot " << name << " initialisé ! (équipe : "<< team <<")\n";


		return 1;
	}

	int getScore(Emplacement grille[TAILLE][TAILLE]) {
		int score=0, x, y;
		for (x = 0; x < TAILLE; ++x)
			for (y = 0; y < TAILLE; ++y)
				if(grille[x][y].valeur == team)
					score+=grille[x][y].hauteur;
		return score;
	}

	/*void getPions(Emplacement grille[TAILLE][TAILLE]) {
		int x,y; //variables for

		//on vide le stack
		while(!pions.empty())
			pions.pop();

		for (x = 0; x < TAILLE; ++x)
			for (y = 0; y < TAILLE; ++y)
				if(grille[x][y].valeur == team) {
					int pos[2];
					pos[0] = x;
					pos[1] = y;
					pions.push(pos); //on ajoute tous nos pions
				}
	}*/

	int randInt(int min, int max) {
		return (int) rand()%(max-min) + min;
	}


	int evaluate(Emplacement grille[TAILLE][TAILLE]) {
		int x, y, k, l, len=0;
		Plan bestmove, tmp;
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
						if(scr > bestmove.getScore()){
							bestmove.init(x, y, x+l, y+k, team, grille);
						}
					}	
				}
			}
		}

		if(bestmove.score == -1) return -1;
		cout << name <<" ";
		printf("[%d:%d] => [%d:%d] (score:%d)\n", bestmove.mvt.src[0], bestmove.mvt.src[1], bestmove.mvt.des[0], bestmove.mvt.des[1], bestmove.score);
		bestmove.mvt.apply(grille);
		return 0;
	}
};