#ifndef WordList_H 
#define  WordList_H
 
#include <string>
#include <iostream>
#include "WordOccurrence.h"
using namespace std;

class WordList{
  public:
      // add copy constructor, destructor, overloaded assignment
      WordList(int size = 1);
      WordList(const WordList& source);
      ~WordList();
      void addWord(const string &);
      void printList(void);
      //Operators
      void operator =(const sequence& source);      
  private:
      WordOccurrence *wordArray_; // a dynamically allocated array of WordOccurrences
                                  // may or may not be sorted
      int size_;
};


#endif
