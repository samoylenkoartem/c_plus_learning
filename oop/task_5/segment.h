#pragma once
#include "line.h"
#include "arc.h"

class Segment : public Line<3>, public Arc {
public:
    Segment(float _r, float _g, float _b, float _pointX, float _pointY,
        float _rad, float _start, float _end)
        : Figure(_r, _g, _b, _pointX, _pointY)
        , Line<3>(_r, _g, _b, _pointX, _pointY,
            _pointX + _rad * cos(_start * PI / 180.0),
            _pointY + _rad * sin(_start * PI / 180.0),
            _pointX + _rad * cos(_end * PI / 180.0),
            _pointY + _rad * sin(_end * PI / 180.0))
        , Arc(_r, _g, _b, _pointX, _pointY, _rad, _start, _end) {
        draw();
    }

    ~Segment() {
        erase();
    }

    void draw() {
        Line<3>::draw();
        Arc::draw();
    }
    void erase() {
        Line<3>::erase();
        Arc::erase();
    }
};