// Matthew Bender

#include "../inc/Figure.h"
#include "../inc/Square.h"
#include "../inc/Triangle.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void clearscreen(int lines) {
    for(int i = 0; i < lines; ++i) {
        cout << endl;
    }
}
int stringToInt(string number){
    int size;
    //Convert Size Argument to int.
    istringstream (number) >> size;
    return size;
}
int main (int argc, char* argv[]) {
    // Keep track of object we are working with.
    Figure * currentShape = NULL;

    //Initial clear
    clearscreen(20);

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
        if(word[0] == "clear" && word[1] == "screen") {
            clearscreen(20);
        }
        else if(word[0] == "draw" || word[0] == "d") {
            int size = stringToInt(word[2]);
            if(size >= 20) {
                cout << "BZZZ. Too big" << endl;
            }
            else {
                if(word[1] == "square" || word[1] == "s") {
                    currentShape = new Square(size);
                }
                else if(word[1] == "triangle" || word[1] == "t") {
                    currentShape = new Triangle(size);
                }
               
                currentShape->draw();
            }
        }
        else if(word[0] == "center") {
            if(word[1] == "vertical" || word[1] == "v") {
                currentShape->centerVertical();
            }
            else {
                currentShape->centerHorizontal();
            }

        } 
        else if(word[0] == "move") {
            // Stop if error in X so we see message
            if(currentShape->setOriginX(stringToInt(word[1]))) {
                currentShape->setOriginY(stringToInt(word[2]));
            }
        }
        else {
            cout << "Command not recognized." << endl;
        }
    } 

    return 0;
}
