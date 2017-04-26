#ifndef MOUVEMENT_CPP
#define MOUVEMENT_CPP

#include <stdio.h>
#include "../Emplacement/Emplacement.class.h"

#define TAILLE 9

bool Mouvement::isInTheField(int coor) {
	return coor < TAILLE && coor >= 0;
}

bool Mouvement::isCorrect(int x_s, int y_s, int x_d, int y_d, Emplacement grille[TAILLE][TAILLE]) {
	bool field = (isInTheField(x_s) && isInTheField(y_s) && isInTheField(x_d) && isInTheField(y_d) && grille[x_s][y_s].valeur != 2 && grille[x_d][y_d].valeur != 2 && x_s-x_d >= -1 && x_s-x_d <= 1 && y_s-y_d >= -1 && y_s-y_d <= 1);
	    //if(!field)
	    //	printf("==!Position incorrecte [%d:%d]=>[%d:%d]!==\n", x_s, y_s, x_d, y_d);
	bool different = (x_s != x_d || y_s != y_d);
		//if(!different)
		//	printf("==!C'est la même pièce!==\n");
	bool hauteurLegale = (grille[x_d][y_d].hauteur > 0 && grille[x_s][y_s].hauteur > 0 && grille[x_s][y_s].hauteur+grille[x_d][y_d].hauteur <= 5);
		//if(!hauteurLegale && grille[x_d][y_d].hauteur > 0 && grille[x_s][y_s].hauteur > 0)
		//	printf("grille[x_d][y_d].hauteur [%d] > 0 && grille[x_s][y_s].hauteur [%d] > 0 && grille[x_s][y_s].hauteur+grille[x_d][y_d].hauteur [%d] <= 5\n",grille[x_d][y_d].hauteur, grille[x_s][y_s].hauteur, grille[x_s][y_s].hauteur+grille[x_d][y_d].hauteur);
	return field && different && hauteurLegale;
}

int Mouvement::init(int x_s, int y_s, int x_d, int y_d, Emplacement grille[TAILLE][TAILLE]) { //s = src, d= des 
	if (!isCorrect(x_s, y_s, x_d, y_d, grille))
		return -1;

	src[0] = x_s;
	src[1] = y_s;
	des[0] = x_d;
	des[1] = y_d;

	return 1;
}

int Mouvement::apply(Emplacement grille[TAILLE][TAILLE]) {
	if(!isCorrect(src[0], src[1], des[0], des[1], grille))
		return -1;
		//printf("grille[%d][%d].valeur (:%d) = grille[%d][%d].valeur (:%d)\n", des[0], des[1], grille[des[0]][des[1]].valeur, src[0], src[1], grille[src[0]][src[1]].valeur);
		//printf("grille[%d][%d].hauteur (:%d) += grille[%d[%d].hauteur (:%d)\n", des[0], des[1], grille[des[0]][des[1]].hauteur, src[0], src[1], grille[src[0]][src[1]].hauteur);
	grille[des[0]][des[1]].valeur = grille[src[0]][src[1]].valeur;
	grille[des[0]][des[1]].hauteur += grille[src[0]][src[1]].hauteur;
	grille[src[0]][src[1]].valeur = 2;
	grille[src[0]][src[1]].hauteur = 0;
		//printf("executing\n");
	return 1;
}

int Mouvement::verify(Emplacement grille[TAILLE][TAILLE]) {
	return init(src[0], src[1], des[0], des[1], grille);
}


#endif