// #include "Mechanic.h"
Mechanic::Mechanic()
{
    counter = 0;
    booked = new Appointment[48];
}
bool Mechanic::isAvailable(Appointment c)
{
    for (int i = 0; i < 48; i++)
    {
        if (c.hours == (booked + i)->hours && c.mins == (booked + i)->mins)
        {
            return false;
        }
    }
    return true;
}
void Mechanic::setCounter(int CounteR) { counter = CounteR; }
void Mechanic::setBooked(Person::Appointment app)
{
    booked[++counter] = app;
}
int Mechanic::getCounter()
{
    return counter;
}
Person::Appointment *Mechanic::getBooked()
{
    return booked;
}
Mechanic::~Mechanic() // frees the memory
{
    delete[] booked;
    booked = nullptr;
}