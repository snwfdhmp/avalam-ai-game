#ifndef PLAYER_IA_TEST_CPP
#define PLAYER_IA_TEST_CPP

#include <stdio.h>
#include "PlayerIA.class.h"

//include macro for testing
#include "../../config/macros.h"

int main(int argc, char const *argv[])
{
	PlayerIA a;
	unsigned char team;
	int err=0;

	for (team = 0; team < 2; ++team)
	{
		SHOULD_BE_TRUE(a.init(team, "Martin"))
		SHOULD_BE_TRUE(a.init(team, "L"))
		SHOULD_BE_TRUE(a.init(team, "MARTIN"))
		SHOULD_BE_FALSE(a.init(team, ""))
		SHOULD_BE_TRUE(a.init(team, " "))
	}

	UNIT_TEST_RETURN(err)
}

#endif