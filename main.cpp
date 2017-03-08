#include <stdio.h>
#include <stdlib.h>
#include "Emplacement.cpp"
#include "Mouvement.cpp"

#define TAILLE 9

void printGrille(Emplacement grille[TAILLE][TAILLE]) {
	printf("Affichage du plateau : \n");
	int i,j;
	for (i = 0; i < TAILLE; ++i)
	{
		for (j = 0; j < TAILLE; ++j)
		{
			if (grille[j][i].valeur != 2)
				printf("%d ", grille[j][i].valeur);
			else
				printf("  ");
		}
	printf("\n");
}
}



void initGrille(Emplacement grille[TAILLE][TAILLE]) {
	int i, j;

	//on remplit case par case en changeant de couleur à chaque ligne
	for (i = 0; i < TAILLE; ++i)
	{
		for (j = 0; j < TAILLE; ++j)
		{
			grille[j][i].init(i%2);
			//grille[i][j].init(0);
		}
	}

	//maintenant on définit les cases qui sont vides par défaut
	grille[4][4].valeur = 2;
	grille[0][0].valeur = 2;
	grille[1][0].valeur = 2;
	grille[4][0].valeur = 2;
	grille[5][0].valeur = 2;
	grille[6][0].valeur = 2;
	grille[7][0].valeur = 2;
	grille[8][0].valeur = 2;
	grille[0][1].valeur = 2;
	grille[5][1].valeur = 2;
	grille[6][1].valeur = 2;
	grille[7][1].valeur = 2;
	grille[8][1].valeur = 2;
	grille[0][2].valeur = 2;
	grille[7][2].valeur = 2;
	grille[8][2].valeur = 2;
	grille[0][3].valeur = 2;
	grille[8][3].valeur = 2;
	grille[8][5].valeur = 2;
	grille[0][6].valeur = 2;
	grille[1][6].valeur = 2;
	grille[8][6].valeur = 2;
	grille[0][7].valeur = 2;
	grille[1][7].valeur = 2;
	grille[2][7].valeur = 2;
	grille[3][7].valeur = 2;
	grille[8][7].valeur = 2;
	grille[0][8].valeur = 2;
	grille[1][8].valeur = 2;
	grille[2][8].valeur = 2;
	grille[3][8].valeur = 2;
	grille[4][8].valeur = 2;
	grille[7][8].valeur = 2;
	grille[8][8].valeur = 2;


	//custom -> à supprimer
	grille[3][2].hauteur = 0;
}

int main(int argc, char const *argv[])
{
	Emplacement grille[TAILLE][TAILLE];

	initGrille(grille);

	printGrille(grille);

	Mouvement depart;
	depart.init(2,3,0,0, grille);

	return 0;
}