// Adapted by Matt Bender
// 02/21/14

#ifndef Factory_H
#define Factory_H

#include<string>
#include"Figures.h"


using namespace std;
template <typename Figure>
class Factory {
    public:
        Figure* generateFigure(int size, string fillType, char character = '*');
};

template <typename Figure>
Figure* Factory<Figure>::generateFigure(int size, string fillType, char character) {
    Fill *fill;

    if(fillType == "Hollow") {
        fill = new Hollow(character);
    }
    else {
        fill = new Filled(character);
    }

    return new Figure(size, fill);
}

#endif
