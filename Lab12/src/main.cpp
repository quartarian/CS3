#include <string>
#include <fstream>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <map> 

using namespace std;

struct Student {
    string fname;
    string lname;
    int grade;
    int rank; 
};

void fileToStudents(multimap<int,Student> &courseStudents, string fileName);
string intToLetter(int grade);
int main() {
    multimap<int, Student> studentsByGrade;
    multimap<string, Student> studentsByName;

    fileToStudents(studentsByGrade, "test.txt");

    for(auto it = studentsByGrade.begin(); it != studentsByGrade.end(); it++ ) {
        it->second.rank = studentsByGrade.size() - distance(studentsByGrade.begin(), it);
        studentsByName.insert ( std::pair<string,Student>( it->second.lname,it->second ));
    }

    cout << "First" << setw(20) 
         << "Last" << setw(20) 
         << "Score" << setw(15) 
         << "Rank" << setw(15) 
         << "Grade" << endl;

    for(auto it = studentsByName.begin(); it != studentsByName.end(); it++) {
        cout << it->second.fname << setw(20)
            << it->second.lname << setw(20)
            << it->second.grade << setw(15)
            << it->second.rank << setw(15)
            << intToLetter(it->second.grade) << endl;
    }
}
// Converts integer to letter grade
string intToLetter(int grade) {
    string returnval;
    if(grade <= 100)
        returnval = "A";
    if(grade <90)
        returnval = "B";
    if(grade < 80)
        returnval = "C";
    if(grade < 70)
        returnval = "D";
    if(grade < 60)
        returnval = "F";

    return returnval;
}
// reading a list from fileName
void fileToStudents(multimap<int,Student> &courseStudents, string fileName) {
    ifstream fileInput(fileName.c_str());

    string fileLine;    
    while (getline (fileInput,fileLine)) {
        int wordnumber = 0;
        bool readingspace = false;
        string word, fname, lname, grade;
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
                else if(wordnumber == 2) {
                    grade += fileLine[i];
                }   
            }
        }
        Student student = {fname, lname, atoi(grade.c_str())};
        courseStudents.insert ( std::pair<int,Student>(atoi(grade.c_str()),student) );

    }
    fileInput.close();
}
