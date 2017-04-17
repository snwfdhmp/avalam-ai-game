#include <time.h>
#include <stdlib.h>
#include "Emplacement.cpp"
#include "Mouvement.cpp"

#define TAILLE 9

class Plan
{
public:
	Mouvement mvt;
	int score;

	int init(int x_s, int y_s, int x_d, int y_d, Emplacement grille[TAILLE][TAILLE], int newScore) {
		score = newScore;
		calcScore();
		if(!mvt.init(x_s, y_s, x_d, y_d, grille)) {
			return -1;
		}
		return score;
	}
	
	void calcScore() {

	}
};