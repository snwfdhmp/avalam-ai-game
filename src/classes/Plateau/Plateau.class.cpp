// Project MPI [duck managed]
// Class Plateau (src/classes/Plateau/Plateau.class.cpp)
   #ifndef PLATEAU_CLASS_CPP
    #define PLATEAU_CLASS_CPP

    //Plateau class methods implementation
	
    #include "Plateau.class.h"

    //class constructor
    Plateau::Plateau() {
        // object initialization
        /*SDL_SetRenderDrawColor(game->renderer, 0, 87, 122, 255);//Fond bleu
  		SDL_RenderClear(game->renderer);

  		pions[20].x = pions[28].x = 150;
    	pions[2].x = pions[6].x = pions[12].x = pions[21].x  = pions[29].x = 230;
    	pions[0].x = pions[3].x = pions[7].x = pions[13].x = pions[22].x = pions[30].x = pions[36].x = 310;
    	pions[1].x = pions[4].x = pions[8].x = pions[14].x = pions[23].x = pions[31].x = pions[37].x = 390;
    	pions[5].x = pions[9].x = pions[15].x = pions[32].x = pions[38].x = pions[42].x = 470;
    	pions[10].x = pions[16].x = pions[24].x = pions[33].x = pions[39].x = pions[43].x = pions[46].x = 550;
    	pions[11].x = pions[17].x = pions[25].x = pions[34].x = pions[40].x = pions[44].x = pions[47].x = 630;
    	pions[18].x = pions[26].x = pions[35].x = pions[41].x = pions[45].x = 710;
    	pions[19].x = pions[27].x = 790;

    	pions[0].y = pions[1].y = 100;
    	pions[2].y = pions[3].y = pions[4].y = pions[5].y = 180;
    	pions[7].y = pions[6].y = pions[8].y = pions[9].y = pions[10].y = pions[11].y = 260;
    	pions[12].y = pions[13].y = pions[14].y = pions[15].y = pions[16].y = pions[17].y = pions[18].y = pions[19].y = 340;
    	pions[20].y = pions[21].y = pions[22].y = pions[23].y = pions[24].y = pions[25].y = pions[26].y = pions[27].y = 420;
    	pions[28].y = pions[29].y = pions[30].y = pions[31].y = pions[32].y = pions[33].y = pions[34].y = pions[35].y = 500;
    	pions[36].y = pions[37].y = pions[38].y = pions[39].y = pions[40].y = pions[41].y = 580;
    	pions[42].y = pions[43].y = pions[44].y = pions[45].y = 660;
    	pions[46].y = pions[47].y = 740;

    	for(int i = 0; i < 49; i++){
    		pions[i].w = pions[i].h = 50; //taille d'une case : 50 x 50 pixels

    	if(pions[i].y == 100 || pions[i].y == 260 || pions[i].y == 420 || pions[i].y == 580 || pions[i].y == 740){
    		SDL_SetRenderDrawColor(game->renderer, 206, 170, 62, 255); //Couleur jaune
    		SDL_RenderFillRect(game->renderer, &pions[i]);
    	}

    	else{
    		SDL_SetRenderDrawColor(game->renderer, 121, 17, 100, 255); //Couleur rouge
    		SDL_RenderFillRect(game->renderer, &pions[i]);
    	}
      	SDL_RenderPresent(game->renderer);    	
      	}*/
    }
    #endif
