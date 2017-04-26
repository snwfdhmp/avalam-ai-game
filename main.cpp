#include <stdio.h>
#include <stdlib.h>
#include "Emplacement.cpp"
#include "Mouvement.cpp"
#include "PlayerBot.cpp"
#include "PlayerIA.cpp"
#include "Player.cpp"

#define TAILLE 9
#define CONSOLE_HEIGHT 80

//GRILLE[X][Y]

void clearConsole() {
	int i;
	for (i = 0; i < CONSOLE_HEIGHT/5; ++i)
	{
		printf("\n\n\n\n\n");
	}
}

void printGrille(Emplacement grille[TAILLE][TAILLE]) {
	printf("=========================\n");
	printf("======== PLATEAU ========\n");
	printf("=========================\n");
	int x,y;
	int score[2] = {0, 0};
	printf("=    ==0== ==1== ==2== ==3== ==4== ==5== ==6== ==7== ==8==  =\n");
	for (y = 0; y < TAILLE; ++y)
	{
		printf("= %d: ", y);
		for (x = 0; x < TAILLE; ++x)
		{
			if (grille[x][y].valeur != 2) {
				(grille[x][y].valeur)?printf("\033[31m"):printf("\033[32m");
				printf("(%d:%d) ", grille[x][y].valeur, grille[x][y].hauteur);
				printf("\033[39m");
				score[grille[x][y].valeur]+=grille[x][y].hauteur;
			}
			else
				printf("      ");
		}
		printf(" =\n");
	}
	printf("==== 0 : %d | 1 : %d ====\n", score[0], score[1]);
}

void getPoints(int* point_zero, int* point_one, Emplacement grille[TAILLE][TAILLE]) {
	int x,y;
	*point_zero = 0;
	*point_one = 0;
	for (y = 0; y < TAILLE; ++y)
	{
		for (x = 0; x < TAILLE; ++x)
		{
			if(grille[x][y].valeur == 1) {
				*point_one+=grille[x][y].hauteur;
			} 
			if(grille[x][y].valeur == 0) {
				*point_zero+=grille[x][y].hauteur;
			}	
		}
	}
}

void initGrille(Emplacement grille[TAILLE][TAILLE]) {
	int x,y;

	//on remplit case par case en changeant de couleur à chaque ligne
	for (y = 0; y < TAILLE; ++y)
	{
		for (x = 0; x < TAILLE; ++x)
		{
			grille[x][y].init(y%2);
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
	//grille[3][2].hauteur = 0;
}

int main(int argc, char const *argv[])
{
	Emplacement grille[TAILLE][TAILLE];

	initGrille(grille);

	printGrille(grille);

	int points_Martin = 0, points_Landry = 0;
	int score_m = 0, score_l = 0;

	PlayerIA Martin;
	Player Landry;
	//PlayerBot* actual;
	Martin.init(0, "Martin");
	Landry.init(1, "Landry");

	int x_s,y_s,x_d,y_d;

	while(true) {
		printGrille(grille);
		getchar();
		if(Martin.evaluate(grille) == -1) {
			printGrille(grille);
			//getchar();
			if(Martin.getScore(grille) > Landry.getScore(grille)) {
				printf("Martin ");
				Martin.points++;
			}
			else if (Martin.getScore(grille) < Landry.getScore(grille)){
				printf("Landry ");
				Landry.points++;
			} else {
				printf("Egalité ");
			}
			printf("remporte la partie !\n");
			printf("M:%d | L:%d\n", Martin.points, Landry.points);
			initGrille(grille);
		}
		printGrille(grille);
		if(Landry.evaluate(grille) == -1) {
			printGrille(grille);
			//getchar();
			if(Martin.getScore(grille) > Landry.getScore(grille)) {
				printf("Martin ");
				Martin.points++;
			}
			else if (Martin.getScore(grille) < Landry.getScore(grille)){
				printf("Landry ");
				Landry.points++;
			} else {
				printf("Egalité ");
			}
			printf("remporte la partie !\n");
			printf("M:%d | L:%d\n", Martin.points, Landry.points);
			initGrille(grille);
		}
	}




	// 1 VS 1

	while(true) {
	printGrille(grille);
	Mouvement mvt;
	printf("=========================\n");
	printf("==========JOUER==========\n");
	printf("=========================\n");
	printf("====Quel pion bouger?====\n");
	printf("> x : ");
	scanf("%d", &x_s);
	printf("> y : ");
	scanf("%d", &y_s);
	printf("==Vers quelle position?==\n");
	printf("> x : ");
	scanf("%d", &x_d);
	printf("> y : ");
	scanf("%d", &y_d);
	if(!mvt.init(x_s, y_s, x_d, y_d, grille)) {
		printf("==!Mouvement incorrect!==\n");
	} else {
		printf("===!Mouvement correct!===\n");
		mvt.apply(grille);
	}
	}

	printGrille(grille);

	return 0;
}