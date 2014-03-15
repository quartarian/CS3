// Adapted by Matt Bender
// 02/21/14

#ifndef Figures_H
#define Figures_H

#include"Fill.h"
using namespace std;

// abstract handle
class Figure {
public:
   Figure(int size, Fill* fill): size_(size), fill_(fill){}
   virtual void draw() =0;
   virtual ~Figure(){}
protected:
   int size_;
   Fill *fill_;
};
 
// concrete handle
class Square: public Figure{
public:
   Square(int size, Fill* fill): Figure(size, fill){}
   void draw(void);
   ~Square(){}
};


class Triangle: public Figure{
public:
   Triangle(int size, Fill* fill): Figure(size, fill){}
   void draw(void);
   ~Triangle(){}
};




#endif
