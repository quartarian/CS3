#ifndef Person_H
#define Person_H

#include<string>
#include<vector>

class Person {
public:
    Person(){};
    Person(std::string txtline) {parseLine(txtline);}
    ~Person(){};
    void addCourse(std::string course){this->courses.push_back(course);}
    void print();
private:
    std::string fname;
    std::string lname;
    std::vector<std::string> courses;

    void parseLine(std::string fileLine);

    friend bool operator> (Person &cC1, Person &cC2);
    friend bool operator<= (Person &cC1, Person &cC2);
    friend bool operator< (Person &cC1, Person &cC2);
    friend bool operator>= (Person &cC1, Person &cC2);
    friend bool operator== (Person &cC1, Person &cC2);
    friend bool operator== (const Person p1, const Person &p2);
    friend bool mergePeople(Person &p1, Person &p2);
};

#endif
