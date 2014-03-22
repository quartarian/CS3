// Matthew Bender

#include "person.h"
#include <iostream>
#include <string> 
#include <fstream>
#include <list>
#include <utility>
#include <iomanip>

using namespace std;

void fileToStudents(vector <list<Person>> &courseStudents, std::string filename, std::string course = ""); 
void readRoster(list<Person>& roster, string fileName, string course ="");  // reading a list from a fileName
void printPersonList(list<Person> list);
list<Person> mergePersonLists(vector <list<Person>> PersonLists);

int main (int argc, char* argv[]) {
    vector <list<Person>> courseStudents; // vector of courses of students

    // Load in Students
    fileToStudents(courseStudents, "example/cs1.txt", "CS1");
    fileToStudents(courseStudents, "example/cs2.txt", "CS2");
    fileToStudents(courseStudents, "example/cs3.txt", "CS3");
    // Appends additional course to first entry of student
    // and does not add additional entry to list
    list<Person> allStudents = mergePersonLists(courseStudents);

    cout << "--------------------------------------" << endl;
    cout << "         ALL STUDENTS (Unsorted)" << endl;
    cout << "--------------------------------------" << endl;
    cout << left << setw(15) << "First Name:" << setw(15) << "Last Name:" << setw(8) << "Courses:" << endl;
    printPersonList(allStudents);

    // Subtract Dropouts
    list<Person> dropoutStudents;
    readRoster(dropoutStudents,  "example/dropouts.txt");
    typedef std::list<Person>::iterator pList;
    for(pList i = dropoutStudents.begin(); i != dropoutStudents.end(); ++i) {
       Person test = *i;
       Person newtest = test;
       allStudents.remove(newtest); 
    }
    // Sort
    allStudents.sort();

    cout << "--------------------------------------" << endl;
    cout << "       REMAINING STUDENTS (Sorted)" << endl;
    cout << "--------------------------------------" << endl;
    cout << left << setw(15) << "First Name:" << setw(15) << "Last Name:" << setw(8) << "Courses:" << endl;
    printPersonList(allStudents);


    return 0;
}

list<Person> mergePersonLists(vector <list<Person>> personLists) {
    list<Person> mergedPeople;

    for(int i =0; i < personLists.size(); i++) {
        list<Person> people = personLists[i];
        typedef list<Person>::iterator pList;
        
        for(pList i = people.begin(); i != people.end(); ++i){
            bool merged = false;
            for(pList j = mergedPeople.begin(); j != mergedPeople.end(); ++j){
                merged = mergePeople(*j,*i);
                if(merged) break;
            } 
            if(!merged) mergedPeople.push_back(*i); 

        } 
    }

    return mergedPeople;
}
void fileToStudents(vector <list<Person>> &courseStudents, std::string filename, std::string course) {
    list<Person> roster;
    readRoster(roster, filename, course);
    courseStudents.push_back(move(roster)); 
    roster.clear();
}

// reading a list from fileName
void readRoster(list<Person>& roster, string fileName, string course) {
    ifstream fileInput(fileName.c_str());

    string fileLine;    
    while (getline (fileInput,fileLine)) {
       Person person(fileLine);
       if(course != "") {
            person.addCourse(course);
       } 
       roster.push_back(person);
    }

    fileInput.close();
}
 
void printPersonList(list<Person> list) {
    typedef std::list<Person>::iterator pList;
    for(pList i = list.begin(); i != list.end(); ++i) /* Prefer pre-increment with iterators */
    {
        i->print();
    }
}
