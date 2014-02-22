// Adapted by Matt Bender
// 02/21/14

#ifndef Factory_H
#define Factory_H

#include<string>
#include"Figures.h"


using namespace std;

class Factory {
    public:
        Figure* generateFigure(string figureType, int size, string fillType, char character = '*');
};
 
#endif
