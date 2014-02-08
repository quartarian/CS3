// Matthew Bender

#include "../inc/SingletonSchedule.h"
#include <iostream>
#include <string> 
#include <fstream>

using namespace std;

int main (int argc, char* argv[]) {
  if(argc == 1) {
    cout << "Please select a file." << endl;
  }
  else {
      //Open File
      ifstream fileInput(argv[1]);
      
      if(!fileInput.is_open()) {
        cout << "Unable to open " << argv[1] << endl;
      }
      else {
        cout << argv[1] << " opened." << endl;

        string fileLine;    
        while (getline (fileInput,fileLine)) {
            int wordnumber = 0;
            string word, time, name;
            for(int i = 0; i < fileLine.size(); i++) {
                if(wordnumber < 1 && (fileLine[i] == ' ' || fileLine[i] == '\t')) {
                    wordnumber++;
                }
                else if(wordnumber == 0) {
                    time += fileLine[i];
                }               
                else if(!(fileLine[i] == ' ' || fileLine[i] == '\t')) {
                    name += fileLine[i];
                }
            }
            SingletonSchedule::instance()->addRequest(time,name);
        }

        SingletonSchedule::instance()->printSchedule();

        // Close File
        fileInput.close();
      }
  }
  
  return 0;
}
