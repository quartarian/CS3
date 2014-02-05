#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main (int argc, char* argv[]) {
  if(argc == 1 || argc == 2 || argc == 3) {
    cout << "You are missing an argument and now I'm confused." << endl;
  }
  else if(argc > 4) {
    cout << "You have provided too many arguments." << endl;
  }
  //Test int conversion
  else if(!atoi(argv[1])) {
    cout << "The first argument should be an integer." << endl;
  }
  else if(argc == 4) {
    // Open Files
    ifstream fileLeft  (argv[2]);
    ofstream fileRight (argv[3]);
    
    if(!fileLeft.is_open()) {
      cout << "Unable to open " << argv[2] << endl;
    } 
    if(!fileRight.is_open()) {
      cout << "Unable to open " << argv[3] << endl;
    }
    
    if (fileLeft.is_open() && fileLeft.is_open()) {
      string fileLeftLine;
      
      //Loop Through File
      while (getline (fileLeft,fileLeftLine)) {
        for(int i = 0; i < fileLeftLine.size(); i++) {
          fileRight << static_cast<char>(fileLeftLine[i] + atoi(argv[1]));
        }
        fileRight << "\n" << endl;
      }
      // Close Files
      fileLeft.close();
      fileRight.close();
    }
  }
  return 0;
}
