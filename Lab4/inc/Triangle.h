
// Adapted by Matthew Bender
// 02/14/14

#ifndef Triangle_H 
#define  Triangle_H

#include "Figure.h"
#include <iostream>
using namespace std;

class Triangle: public Figure{
    public:
        Triangle(int);
        void draw(void);
        ~Triangle(){};
};

#endif
