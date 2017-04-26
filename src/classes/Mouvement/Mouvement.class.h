#ifndef MOUVEMENT_H
#define MOUVEMENT_H

#define TAILLE 9

class Mouvement
{
public:
	int src[2]; //[x, y]
	int des[2]; //[x, y]
	Emplacement tmp;

	int init(int x_s, int y_s, int x_d, int y_d, Emplacement grille[TAILLE][TAILLE]); //Initialise le mouvement

	bool isInTheField(int coor); //Renvoie si les coordonnées sont dans le plan

	bool isCorrect(int x_s, int y_s, int x_d, int y_d, Emplacement grille[TAILLE][TAILLE]); // Renvoie si les coordonnées sont correctes

	int verify(Emplacement grille[TAILLE][TAILLE]); // Réinitialise avec les mêmes valeurs

	int apply(Emplacement grille[TAILLE][TAILLE]); //applique le mouvement

};

#endif