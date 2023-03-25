#include <iostream>
#include <iomanip>
using namespace std;
template <typename T>
class Queue
{
private:
    int front;
    int rear;
    int size;
    T *queue;

public:
    Queue()
    {
        size = 48;
        queue = new T[size];
        front = -1;
        rear = -1;
    }
    void push(T que)
    {
        if (rear == size - 1) // checks if the queue is already full beforing pushing.
        {
            cout << "The queue is already full.\n";
        }
        else if (front == -1 && rear == -1) // checks if it is the first index.
        {
            front++;
            rear++;
            *(queue + rear) = que;
        }
        else if (front == 0 && rear != size - 1) // normal push into the queue.
        {
            rear++;
            *(queue + rear) = que;
        }
    }
    T pop()
    {
        if (front == rear) // chechks if the queue is empty.
        {
            cout << "The queue is empty";
        }
        else
        {
            front++; // pops the first one in the queue.
        }
    }
    void display()
    {
        if (front == rear)
        {
            cout << "Queue is empty";
        }
        else
        {
#if T == Customer // if the type is customer it displays his information as well.
            for (int i = front; i < rear + 1; i++)
            {

                cout << endl
                     << (queue + i)->getName() << "\t" << (queue + i)->getID() << "\t" << (queue + i)->getMechanicName() << "\t\t"
                     << (queue + i)->getMechanicID() << "\t" << (queue + i)->getappointment().hours << "\t\t\t";
                if ((queue + i)->getappointment().mins == 0)
                {
                    cout << setw(2) << setfill('0') << (queue + i)->getappointment().mins;
                }
                else
                {
                    cout << (queue + i)->getappointment().mins;
                }
            }
#else
            for (int i = front; i < rear + 1; i++)
            {
                cout << *(queue + i);
            }

#endif
        }
    }
    T peak() // returns the first one in the queue.
    {
        if (front == rear)
        {
            cout << "Queue is empty";
        }
        else
        {
            return *(queue + front);
        }
    }
    void setSize(int SiZe) { size = SiZe; }
    T *getQueue() { return queue; }
    ~Queue()
    { // frees the memory.
        delete[] queue;
    }
};