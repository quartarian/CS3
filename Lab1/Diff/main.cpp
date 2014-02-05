#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char* argv[]) {
  if(argc == 1) {
    cout << "What files should I Diff?" << endl;
  }
  else if(argc == 2) {
    cout << "What files should I Diff against " << argv[1] << " ?" << endl;
  }
  else if(argc > 3) {
    cout << "You have provided too many arguments." << endl;
  }
  else if(argc == 3) {
    // Open Files
    ifstream fileLeft  (argv[1]);
    ifstream fileRight (argv[2]);
    
    if(!fileLeft.is_open()) {
      cout << "Unable to open " << argv[1] << endl;
    } 
    if(!fileRight.is_open()) {
      cout << "Unable to open " << argv[2] << endl;
    }    
    
    if (fileLeft.is_open() && fileLeft.is_open() ) {
      string fileLeftLine;
      string fileRightLine;
      
      //Loop Untill Manual Exit
      while (true) {
        int exit = 0;
        static int lineNumber = 1;
        if(!getline (fileLeft,fileLeftLine)) {
          ++exit;
        }
        if(!getline (fileRight,fileRightLine)) {
          ++exit;
        }
        //Body of While Loop
        if(fileLeftLine != fileRightLine) {
          cout << argv[1] << ": " << lineNumber << ": " << fileLeftLine << endl;
          cout << argv[2] << ": " << lineNumber << ": " << fileRightLine << endl;
        }
        
        // Exit if both files are done
        if(exit == 2) {
          break;
        }
        ++lineNumber;
      }
      // Close Files
      fileLeft.close();
      fileRight.close();
    }
  }
  return 0;
}
