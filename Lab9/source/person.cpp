// Matthew Bender
#include"person.h"
#include<string>
#include <iostream>
#include<iomanip>

using std::string;
using std::setw;

void Person::parseLine(std::string fileLine) {
    int wordnumber = 0;
    bool readingspace = false;
    string word;
    for(int i = 0; i < fileLine.size(); i++) {
        if(readingspace && (fileLine[i] == ' ' || fileLine[i] == '\t')) {
            //Do Nothing
        }
        else {
            readingspace = false;
            if((fileLine[i] == ' ' || fileLine[i] == '\t')) {
                wordnumber++;
                readingspace = true;
            }
            else if(wordnumber == 0) {
                this->fname += fileLine[i];
            }               
            else if(wordnumber == 1) {
                this->lname += fileLine[i];
            }  
            else if(wordnumber > 1) {
                /*
                // This would allow multiple coureses to be added 
                int vindex = wordnumber - 2;
                if(this->courses.size() <= vindex) {
                    //Add course to vector (with first character)
                    string firstCharacter = "" + fileLine[i];
                    this->courses.push_back(firstCharacter);
                }
                else {
                    //Add character to course
                    this->courses[i] += fileLine[i];
                }
                */
            } 
        }
    }

}
void Person::print() {
    std::cout << std::left << setw(15) << this->fname << setw(15) << this->lname << setw(8);
    for(int i=0; i < this->courses.size(); i++) {
        std::cout << courses[i] << setw(8);
    }
    std::cout << std::endl;
}

bool operator> (Person  &p1, Person &p2) {
    return p1.lname > p2.lname;
}
bool operator<= (Person &p1, Person &p2) {
    return p1.lname <= p2.lname;
}
bool operator< (Person  &p1, Person &p2){
    return p1.lname < p2.lname;
}
bool operator>= (Person &p1, Person &p2){
    return p1.lname >= p2.lname;
}
bool operator== (const Person p1, const Person &p2) {
     return (p1.fname == p2.fname)&&(p1.lname == p2.lname);
}
bool operator== (Person &p1, Person &p2) {
    return (p1.fname == p2.fname)&&(p1.lname == p2.lname);
}
bool mergePeople(Person &p1, Person &p2) {
    if(p1 == p2) {
        p1.addCourse(p2.courses[0]);
        return true;
    }
    else {
        return false;
    }
}
