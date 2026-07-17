#include "graphlib.h"
#include "figure.h"
#include "line.h"
#include "arc.h"
#include "segment.h"
#include "sector.h"
#include <iostream>
#include <typeinfo>

const int length = 10;

void addFigure(Figure* figures[], int& count, Figure* fig) {
    if (fig && count < length) {
        figures[count++] = fig;
    }
}

void removeFigure(Figure* figures[], int& count, Figure* fig) {
    for (int i = 0; i < count; i++) {
        if (figures[i] == fig) {
            for (int j = i; j < count - 1; j++) {
                figures[j] = figures[j + 1];
            }
            count--;
            break;
        }
    }
}

void Main() {
    Figure* figures[length] = { nullptr };
    int figureCount = 0;

    Segment* newSegment = new Segment(0, 0, 1, 300, 300, 150, 0, 180);

    Sector* newSector = new Sector(1, 1, 0, 300, 600, 200, 45, 135);

    addFigure(figures, figureCount, newSegment);
    addFigure(figures, figureCount, newSector);

    Segment* segmentCheck = dynamic_cast<Segment*>(newSector);
    if (segmentCheck != nullptr) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }

    try {
        Segment& segmentCheck = dynamic_cast<Segment&>(*newSegment);
        std::cout << "True" << std::endl;
    }
    catch (std::bad_cast&) {
        std::cout << "False" << std::endl;
    }

    wait4keyORmouse();

    newSegment->setColor(1, 0.5, 0);
    newSegment->move(700, 300);

    newSector->setColor(1, 0, 1);
    newSector->move(700, 600);

    wait4keyORmouse();

    newSegment->setColor(1, 0.5, 0.5);
    newSegment->move(1200, 300);

    newSector->setColor(1, 0.5, 1);
    newSector->move(1200, 600);
 
    wait4keyORmouse();

    removeFigure(figures, figureCount, newSegment);
    removeFigure(figures, figureCount, newSector);

    delete newSegment;
    delete newSector;

    wait4keyORmouse();
}   
