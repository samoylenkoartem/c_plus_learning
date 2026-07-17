#pragma once
#include "line.h"
#include "arc.h"

class Sector : public Line<1>, public Arc, public Line<2> {
public:
    Sector(float _r, float _g, float _b, float _pointX, float _pointY,
        float _rad, float _start, float _end)
        : Figure(_r, _g, _b, _pointX, _pointY)
        , Line<1>(_r, _g, _b, _pointX, _pointY, _pointX, _pointY, _pointX + _rad * cos(_start * PI / 180.0), 
            _pointY + _rad * sin(_start * PI / 180.0))
        , Line<2>(_r, _g, _b, _pointX, _pointY, _pointX, _pointY, _pointX + _rad * cos(_end * PI / 180.0), 
            _pointY + _rad * sin(_end * PI / 180.0))
        , Arc(_r, _g, _b, _pointX, _pointY, _rad, _start, _end){
        draw();
    }

    ~Sector() {
        erase();
    }

    void draw() {
        Arc::draw();
        Line<1>::draw();
        Line<2>::draw();
    }

    void erase() {
        Arc::erase();
        Line<1>::erase();
        Line<2>::erase();
    }
};