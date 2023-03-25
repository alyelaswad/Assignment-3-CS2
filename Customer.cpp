#include <iostream>
#include <string>
// #include "Customer.h"
Customer::Customer() // initializing
{
    MechanicID = 000000000;
    appointment.hours = 0, appointment.mins = 0;
}
void Customer::setMechanicID(long mechID) { MechanicID = mechID; }
void Customer::setMechanicName(string namE) { MechanicName = namE; }
void Customer::setappointment(int Hours, int Mins)
{
    appointment.hours = Hours;
    appointment.mins = Mins;
}
long Customer::getMechanicID() { return MechanicID; }
string Customer::getMechanicName() { return MechanicName; }
Person::Appointment Customer::getappointment() { return appointment; }
bool Customer::operator<(const Customer &a)
{

    if (this->appointment.hours < a.appointment.hours)
    {
        return true;
    }
    else if (this->appointment.hours == a.appointment.hours)
    {
        if (this->appointment.mins < a.appointment.mins)
        {
            return true;
        }
    }
    return false;
}
bool Customer::operator>(const Customer &a)
{
    if (this->appointment.hours > a.appointment.hours)
    {
        return true;
    }
    else if (this->appointment.hours == a.appointment.hours)
    {
        if (this->appointment.mins > a.appointment.mins)
        {
            return true;
        }
    }
    return false;
}
bool Customer::operator==(const Customer &a)
{
    if (this->appointment.hours == a.appointment.hours && this->appointment.mins == a.appointment.mins)
    {
        return true;
    }
    return false;
}
