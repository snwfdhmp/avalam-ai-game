#include <stdio.h>
#include <stdlib.h>
#include "emplacement.cpp"

#define TAILLE 9

void printGrille(Emplacement* grille) {
	printf("Affichage du plateau : \n");
	int i,j;
	for (i = 0; i < TAILLE; ++i)
	{
		for (j = 0; j < TAILLE; ++j)
		{
			printf("%d ", grille[i][j].valeur);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	Emplacement grille[TAILLE][TAILLE];
	int i, j;

	for (i = 0; i < TAILLE; ++i)
	{
		for (j = 0; j < TAILLE; ++j)
		{
			grille[i][j].init(i%2);
		}
	}
	return 0;
}