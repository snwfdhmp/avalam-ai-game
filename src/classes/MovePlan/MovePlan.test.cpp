#include "MovePlan.class.h"
#include "../../config/constants.h"

/*
	UNIT TEST FOR MOVEPLAN
*/

#define SHOULD_BE_TRUE(a) if(!a)return-1;
#define SHOULD_BE_FALSE(a) if(a)return-1;


int main(int argc, char const *argv[])
{
	Emplacement grille[TAILLE][TAILLE];
	MovePlan a;
	SHOULD_BE_TRUE(a.init(-1, -1, -2, -2, NULL, 0));

	return 0;
}