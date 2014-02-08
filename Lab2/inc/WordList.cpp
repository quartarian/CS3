#include "WordList.h"
#include <iomanip>

WordList::WordList(int size) {
    this->wordArray_ = new WordOccurrence[size];
    this->size_ = size;
}

WordList::~WordList() {
    delete [] this->wordArray_;
}

void WordList::addWord(const string & word) {
    bool isFound = 0;
    for(int i=0; i < this->size_; i++) {
        if(this->wordArray_[i].getWord() == word) {
            isFound = 1;
            this->wordArray_[i].increment();
        }
    }
    if(!isFound) {
    	WordOccurrence* newWordArray = new WordOccurrence[this->size_+1];
        
        for(int i=0;i < this->size_;i++) {
            newWordArray[i] = this->wordArray_[i];
        }
        
        delete [] this->wordArray_;

    	this->wordArray_ = newWordArray;
    	this->wordArray_[this->size_++] = WordOccurrence(word,1);
    }

}
void WordList::printList() {
	cout << endl << "Words:" << endl;
	for(int i=0; i < this->size_; i++) {
        cout << left << setw(25) << this->wordArray_[i].getWord() <<
         		left << setw(10) << this->wordArray_[i].getNum() << endl;
    }
}
int WordList::getSize() {
	return this->size_;
}
//Insertion Sort
void WordList::sortList() {
	 int i, j;
	 WordOccurrence tmp;

	 for (i = 1; i < this->size_; i++) {
		 j = i;
		 while (j > 0 && wordArray_[j - 1].getNum() < wordArray_[j].getNum()) {
			 tmp = wordArray_[j];
			 wordArray_[j] = wordArray_[j - 1];
			 wordArray_[j - 1] = tmp;
			 j--;
		 }//end of while loop
	 }//end of for loop
}

void WordList::exandArray(int size) {

}
