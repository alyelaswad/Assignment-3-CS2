#include "Person.h"
#include "Customer.h"
#include "Mechanic.h"
#include "Person.cpp"
#include "Customer.cpp"
#include "Mechanic.cpp"
#include <iostream>
#include "Queue.h"
#include <iomanip>
#include <fstream>

using namespace std;
void appointMechanic(Mechanic mech[], Customer &a, int i, int count);
int main()
{
    Queue<Customer> queue; // the queue of customers.
    int size = 100;
    Mechanic mech[size]; // array of mechanics with a max size of 100.
    string names;
    ifstream Reader;  // var to read from mechanics.txt
    ifstream Readerc; // var to read from customers.txt
    long ids;
    int aGe, customerN;
    int hrs, mins;
    Reader.open("mechanics.txt");
    int i;
    if (Reader.is_open())
    {
        i = 0;
        do
        {
            cout << "Reading Mechanic " << i + 1 << "'s name...\n"; // getting the credentials of each mechanic.
            Reader >> names;
            mech[i].setName(names);
            cout << "Reading " << mech[i].getName() << "'s Mechanic's ID...\n";
            Reader >> ids;
            mech[i].setID(ids);
            cout << "Reading " << mech[i].getName() << "'s Age...\n";
            Reader >> aGe;
            mech[i].setAge(aGe);
            mech[i].printinfo();
            cout << "Data of Mechanic " << i + 1 << " taken...\n";
            i++;
        } while (!Reader.eof()); // this allows a more general case the code works on were a number of mechanics (max 100)
                                 // as it will read until no more mechanics are input.
    }

    // Data of Mechanic 3 taken...
    int count2 = 0;
    Customer custs[48 * 3];
    Readerc.open("customers.txt");

    do
    {
        cout << "\n\nReading Customer's name...\n";
        Readerc >> names;
        custs[count2].setName(names);
        cout << "Reading " << custs[count2].getName() << "'s ID...\n";
        Readerc >> ids;
        custs[count2].setID(ids);
        cout << "Reading " << custs[count2].getName() << "'s Age...\n";
        Readerc >> aGe;
        custs[count2].setAge(aGe);

        cout << "Reading the time to book? (hour minute): ";
        Readerc >> hrs >> mins;
        custs[count2].setappointment(hrs, mins);
        appointMechanic(mech, custs[count2], count2, i);
        count2++;
        cout << "\n";
    } while (!Readerc.eof()); // like with the mechanics this allows a more general case the code works on were a number of customer (max 144)
                              // as it will read until no more customers are input.

    for (int i = 0; i < count2 - 1; i++) // sorting the customers (selection sort) to be pushed into the queue.
    {
        int min_index = i;
        for (int j = i; j < count2; j++)
        {
            if (custs[j] < custs[min_index])
            {
                min_index = j;
            }
        }
        swap(custs[min_index], custs[i]);
    }
    for (int i = 0; i < count2; i++) // pushes the sorted customers into the queue.
    {
        queue.push(custs[i]);
    }
    cout << "The mechanics schedule is as follows:\nName\tID\t\tMechanic Name\tMechanic ID\tAppointment hour\tAppointment minute";
    queue.display();
}
void appointMechanic(Mechanic mech[], Customer &a, int i, int count) // this function allocates an appointment with the mechanics.
{
    static int one_counter, two_counter, three_counter;
    i %= count;
    if ((i % 3) == 0)
    {

        if (mech[i].isAvailable(a.getappointment())) // checks if the mechanic is available at that time
        // if not an appointment with another mechanic is set
        {
            a.setMechanicID(mech[i].getID());
            cout << endl
                 << endl
                 << mech[i].getName();
            a.setMechanicName(mech[i].getName());
            mech[i].setCounter(++one_counter);
            mech[i].setBooked(a.getappointment());
            cout << "\nBooked...\n";
            return;
        }
        else
        {
            i++;
        }
    }
    if (i % 3 == 1)
    {
        if (mech[i].isAvailable(a.getappointment()))
        {
            a.setMechanicID(mech[i].getID());
            cout << endl
                 << endl
                 << mech[i].getName();
            a.setMechanicName(mech[i].getName());
            mech[i].setCounter(++two_counter);
            mech[i].setBooked(a.getappointment());
            cout << "\nBooked...\n";
            return;
        }
        else
        {
            i++;
        }
    }
    if (i % 3 == 2)
    {
        if (mech[i].isAvailable(a.getappointment()))
        {
            a.setMechanicID(mech[i].getID());
            cout << endl
                 << endl
                 << mech[i].getName();
            a.setMechanicName(mech[i].getName());
            mech[i].setCounter(++three_counter);
            mech[i].setBooked(a.getappointment());
            cout << "\nBooked...\n";
            return;
        }
        else
        {
            cout << "We are sincerely sorry! All our mechanics are unavailable at that time. Please select a different time.\n";
        }
    }
    return;
}