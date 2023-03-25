#include <iostream>
#include <string>
// #include "Person.h"
Person::Person() // initializing the private members to 0.
{
    Name = "";
    ID = 000000000;
    age = 0;
}
void Person::setName(string name) { Name = name; } // setter definitions.
void Person::setID(long id) { ID = id; }
void Person::setAge(int AGE) { age = AGE; }
string Person::getName() { return Name; } // getter definition.
long Person::getID() { return ID; }
int Person::getAge() { return age; }
void Person::printinfo() // display the info of the person.
{
    cout << "\nPerson's name: " << Name << endl
         << "Person's ID: " << ID << endl
         << "Person's age: " << age << endl;
}
