/*
 * Author: Matt Bender
 * Date:   01/31/14
 * 
 */ 


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "../inc/WordOccurrence.h"
#include "../inc/WordList.h"

using namespace std;

int main (int argc, char* argv[]) {
  if(argc == 1) {
    cout << "Please select a file." << endl;
  }
  
  //Open File
  ifstream fileInput  (argv[1]);
  
  if(!fileInput.is_open()) {
    cout << "Unable to open " << argv[1] << endl;
  }
  else {
    string word;
    WordList wordList = wordList();
    while(fileInput >> word) {
      if( word[word.size()-1] == ',' ||
          word[word.size()-1] == '!' ||
          word[word.size()-1] == '.' ||
          word[word.size()-1] == ';' ||
          word[word.size()-1] == ':' ||
          word[word.size()-1] == '?' ||
          word[word.size()-1] == '-' ||
          word[word.size()-1] == '+') 
      {
        word.erase(word.size()-1);
      }
      cout << word << endl;
    }
    
    
    // Close File
    fileInput.close();
  }
  
  //For Each Line
  //While Character is not space
  
  
  return 0;
}
