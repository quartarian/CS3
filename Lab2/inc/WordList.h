#ifndef WordList_H 
#define  WordList_H

#include <string>
#include <iostream>
#include "WordOccurrence.h"
using namespace std;

class WordList{
    public:
        // add copy constructor, destructor, overloaded assignment
        WordList(int size = 0);
        WordList(const WordList& source);
        ~WordList();
        void addWord(const string & word);
        void printList(void);
        int getSize(void);
        void sortList();
        //Operators
        void operator =(const WordList& source);      
    private:
        WordOccurrence *wordArray_; // a dynamically allocated array of WordOccurrences
        // may or may not be sorted
        void exandArray(int size = 1);
        int size_;
};


#endif
