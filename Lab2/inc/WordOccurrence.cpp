#include "WordOccurrence.h"
#include<iostream>

WordOccurrence::WordOccurrence(const string& word, int num) {
	this->word_ = word;
	this->num_ = num;
}

bool WordOccurrence::matchWord(const string & word) {
	if(this->word_ == word) {
		return 1;
	}
	else {
		return 0;
	}
}
void WordOccurrence::increment() {
	this->num_++;
}
string WordOccurrence::getWord() const {
	return this->word_;
}
void WordOccurrence::setWord(const string & word) {
	this->word_ = word;
}
int WordOccurrence::getNum() const {
	return this->num_;
}
