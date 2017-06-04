#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "classes/Emplacement/Emplacement.class.h"
#include "classes/Mouvement/Mouvement.class.h"
#include "classes/Player/Player.class.h"
#include "classes/Window/Window.class.h"
#include "config/macros.h"
#include "config/constants.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "classes/GameInstance/GameInstance.class.h"
#define TAILLE 9
#undef main

using namespace std;

int createGame(int type1 , int type2);
int createMenu();
void gameEvents(Window*, Display*);
void initGrille(Emplacement grille[TAILLE][TAILLE]);
bool isOver(Emplacement grille[TAILLE][TAILLE]);
void onMouseOver(Display *, char*);



void onMouseOver(Display *display, char *path){
    GraphicComponent* gc_over = new GraphicComponent(display->renderer, path);
    SDL_Rect position = {0, 0, gc_over->width, gc_over->height};
    SDL_RenderCopy(display->renderer, gc_over->texture, NULL, &position);
    SDL_RenderPresent(display->renderer);
}

/*int loadMusic(){
  Mix_Music *music;
  music = Mix_LoadMUS("ressources/musics/name.wav");

if(music != NULL){ 
  Mix_PlayMusic(music, -1);
  return 0;
}
  
  return -1;
} */

void initGrille(Emplacement grille[TAILLE][TAILLE]){
  int i,j;
  for (i = 0; i < TAILLE; ++i)
    for (j = 0; j < TAILLE; ++j) {
      grille[i][j].init(j%2);
    }
}

int createMenu(){

  int continuer = 1;
  SDL_Event event;
  Window* window = new Window("Avalam by Joly and Monga", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 561, SDL_WINDOW_SHOWN); //Window init
  window->setIcon("ressources/img/chess.bmp"); //Icon init
  
  Display* menu = new Display(window);
  
  SDL_Surface* menuSurf = SDL_LoadBMP("ressources/img/menu.bmp");
  SDL_Texture* menuText = SDL_CreateTextureFromSurface(menu->renderer, menuSurf);
  SDL_Rect position = {0, 0, menuSurf->w, menuSurf->h};
  
  SDL_RenderCopy(menu->renderer, menuText, NULL, &position);
  SDL_RenderPresent(menu->renderer);
  
  while(continuer){
    SDL_WaitEvent(&event);
    
    switch(event.type){

      case SDL_MOUSEMOTION : 
        if((event.motion.x >= 200 && event.motion.x <= 500) && event.motion.y >= 130 && event.motion.y <= 545){
              onMouseOver(menu, "ressources/img/jouer-over.bmp");
            }
            else if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 135 && event.motion.y <= 315){
              onMouseOver(menu, "ressources/img/options-over.bmp");
            }
            else if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 330 && event.motion.y <= 435){
              onMouseOver(menu, "ressources/img/themes-over.bmp");
            }
            else if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 445 && event.motion.y <= 495){
              onMouseOver(menu, "ressources/img/rules-over.bmp");
            }
            else if((event.motion.x >= 515 && event.motion.x <= 815) && event.motion.y >= 505 && event.motion.y <= 550){
              onMouseOver(menu, "ressources/img/about-over.bmp");
            }
            else onMouseOver(menu, "ressources/img/menu.bmp");
            break;

            case SDL_MOUSEBUTTONUP :
               if((event.motion.x >= 200 && event.motion.x <= 500) && event.motion.y >= 130 && event.motion.y <= 260){
                  continuer = 0;
                  window->destroyWindow();
                  createGame(PLAYER_TYPE_HUMAN, PLAYER_TYPE_HUMAN);
            }
             if((event.motion.x >= 200 && event.motion.x <= 500) && event.motion.y >= 270 && event.motion.y <= 400){
                  continuer = 0;
                  window->destroyWindow();
                  createGame(PLAYER_TYPE_HUMAN, PLAYER_TYPE_IA);
              }
              if((event.motion.x >= 200 && event.motion.x <= 500) && event.motion.y >= 410 && event.motion.y <= 545){
                  continuer = 0;
                  window->destroyWindow();
                  createGame(PLAYER_TYPE_IA, PLAYER_TYPE_IA);
            }
      }
  }
}

int createGame(int type1, int type2){

  Window* window = new Window("Avalam by Joly and Monga", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1012, 800, SDL_WINDOW_SHOWN); //Window init
  window->setIcon("ressources/img/chess.bmp"); //Icon init

  Display* game = new Display(window);
  //Initialistion des joueurs
  Player* player1 = new Player();
  player1->init(game, 0, "Martin", type1);
  Player* player2 = new Player();
  player2->init(game, 1, "Landry", type2);
  Emplacement grille[TAILLE][TAILLE];

  initGrille(grille);
  APPLY_DEFAULT_EMPTY(grille);
  game->printGrille(grille);

  while(isOver(grille) == false){
    gameEvents(window, game);
    while(player1->evaluate(grille) == -1);
    game->printGrille(grille);
    SDL_Delay(900);
    while(player2->evaluate(grille) == -1);
    game->printGrille(grille);
  }

  printf("FIN DU JEU!!\n");
  int score1 = player1->getScore(grille);
  int score2 = player2->getScore(grille);
  printf("Le joueur 1 a fait %d et le joueur 2 a fait %d\n", score1, score2);
  window->destroyWindow();
  createMenu();
}

bool isOver(Emplacement grille[TAILLE][TAILLE]){
Mouvement tmp;
int x,y,k,l;
  for (x = 0; x < TAILLE; ++x)
    for (y = 0; y < TAILLE; ++y)
      if(grille[x][y].valeur == 2)
        continue;
      else
        for (k = -1; k <= 1; ++k)
          for (l = -1; l <= 1; ++l)
            if(tmp.init(x, y, x+l, y+k, grille) != -1)
              return false;

return true;
}

void gameEvents(Window* window, Display* menu){
  int continuer = 1;
    SDL_Event event;
      
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            //Si il appuie sur la croix on ferme
            case SDL_QUIT:
                printf("Quitter\n");
                window->destroyWindow();
                SDL_Quit(); 
                break;
            
            case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                //SI on appuie sur echap ou q on save et on quitte..
                case SDLK_ESCAPE: 
                    //save();
                    printf("Quitter\n");
                    window->destroyWindow();
                    SDL_Quit(); 
                    continuer = 0;
                    break;
                case SDLK_q : 
                  //save();
                  printf("Quitter\n");
                  window->destroyWindow();
                  SDL_Quit(); 
                  break;
            }
            break;
        }
 }
  
int main(int argc, char const *argv[])
{
  //Creation de la fenetre
  createMenu();
  //createGame();
 
	return 0;
}