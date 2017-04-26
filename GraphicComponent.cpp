#ifndef GRAPHICCOMPONENT_CPP
#define GRAPHICCOMPONENT_CPP
class GraphicComponent
{
public:
	int x, y;
	int height, width;
	GraphicComponent(int set_x, int set_y, int set_width, int set_height) {
		x = set_x;
		y = set_y;
		width = set_width;
		height = set_height;
	}
	~GraphicComponent();
	
	void onClick() {
		printf("Element at [%d;%d] has fired the onClick() function.\n", x, y);
	}

	void onMouseOver() {
		printf("Element at [%d;%d] has fired the onMouseOver() function.\n", x, y);
	}

	void onMouseOut() {
		printf("Element at [%d;%d] has fired the onMouseOut() function.\n", x, y);
	}
	
};
#endif