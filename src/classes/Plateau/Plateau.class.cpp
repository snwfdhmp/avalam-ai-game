// Project MPI [duck managed]
// Class Plateau (src/classes/Plateau/Plateau.class.cpp)
   #ifndef PLATEAU_CLASS_CPP
    #define PLATEAU_CLASS_CPP

    //Plateau class methods implementation
	
    #include "Plateau.class.h"

    //class constructor
    Plateau::Plateau(Display* game) {
        // object initialization
        /*SDL_SetRenderDrawColor(game->renderer, 0, 87, 122, 255);//Fond bleu
  		SDL_RenderClear(game->renderer);
  		cases[20].x = cases[28].x = 150;
    	cases[2].x = cases[6].x = cases[12].x = cases[21].x  = cases[29].x = 230;
    	cases[0].x = cases[3].x = cases[7].x = cases[13].x = cases[22].x = cases[30].x = cases[36].x = 310;
    	cases[1].x = cases[4].x = cases[8].x = cases[14].x = cases[23].x = cases[31].x = cases[37].x = 390;
    	cases[5].x = cases[9].x = cases[15].x = cases[32].x = cases[38].x = cases[42].x = 470;
    	cases[10].x = cases[16].x = cases[24].x = cases[33].x = cases[39].x = cases[43].x = cases[46].x = 550;
    	cases[11].x = cases[17].x = cases[25].x = cases[34].x = cases[40].x = cases[44].x = cases[47].x = 630;
    	cases[18].x = cases[26].x = cases[35].x = cases[41].x = cases[45].x = 710;
    	cases[19].x = cases[27].x = 790;

    	cases[0].y = cases[1].y = 100;
    	cases[2].y = cases[3].y = cases[4].y = cases[5].y = 180;
    	cases[7].y = cases[6].y = cases[8].y = cases[9].y = cases[10].y = cases[11].y = 260;
    	cases[12].y = cases[13].y = cases[14].y = cases[15].y = cases[16].y = cases[17].y = cases[18].y = cases[19].y = 340;
    	cases[20].y = cases[21].y = cases[22].y = cases[23].y = cases[24].y = cases[25].y = cases[26].y = cases[27].y = 420;
    	cases[28].y = cases[29].y = cases[30].y = cases[31].y = cases[32].y = cases[33].y = cases[34].y = cases[35].y = 500;
    	cases[36].y = cases[37].y = cases[38].y = cases[39].y = cases[40].y = cases[41].y = 580;
    	cases[42].y = cases[43].y = cases[44].y = cases[45].y = 660;
    	cases[46].y = cases[47].y = 740;

    	for(int i = 0; i < 49; i++){
    	cases[i].w = cases[i].h = 50; //taille d'une case : 50 x 50 pixels

    	if(cases[i].y == 100 || cases[i].y == 260 || cases[i].y == 420 || cases[i].y == 580 || cases[i].y == 740){
    		SDL_SetRenderDrawColor(game->renderer, 206, 170, 62, 255); //Couleur jaune
    		SDL_RenderFillRect(game->renderer, &cases[i]);
    	}

    	else{
    		SDL_SetRenderDrawColor(game->renderer, 121, 17, 100, 255); //Couleur rouge
    		SDL_RenderFillRect(game->renderer, &cases[i]);
    	}
      	SDL_RenderPresent(game->renderer);    	
      	}	*/
    }

    #endif
