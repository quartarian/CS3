#ifndef WordOccurrence_H 
#define  WordOccurrence_H

#include <string>
using namespace std;

class WordOccurrence {
    public:
        WordOccurrence(const string& word = "", int num=0);
        bool matchWord(const string& word); // returns true if word matches stored
        void increment(void); // increments number of occurrences
        void setWord(const string& word);
        string getWord(void) const;
        int getNum(void) const;

    private:
        string word_;
        int num_;
};


#endif
