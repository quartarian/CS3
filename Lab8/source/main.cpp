// Adapted by Matt Bender
// 02/21/14
#include "Fill.h"
#include "Figures.h"
#include "Factory.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

int stringToInt(string number){
    int size;
    //Convert Size Argument to int.
    istringstream (number) >> size;
    return size;
}

int main(void){
    Figure * figure = NULL;
    for(int i = 0; i < 65; i++) {
        cout << endl;
    }
    cout << "===========================================================================" << endl;
    cout << "Please use this format: \n\t{Square | Triangle} {integer > 0} {Hollow | Filled} {character}" << endl;
    cout << "For Example: \n\tTriangle 10 Hollow *" << endl;
    cout << "Use 'exit' to terminate the program." << endl;
    cout << "===========================================================================" << endl;
    cout << endl;

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
        if(word[0] == "exit") {
            exit(0);
        }
        if( (word[0] == "Square" || word[0] == "Triangle") 
                && size >=0 && size != NULL 
                &&(word[2] == "Hollow" || word[2] == "Filled") 
                && word[3].size() == 1) 
        {
            if( word[0] == "Square" ) {
                Factory<Square> factory;
                figure = factory.generateFigure(size, word[2],word[3][0]);
            }
            else if (word[0] == "Triangle") {
                Factory<Triangle> factory;
                figure = factory.generateFigure(size, word[2],word[3][0]);
            }
            figure->draw();
        }
        else {
            cout << "Incorrect entry. Please use this format: {Square | Triangle} {integer > 0} {Hollow | Filled} {character}" << endl;       
        }

    }
}
