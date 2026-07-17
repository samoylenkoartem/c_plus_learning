#pragma once
#include "figure.h"
class Arc : virtual public Figure {
protected:
	float rad, start, end;
public:
	Arc(float _r, float _g, float _b, float _pointX, float _pointY, float _rad, float _start, float _end) :
		Figure(_r, _g, _b, _pointX, _pointY), rad(_rad), start(_start), end(_end) {
		draw();
	}
	~Arc() {
		erase();  
	}
	void draw() {
		draw_arc(pointX, pointY, rad, start, end, r, g, b);
	}
	void erase() {
		draw_arc(pointX, pointY, rad, start,end, 0, 0, 0);
	}
};
