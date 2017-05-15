// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.class.cpp)
   #ifndef PLAY_CPP
    #define PLAY_CPP

    //Bouton class methods implementation

    #include "Play.class.hpp"
    #include "../GraphicComponenent/GraphicComponenent.class.h"
    #include "../Display/Display.class.h"
    #include "SDL2/SDL.h"
    #include <stdio.h>
	
    //class constructor
    PlayBouton::PlayBouton(){
        // object initialization
    }
    
    void Onclick(){
        printf("Le play a a ete clique\n");
        /*DestroyRenderer(this.display);
        Window* game = new Window("Avalam", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 900, 0); //Window init
        game->setIcon("ressources/img/chess.bmp"); //Icon init
        Display* game_display = new Display(game);
    
        SDL_Rect cases[48]; // Déclaration du tableau contenant les cases blanches
        SDL_Point ligne_depart, ligne_arrivee; // Déclaration du point de départ et du point d'arrivée d'une ligne

    // Création du renderer :
    if(game_display->renderer == NULL) // Gestion des erreurs
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return -1;
    }
    // On s'occupe tout d'abord des cases de l'échiquier
    SDL_SetRenderDrawColor(game_display->renderer, 55, 194, 31, 255);
    SDL_RenderClear(game_display->renderer);
    // Le fond est à présent vert
    SDL_SetRenderDrawColor(game_display->renderer, 0, 0, 0, 255); //Couleur blanche

    // Nous allons maintenant remplir les cases blanches par dessus le fond noir
    // Remplissage du tableau de SDL_Rect que l'on remplira ensuite avec du blanc :

    cases[20].x = cases[28].x = 0;
    cases[2].x = cases[6].x = cases[12].x = cases[21].x  = cases[29].x = 100;
    cases[0].x = cases[3].x = cases[7].x = cases[13].x = cases[22].x = cases[30].x = cases[36].x = 200;
    cases[1].x = cases[4].x = cases[8].x = cases[14].x = cases[23].x = cases[31].x = cases[37].x = 300;
    cases[5].x = cases[9].x = cases[15].x = cases[32].x = cases[38].x = cases[42].x = 400;
    cases[10].x = cases[16].x = cases[24].x = cases[33].x = cases[39].x = cases[43].x = cases[46].x = 500;
    cases[11].x = cases[17].x = cases[25].x = cases[34].x = cases[40].x = cases[44].x = cases[47].x = 600;
    cases[18].x = cases[26].x = cases[35].x = cases[41].x = cases[45].x = 700;
    cases[19].x = cases[27].x = 800;

    cases[0].y = cases[1].y = 0;
    cases[2].y = cases[3].y = cases[4].y = cases[5].y = 100;
    cases[6].y = cases[7].y = cases[8].y = cases[9].y = cases[10].y = cases[11].y = 200;
    cases[12].y = cases[13].y = cases[14].y = cases[15].y = cases[16].y = cases[17].y = cases[18].y = cases[19].y = 300;
    cases[20].y = cases[21].y = cases[22].y = cases[23].y = cases[24].y = cases[25].y = cases[26].y = cases[27].y = 400;
    cases[28].y = cases[29].y = cases[30].y = cases[31].y = cases[32].y = cases[33].y = cases[34].y = cases[35].y = 500;
    cases[36].y = cases[37].y = cases[38].y = cases[39].y = cases[40].y = cases[41].y = 600;
    cases[42].y = cases[43].y = cases[44].y = cases[45].y = 700;
    cases[46].y = cases[47].y = 800;

    for(int i = 0; i < 48; i++)
        cases[i].w = cases[i].h = 100; //taille d'une case : 100 x 100
    


    if(SDL_RenderFillRects(game_display->renderer, cases, 48) <0)//Remplissage des cases blanches
    {
        printf("Erreur lors des remplissages de rectangles: %s",SDL_GetError());
        return -1;
    }

// À présent, occupons nous des lignes
// On ne peut pas utiliser la fonction SDL_RenderDrawLines
// car celle-ci ne permet pas de créer des lignes indépendantes comme nous voulons le faire mais des chemins

    SDL_SetRenderDrawColor(game_display->renderer, 255, 0 , 0 , 255);//Couleur rouge

// Lignes horizontales
    ligne_depart.x = 0;
    ligne_arrivee.x = 800;
    ligne_depart.y = 0;
    for(int i = 0; i!=8; i++)
    {
        ligne_depart.y += 100;
        ligne_arrivee.y = ligne_depart.y;
        SDL_RenderDrawLine(game_display->renderer,ligne_depart.x, ligne_depart.y,ligne_arrivee.x,ligne_arrivee.y);
    }

// Lignes verticales
    ligne_depart.x = 0;
    ligne_depart.y = 0;
    ligne_arrivee.y = 1000;
    for(int i = 0; i < 10; i++)
    {
        ligne_depart.x += 100;
        ligne_arrivee.x = ligne_depart.x;
        SDL_RenderDrawLine(game_display->renderer,ligne_depart.x, ligne_depart.y,ligne_arrivee.x,ligne_arrivee.y);
    }

// Toujours penser au rendu, sinon on n'obtient rien du tout
    SDL_RenderPresent(game_display->renderer);
}*/

    #endif
