#ifndef WordOccurrence_H 
#define  WordOccurrence_H
 
using namespace std;
#include <string>

class WordOccurrence {
  public:
      WordOccurrence(const string& word, int num=0);
      ~WordOccurrence();
      bool matchWord(const string &); // returns true if word matches stored
      void increment(void); // increments number of occurences
      string getWord(void) const; 
      int getNum(void) const;

  private:
      string word_;
      int num_;
};


#endif
