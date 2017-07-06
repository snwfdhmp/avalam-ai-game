#ifndef EMPLACEMENT_H
#define EMPLACEMENT_H

class Emplacement
{
public:
	int valeur; // entre 0 ou 2
	int hauteur; // entre 0 et 5
	int x, y, selected = 0;

	void init(int val); // Initialise l'emplacement avec sa valeur

	bool isVide(); // renvoie si l'emplacement est vide
	
};

#endif