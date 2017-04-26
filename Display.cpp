#ifndef DISPLAY_CPP
#define DISPLAY_CPP

#include "GraphicComponent.cpp"

class Display
{
public:
	GraphicComponent** components;
	int x, y, width, height;
	unsigned int size;

	Display(int set_x, int set_y, int set_width, int set_height) {
		components = (GraphicComponent**) malloc(sizeof(GraphicComponent*));
		size = 0;
		x = set_x;
		y = set_y;
		width = set_width;
		height = set_height;

	};
	~Display();
	
	GraphicComponent* addComponent(GraphicComponent* componentToAdd) {
		components = (GraphicComponent**) malloc(sizeof(GraphicComponent) * size + 1);
		components[size] = componentToAdd;
		printf("Component [%d;%d] has been added to display [%d;%d] (%d:%d) [size : %d]\n", components[size]->x, components[size]->y, x, y, width, height, size);
		size++;
		return components[size];
	}

	GraphicComponent* getTargeted(int mouse_x, int mouse_y) {
		if(mouse_x < x || mouse_x > x+width || mouse_y < y || mouse_y > y+height)
			return NULL;
		else
			for (int i = 0; i < size; ++i)
				if(mouse_x < components[i]->x || mouse_x > components[i]->x+components[i]->width || mouse_y < components[i]->y || mouse_y > components[i]->y+components[i]->height)
					continue;
				else
					return components[i];
		return NULL;
	}

};
#endif