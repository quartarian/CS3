// Adapted by Matt Bender
// 02/21/14

#include"Factory.h"

using namespace std;

Figure* Factory::generateFigure(string figureType, int size, string fillType, char character) {
    if(figureType == "Square" || figureType == "S" || figureType == "Triangle" || figureType == "T") {
        Fill *fill;

        if(fillType == "Hollow") {
            fill = new Hollow(character);
        }
        else {
            fill = new Filled(character);
        }

        if(figureType == "Square" || figureType == "S") {
            return new Square(size, fill);
        }
        else if (figureType == "Triangle" || figureType == "T") {
             return new Triangle(size, fill);           
        }
    }
}

