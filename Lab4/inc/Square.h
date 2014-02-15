
// Adapted by Matthew Bender
// 02/14/14

#ifndef Square_H
#define Square_H

#include "Figure.h"
#include <iostream>
using namespace std;

class Square: public Figure{
    public:
        Square(int);
        void draw(void);
        ~Square(){}; 
};

#endif
