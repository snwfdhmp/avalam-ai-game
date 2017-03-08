#include <stdio.h>
#include "Emplacement.cpp"

#define TAILLE 9

class Mouvement
{
public:
	int src[2]; //[x, y]
	int des[2]; //[x, y]

	bool isInTheField(int coor) {
		return coor < 9 && coor >= 0;
	}

	bool isCorrect(int x_s, int y_s, int x_d, int y_d, Emplacement grille[TAILLE][TAILLE]) {
		bool field = (isInTheField(x_s) && isInTheField(y_s) && isInTheField(x_d) && isInTheField(y_d));
		bool different = (x_s != x_d || y_s != y_d);
		bool hauteurLegale = (grille[y_d][x_d].hauteur > 0 && grille[y_s][x_s].hauteur > 0);
		return field*different*hauteurLegale;
	}

	void init(int x_s, int y_s, int x_d, int y_d, Emplacement grille[TAILLE][TAILLE]) { //s = src, d= des 
		if (isCorrect(x_s, y_s, x_d, y_d, grille))
		{
			src[0] = x_s;
			src[1] = y_s;
			des[0] = x_d;
			des[1] = y_d;
			printf("Déclaration du mouvement : correcte.\n");
		}
		else {
			printf("Erreur lors de la déclaration du mouvement.\n");
			return;
		}
	}
	
};