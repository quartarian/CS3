// Adapted by Matt Bender
// 02/21/14
#include "Fill.h"
#include "Figures.h"
#include "Factory.h"
#include <iostream>
#include <sstream>

using namespace std;

int stringToInt(string number){
    int size;
    //Convert Size Argument to int.
    istringstream (number) >> size;
    return size;
}

int main(void){
    Factory figureFactory;
    Figure * figure = NULL;
    cout << "===========================================================================" << endl;
    cout << "Please use this format: \n\t{Square | Triangle} {integer > 0} {Hollow | Filled} {character}" << endl;
    cout << "For Example: \n\tTriangle 10 Hollow *" << endl;
    cout << "===========================================================================" << endl;

    while(true) {
        string command = "";

        cout << "prompt: ";
        getline(cin,command);

        stringstream stream(command);
        string word[4];
        int i = 0;
        // Parse command to an array of words
        while(stream >> word[i]) {
            i++;
        }
        int size = stringToInt(word[1]);
        if( (word[0] == "Square" || word[0] == "Triangle") 
                && size >=0 && size != NULL 
                &&(word[2] == "Hollow" || word[2] == "Filled") 
                && word[3].size() == 1) 
        {
            //Delete Object if set
            if(figure != NULL) {
                delete figure;
            }
            figure = figureFactory.generateFigure(word[0], size, word[2],word[3][0]);
            figure->draw();
        }
        else {
            cout << "Incorrect entry. Please use this format: {Square | Triangle} {integer > 0} {Hollow | Filled} {character}" << endl;       
        }

    }
}
