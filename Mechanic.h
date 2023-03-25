#ifndef Mechanic_H
#define Mechanic_H
#include "Person.h"
#include <string>
class Mechanic : public Person // inherits the variables from person.
{
private:
    int counter;
    Appointment *booked; // array/schedule of booked and bookable times for the mechanic.

public:
    Mechanic();
    ~Mechanic();
    bool isAvailable(Appointment); // checks if the mechanic is available at a certain time.
    void setCounter(int);
    void setBooked(Appointment); // books with the mechanic at a time;
    int getCounter();
    Appointment *getBooked(); // gets the info of when the mechanic is booked.
};
#endif