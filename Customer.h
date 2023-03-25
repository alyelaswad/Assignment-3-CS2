#ifndef CUSTOMER_H
#define CUSTOMER_H
// #include "Person.h"
class Customer : public Person
{
private:
    long MechanicID;
    string MechanicName;
    Appointment appointment;

public:
    Customer();
    void setMechanicID(long);     // assigns a mechanic to a the customer.
    void setMechanicName(string); // gets that mechanic's name.
    void setappointment(int, int);
    long getMechanicID();
    string getMechanicName();
    Appointment getappointment();
    bool operator<(const Customer &a); // operator overload to sort the customers in the queue.
    bool operator>(const Customer &a);
    bool operator==(const Customer &a);
};
#endif