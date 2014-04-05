// Matthew Bender
#include <iostream>
#include <string> 
#include <fstream>
#include <list>
#include <utility>
#include <iomanip>
#include <map> 
#include <vector>
using namespace std;

void fileToStudents(map<string,string> &courseStudents, map<string,vector<string>> &courses, string fileName, string course = "");
void printStudents(map<string,string> &courseStudents, map<string,vector<string>> courses);

int main (int argc, char* argv[]) {
    map<string,string> courseStudents, courseDropouts; 
    map<string,vector<string>> courses; 

    fileToStudents(courseStudents,courses, "example/cs1.txt", "CS1");
    fileToStudents(courseStudents,courses, "example/cs2.txt", "CS2");
    fileToStudents(courseStudents,courses, "example/cs3.txt", "CS3");
    fileToStudents(courseDropouts,courses, "example/dropouts.txt");

    typedef std::map<string, string>::iterator it_type;
    for(it_type iterator = courseDropouts.begin(); iterator != courseDropouts.end(); iterator++) {
        courseStudents.erase(iterator->first);
        courses.erase(iterator->first);
    }

    printStudents(courseStudents, courses);

    return 0;
}

// reading a list from fileName
void fileToStudents(map<string,string> &courseStudents, map<string,vector<string>> &courses, string fileName, string course) {
    ifstream fileInput(fileName.c_str());

    string fileLine;    
    while (getline (fileInput,fileLine)) {
        int wordnumber = 0;
        bool readingspace = false;
        string word, fname, lname;
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
                    fname += fileLine[i];
                }               
                else if(wordnumber == 1) {
                    lname += fileLine[i];
                }  
            }
        }
        courseStudents.insert ( std::pair<string,string>(lname,fname) );

        if(courses.count(lname) == 0) {
            vector<string> vec;
            vec.push_back(course);
            courses.insert ( pair<string,vector<string>>(lname,vec) );
        }
        else {
            //courses.insert ( pair<string,vector<string>>(lname,vec) );
            vector<string> vec = courses[lname];
            vec.push_back(course);
            courses[lname] = vec;
        }
    }
    fileInput.close();
}
void printStudents(map<string,string> &courseStudents, map<string,vector<string>> courses) {
    typedef std::map<string, string>::iterator it_type;

    cout << "--------------------------------------" << endl;
    cout << "       REMAINING STUDENTS (Sorted)" << endl;
    cout << "--------------------------------------" << endl;

    cout << left << setw(15)
         << "First Name:" << setw(15) 
         << "Last Name:" << setw(8) 
         << "Courses:" << endl;
    for(it_type iterator = courseStudents.begin(); iterator != courseStudents.end(); iterator++) {
        // iterator->first = key
        // iterator->second = value
        // Repeat if you also want to iterate through the second map.
        cout << left << setw(15)
             << iterator->second << setw(15) 
             << iterator->first;
        
        vector<string> vec = courses[iterator->first];
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        } 
        cout << endl;
    }   
}
