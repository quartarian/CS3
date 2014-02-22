// Adapted by Matt Bender
// 02/21/14

#include"Figures.h"
#include<iostream>

using namespace std;

void Square::draw(void){
    for(int i=0; i < size_; ++i){
        for(int j=0; j < size_; ++j)
            if(i==0 || j==0 || i==size_-1 || j==size_-1 )
                cout << fill_ -> getBorder();
            else
                cout << fill_ -> getInternal();
        cout << endl;
    }
}

void Triangle::draw(void){
    for(int i=0; i < size_; ++i){
        for(int j=0; j < size_; ++j) {
            if (j == i || j == 0 || i == size_-1){
                cout << fill_ ->getBorder();
            }
            else if(i == -1) {
                cout << fill_ ->getBorder();
            }
            else if(j < i) {
                cout << fill_ ->getInternal();
            }

        }
        cout << endl;
    }
}

