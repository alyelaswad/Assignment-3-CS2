#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;
class Person
{
private: // private member variables name, ID , and age.
    string Name;
    long ID;
    int age;

public:
    Person();             // default constructor.
    void setName(string); // setters
    void setID(long);
    void setAge(int);
    string getName(); // getters
    long getID();
    int getAge();
    void printinfo();  // displaying the information of every person.
    struct Appointment // a public srtuct appointment to be easily accessed in the main.
    {
        int hours, mins;
    };
};
#endif