#ifndef DISPLAY_CPP
#define DISPLAY_CPP

#include <string>
#include "SDL2/SDL.h"
#include "../GraphicComponent/GraphicComponent.class.h"

class Display
{
public:
	SDL_Renderer *renderer;
	int x, y, width, height;
	unsigned int size;
	GraphicComponent** components;

	Display(int set_x, int set_y, int set_width, int set_height);
	
	~Display();

	Display* initWindow();
	Display* initRenderer(SDL_Window *window);
	Display* destroyRenderer(SDL_Renderer *renderer);
	int update();

	Display* updateWindow();
	
	GraphicComponent* addComponent(GraphicComponent* componentToAdd);

	GraphicComponent* getTargeted(int mouse_x, int mouse_y);

	std::string* inputString(std::string question);
	//int* inputNumber(std::string question);
	void* input(std::string question, int type);

};
#endif