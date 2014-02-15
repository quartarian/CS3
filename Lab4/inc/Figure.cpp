// Adapated by Matt Bender
// 02/14/14
//
#include "Figure.h"
#include <iostream>

using namespace std;

Figure::Figure(int size, int xorigin, int yorigin): size_(size), xorigin_(xorigin), yorigin_(yorigin){}

void Figure::alignLeft(void){
    xorigin_=0; 
    draw();
}
void Figure::alignRight(void){
    xorigin_=SCREEN_WIDTH-size_; 
    draw();
}
void Figure::centerHorizontal(void){
    xorigin_=(SCREEN_WIDTH-size_)/2; 
    draw();
}
void Figure::centerVertical(void){
    yorigin_=(SCREEN_HEIGHT-size_)/2; 
    draw();
}

bool Figure::setOriginX(int xorigin){
    if(xorigin + size_ < SCREEN_WIDTH && xorigin >= 0) {
        xorigin_ = xorigin; 
        draw();
        return 1;
    }
    else {
        cout << "BZZZ. Out of bounds." << endl;
        return 0;
    }
}
bool Figure::setOriginY(int yorigin){
    if(yorigin + size_ < SCREEN_HEIGHT && yorigin >= 0) { 
        yorigin_ = yorigin; 
        draw();
        return 1;
    }
    else {
        cout << "BUZZ. Out of bounds." << endl;
        return 0;
    }

}


