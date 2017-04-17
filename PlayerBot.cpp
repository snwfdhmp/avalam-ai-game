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
		int i, j, k, l, y, x;
		int biggest_score;
		int biggest_index;
		int tmp_score;

		Plan* correct_moves;
		Mouvement tmp;
		int mov[TAILLE*TAILLE*6][4]; // [x][0] : x_s[x] [1][x] : y_s[x] [2][x] : x_d[x] [3][x] : y_d[x]
		int len = 0;
		for (y = 0; y < TAILLE; ++y)
		{
			for (x = 0; x < TAILLE; ++x)
			{
				if(grille[x][y].valeur != 2) {
					for(k=-1; k<=1;k++) {
						for(l=-1; l<=1; l++) {
							if(grille[x+l][y+k].valeur != 2 && tmp.init(x, y, x+l, y+k, grille)) {
								mov[len][0] = x;
								mov[len][1] = y;
								mov[len][2] = x+l;
								mov[len][3] = y+k;
								len++;
							//printf("%d\n", len);
							}
						}
					}
				}
			}
		}

		if(len<=0)
			return -1;
		

			// now scoring and picking the best
		correct_moves = (Plan*) malloc(sizeof(Plan)*len);
		biggest_score = 0;
		biggest_index = 0;

		for (i = 0; i < len; ++i)
		{
			tmp_score = correct_moves[i].init(mov[i][0],mov[i][1],mov[i][2],mov[i][3],grille, rand()%500);
			//printf("[%d:%d]=>[%d:%d] ? ", mov[i][0],mov[i][1],mov[i][2],mov[i][3]);
			if(tmp_score > biggest_score) {
				//printf("bigger\n");
				biggest_score = tmp_score;
				biggest_index = i;
			} else {
				//printf("\n");
			}
		}
		//printf("[%d,%d] => [%d, %d] (score : %d)\n", correct_moves[biggest_index].mvt.src[0], correct_moves[biggest_index].mvt.src[1], correct_moves[biggest_index].mvt.des[0], correct_moves[biggest_index].mvt.des[1], biggest_score);
		
		Mouvement end;
		end.init(correct_moves[biggest_index].mvt.src[0], correct_moves[biggest_index].mvt.src[1], correct_moves[biggest_index].mvt.des[0], correct_moves[biggest_index].mvt.des[1], grille);
		end.apply(grille);
		free(correct_moves);

		return 1;
	}




	//Imported and adapted from PlayerIA
	int getScore(Emplacement grille[TAILLE][TAILLE]) {
		int score=0, x, y;
		for (x = 0; x < TAILLE; ++x)
			for (y = 0; y < TAILLE; ++y)
				if(grille[x][y].valeur == team)
					score++;
		return score;
	}
};