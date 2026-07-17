#pragma once
#include "graphlib.h"
#include <cmath>

constexpr float PI = 3.14;

class Figure {
protected:
	float r, g, b;
	float pointX, pointY;
public:
	Figure(float _r, float _g, float _b, float _pointX, float _pointY);

	virtual ~Figure();

	virtual void draw() = 0;

	virtual void erase() = 0;

	void move(float _pointX, float _pointY);

	void setColor(float _r, float _g, float _b);
};


