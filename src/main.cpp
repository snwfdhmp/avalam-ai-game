#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classes/Emplacement/Emplacement.class.h"
#include "classes/Mouvement/Mouvement.class.h"
#include "classes/Player/Player.class.h"
#include "classes/Window/Window.class.h"
#include "config/macros.h"
#include "config/constants.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#define TAILLE 9
#undef main

using namespace std;

int createCredits(Window* window);
int createGame(int type1 , int type2);
int createMenu();
int createRules(Window* window);
void initGrille(Emplacement grille[TAILLE][TAILLE]);
bool isOver(Emplacement grille[TAILLE][TAILLE]);
GraphicComponent* loadImage(Display *display, char *path, int x, int y);
void printWinner(Display* game, char* path);

GraphicComponent* loadImage(Display *display, char *path, int x = 0, int y = 0){
    GraphicComponent* gc_over = new GraphicComponent(display->renderer, path);
    SDL_Rect position;
    position.x = x;
    position.y = y;
    position.w = gc_over->width;
    position.h = gc_over->height;
   SDL_RenderCopy(display->renderer, gc_over->texture, NULL, &position);
    SDL_RenderPresent(display->renderer);

    return gc_over;
}

void printWinner(Display* game, char* path){
    SDL_Surface* gameSurf = SDL_LoadBMP(path);
    SDL_Texture* gameText = SDL_CreateTextureFromSurface(game->renderer, gameSurf);
    SDL_Rect position;
    position.x = 270;
    position.y = 300;
    position.w = gameSurf->w;
    position.h = gameSurf->h;

    SDL_RenderCopy(game->renderer, gameText, NULL, &position);
    SDL_RenderPresent(game->renderer);
}

void initGrille(Emplacement grille[TAILLE][TAILLE]){
  int i,j;

  for (i = 0; i < TAILLE; ++i)
    for (j = 0; j < TAILLE; ++j) {
      grille[i][j].init(j%2);
    }
}

int createMenu(){

  bool launch = false;
  SDL_Event event;

  Window* window = new Window("Avalam by Joly and Monga", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 561, SDL_WINDOW_SHOWN); //Window init
  window->setIcon("ressources/img/chess.bmp"); //Icon init
  
  Display* menu = new Display(window);
  
  SDL_Surface* menuSurf = SDL_LoadBMP("ressources/img/menu.bmp");
  SDL_Texture* menuText = SDL_CreateTextureFromSurface(menu->renderer, menuSurf);
  SDL_Rect position;
  position.x = 0;
  position.y = 0;
  position.w = menuSurf->w;
  position.h = menuSurf->h;
  
  SDL_RenderCopy(menu->renderer, menuText, NULL, &position);
  SDL_RenderPresent(menu->renderer);
  
  while(!launch){
    SDL_WaitEvent(&event);
    
    switch(event.type){

      case SDL_MOUSEMOTION :

        if((event.motion.x >= 200 && event.motion.x <= 500) && event.motion.y >= 130 && event.motion.y <= 545){
              loadImage(menu, "ressources/img/jouer-over.bmp");
        }
        else if((event.motion.x >= 510 && event.motion.x <= 806) && event.motion.y >= 125 && event.motion.y <= 310){
              loadImage(menu, "ressources/img/options-over.bmp");
        }
        else if((event.motion.x >= 510 && event.motion.x <= 806) && event.motion.y >= 320 && event.motion.y <= 420){
              loadImage(menu, "ressources/img/themes-over.bmp");
        }
        else if((event.motion.x >= 510 && event.motion.x <= 806) && event.motion.y >= 435 && event.motion.y <= 480){
              loadImage(menu, "ressources/img/rules-over.bmp");
        }
        else if((event.motion.x >= 510 && event.motion.x <= 806) && event.motion.y >= 490 && event.motion.y <= 535){
              loadImage(menu, "ressources/img/about-over.bmp");
        }
        else loadImage(menu, "ressources/img/menu.bmp");
        break;

            case SDL_MOUSEBUTTONUP :
               if((event.motion.x >= 200 && event.motion.x <= 500) && (event.motion.y >= 130 && event.motion.y <= 260)){
                  launch = true;
                  window->destroyWindow();
                  createGame(PLAYER_TYPE_HUMAN, PLAYER_TYPE_HUMAN);
            }
             if((event.motion.x >= 200 && event.motion.x <= 500) && (event.motion.y >= 270 && event.motion.y <= 400)){
                  launch = true;
                  window->destroyWindow();
                  createGame(PLAYER_TYPE_HUMAN, PLAYER_TYPE_IA);
              }
              if((event.motion.x >= 200 && event.motion.x <= 500) && (event.motion.y >= 410 && event.motion.y <= 545)){
                  launch = true;
                  window->destroyWindow();
                  createGame(PLAYER_TYPE_IA, PLAYER_TYPE_IA);
            }
            if((event.motion.x >= 515 && event.motion.x <= 815) && (event.motion.y >= 445 && event.motion.y <= 495)){
                  launch = true;
                  menu->destroyRenderer();
                  createRules(window);
            }
            if((event.motion.x >= 510 && event.motion.x <= 806) && (event.motion.y >= 490 && event.motion.y <= 535)){
              launch = true;
              menu->destroyRenderer();
              createCredits(window);
            }
            break;

           case SDL_QUIT : 
                window->destroyWindow();
                SDL_Quit();
          break;
        }
  }
}

