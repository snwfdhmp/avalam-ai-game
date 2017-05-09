#ifndef BUTON_H
#define BUTON_H

class Bouton : public GraphicComponent
{
public:
	Bouton(char* kind, int w, int h);
	~Bouton();

	int width, height;
	char* type 
	void onClick();
};

#endif