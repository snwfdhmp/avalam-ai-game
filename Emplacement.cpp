#ifndef EMPLACEMENT_H
#define EMPLACEMENT_H

#include <stdio.h>
#include <stdlib.h>
#define TAILLE 9

class Emplacement
{
public:
	int valeur; // 0 ou 1
	int hauteur; // entre 0 et 5

	void init(int val) {
		if(val == 2) { //si on souhaite créer une case vide
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

#endif