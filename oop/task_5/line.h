#pragma once
#include "figure.h"

template <int N>
class Line : virtual public Figure {
protected:
	float X0, Y0;
	float X1, Y1;
public:
	Line(float _r, float _g, float _b, float _pointX, float _pointY, float _x0, float _y0, float _x1, float _y1) :
		Figure(_r, _g, _b, _pointX, _pointY), X0(_x0 - _pointX), Y0(_y0 - _pointY), X1(_x1 - _pointX), Y1(_y1 - _pointY) {
		draw();
	}
	~Line() {
		erase();  
	}
	void draw() {
		draw_line(pointX + X0, pointY + Y0, pointX + X1, pointY + Y1, r, g, b);
	}
	void erase() {

		draw_line(pointX + X0, pointY + Y0, pointX + X1, pointY + Y1, 0, 0, 0);
	}
};
