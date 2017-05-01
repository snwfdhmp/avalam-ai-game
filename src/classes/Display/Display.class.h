#ifndef DISPLAY_CPP
#define DISPLAY_CPP

#include <string>
#include "../GraphicComponent/GraphicComponent.class.h"
#include "../../config/constants.h"

class Display
{
public:
	GraphicComponent** components;
	int x, y, width, height;
	unsigned int size;

	Display(int set_x, int set_y, int set_width, int set_height);
	
	~Display();

	Display* initWindow();

	int update();

	Display* updateWindow();
	
	GraphicComponent* addComponent(GraphicComponent* componentToAdd);

	GraphicComponent* getTargeted(int mouse_x, int mouse_y);

	std::string* inputString(std::string question);
	int* inputNumber(std::string question);
	void* input(std::string question, int type);

	int printGridToConsole(Emplacement grille[TAILLE][TAILLE]);

};
#endif