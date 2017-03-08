#include <stdio.h>
#include <stdlib.h>
#define TAILLE 9

class Emplacement
{
public:
	int valeur; // 1 ou 2
	int hauteur; // entre 0 et 5

	void init(int val) {
		if(val == 0) { //si on souhaite créer une case vide
			hauteur = 0;
		}
		else { //TODO intégrer vérification de valeur
			valeur = val;
			hauteur = 1;
		}
	}

	bool isVide() {
		return hauteur==0;
	}

	
};