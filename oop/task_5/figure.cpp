#include "figure.h"

Figure::Figure(float _r, float _g, float _b, float _pointX, float _pointY)
    : r(_r), g(_g), b(_b), pointX(_pointX), pointY(_pointY) {
}

Figure::~Figure() {
}
void Figure::move(float _pointX, float _pointY) {
	erase();
	pointX = _pointX;
	pointY = _pointY;
	draw();
}
void Figure::setColor(float _r, float _g, float _b) {
	erase();
	r = _r;
	g = _g;
	b = _b;
	draw();
}