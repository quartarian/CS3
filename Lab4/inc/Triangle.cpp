// Adapated by Matt Bender
// 02/14/14
//
#include "Triangle.h"

Triangle::Triangle(int size): Figure(size){}

void Triangle::draw(void){

    //Draw Pre Buffer
    for(int i=0; i < yorigin_; i++) {
        cout << endl;
    }

  for(int i=0; i < size_; ++i){
    for(int j=0; j < xorigin_; ++j)
      cout << ' ';
    for(int j=0; j < size_; ++j)
      if(j <= i) cout << '*';
    cout << endl;
  }

    //Draw Post Buffer
    for(int i=0; i < (SCREEN_HEIGHT - yorigin_ - size_ - 1); i++) {

        cout << endl;
    }

}
