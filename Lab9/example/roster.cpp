// list algorithms
// Mikhail Nesterenko
// 3/11/2014
 
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string> 
#include <utility>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move;
 
void readRoster(list<string>& roster, string fileName);  // reading a list from a fileName
void printRoster(const list<string>& roster); // printing a list out
 
int main(){
   vector <list<string>> courseStudents; // vector of courses of students
   list<string> roster;
 
   // reading in rosters per course and printing them out 
   readRoster(roster, "cs1.txt");  
   cout << "\n cs1 \n";  printRoster(roster);
   // std::move places roster into courseStudents without copying
   courseStudents.push_back(move(roster)); 
   roster.clear();
   readRoster(roster, "cs2.txt"); 
   cout << "\n cs2 \n" << endl; printRoster(roster);
   courseStudents.push_back(move(roster)); 
   roster.clear();
   readRoster(roster, "cs3.txt"); 
   cout << "\n cs3 \n" << endl; printRoster(roster); 
   courseStudents.push_back(move(roster)); 
   roster.clear();
 
   // reading in dropouts
   list<string> dropouts; 
   readRoster(dropouts, "dropouts.txt"); 
   cout << "\n dropouts \n" << endl; printRoster(dropouts);
 
   list<string> allStudents;  // master list of students
   for(auto& lst : courseStudents) // inserting individual courses
      allStudents.insert(allStudents.end(),lst.begin(),lst.end());
   cout << "\n all students unsorted \n" << endl; printRoster(allStudents);
 
   allStudents.sort(); // sorting master list
   cout << "\n all students sorted \n" << endl; printRoster(allStudents);
 
   allStudents.unique(); // eliminating duplicates
   cout << "\n all students, duplicates removed \n" << endl; printRoster(allStudents);
 
   for (auto& str : dropouts)  // removing individual dropouts
      allStudents.remove(str);
   cout << "\n all students, dropouts removed \n" << endl; printRoster(allStudents);
}
 
// reading a list from fileName
void readRoster(list<string>& roster, string fileName){
   ifstream course(fileName.c_str());
   while(!course.eof()){
      string name;
      getline(course,name);
      roster.push_back(name);
   }
   course.close();
}
 
// printing a list out
void printRoster(const list<string>& roster){
   for(auto& str : roster)
      cout << str << endl;
}