int createGame(int type1, int type2){

  Window* window = new Window("Avalam by Joly and Monga", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1012, 800, SDL_WINDOW_SHOWN); //Window init
  window->setIcon("ressources/img/chess.bmp"); //Icon init

  Display* game = new Display(window);
  SDL_Event event;
  bool leave = false;
  
  //Initialistion des joueurs
  Player* player1 = new Player();
  player1->init(game, 0, "Martin", type1);
  Player* player2 = new Player();
  player2->init(game, 1, "Landry", type2);
  Emplacement grille[TAILLE][TAILLE];

  initGrille(grille);
  APPLY_DEFAULT_EMPTY(grille);
  game->printGrille(grille);

  if(type1 == PLAYER_TYPE_IA && type2 == PLAYER_TYPE_IA){
    while(isOver(grille) == false){
      SDL_Delay(1500);
      while(player1->evaluate(grille) == -1);
      game->printGrille(grille);
      SDL_Delay(1500);
      while(player2->evaluate(grille) == -1);
      game->printGrille(grille);
      switch(event.type){
         case SDL_QUIT : 
                window->destroyWindow();
                SDL_Quit();
          break;
      }
    }
  }

  else if(type1 == PLAYER_TYPE_HUMAN && type2 == PLAYER_TYPE_IA){
    while(isOver(grille) == false){
      while(player1->evaluate(grille) == -1);
      game->printGrille(grille);
      SDL_Delay(900);
      while(player2->evaluate(grille) == -1);
      game->printGrille(grille);
      switch(event.type){
         case SDL_QUIT : 
                window->destroyWindow();
                SDL_Quit();
          break;
      }
  }
}

else if(type1 == PLAYER_TYPE_HUMAN && type2 == PLAYER_TYPE_HUMAN){
   while(isOver(grille) == false){
      while(player1->evaluate(grille) == -1);
      game->printGrille(grille);
      while(player2->evaluate(grille) == -1);
      game->printGrille(grille);
      switch(event.type){
         case SDL_QUIT : 
                window->destroyWindow();
                SDL_Quit();
          break;
      }
  }
}

  printf("FIN DU JEU!!\n");
  int score1 = player1->getScore(grille);
  int score2 = player2->getScore(grille);
  printf("Le joueur 1 a fait %d et le joueur 2 a fait %d\n", score1, score2);

  if(score1 > score2){
    printWinner(game, "ressources/img/redwon.bmp");
  }

  if(score2 > score1){
    printWinner(game, "ressources/img/yellowon.bmp");
  }

  if(score1 == score2){
    printWinner(game, "ressources/img/egalite.bmp");
  }
  
  while(leave == false){
    SDL_WaitEvent(&event);
    switch(event.type){
        case SDL_MOUSEBUTTONUP : 
          if(event.motion.x >= 370 && event.motion.x <= 640 && event.motion.y <= 385 && event.motion.y <= 480){
            leave = true;
            window->destroyWindow();
            createMenu();
          }
          break;

          case SDL_QUIT : 
                window->destroyWindow();
                SDL_Quit();
          break;
   }
  }
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

int createRules(Window* window){
  Display* display = new Display(window);
  SDL_Event event;
  int num = 1;
  char rules[7];

  sprintf(rules, "ressources/img/rules%d.bmp", num);
  GraphicComponent* page =  loadImage(display, rules);
  
  while(num < 7){
    SDL_WaitEvent(&event);
    if(event.type == SDL_KEYDOWN){
      page->destroyTexture();
      page->destroySurface();

      if(event.key.keysym.sym == SDLK_LEFT){
        num--;
        if(num <= 0)
          num = 0;
        sprintf(rules, "ressources/img/rules%d.bmp", num);
        GraphicComponent* page =  loadImage(display, rules);
      }

      if(event.key.keysym.sym == SDLK_RIGHT){
          num++;
          if(num >= 6)
          num = 6;
        sprintf(rules, "ressources/img/rules%d.bmp", num);
        GraphicComponent* page =  loadImage(display, rules);
      }
      if(event.key.keysym.sym == SDLK_ESCAPE){
        window->destroyWindow();
        createMenu();
      }
    }
  }
}

int createCredits(Window* window){
  SDL_Event event;
  Display* credits = new Display(window);
  loadImage(credits, "ressources/img/credits.bmp");
  bool leave = false;

  while(!leave){

    SDL_WaitEvent(&event);

    switch(event.type){
      case SDL_MOUSEBUTTONUP :
        if(event.motion.x < 120 && event.motion.y >= 460 && event.motion.y <= 580){
          leave = true;
          credits->destroyRenderer();
          window->destroyWindow();
          createMenu();
          break;
        }
    }
  }
}
  
int main(int argc, char const *argv[])
{
  Window* intro = new Window("  Welcome in Avalam by Joly and Monga", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1243, 700, SDL_WINDOW_SHOWN);
  intro->setIcon("ressources/img/chess.bmp");

  Display* introDisp = new Display(intro);
  GraphicComponent* menuImage =  loadImage(introDisp, "ressources/img/intro.bmp");
  SDL_Delay(4500);
  
  //Liberation de la memoire alloué
  menuImage->destroySurface();
  menuImage->destroyTexture();
  introDisp->destroyRenderer();
  intro->destroyWindow();

  createMenu();
  
	return 0;
}