#ifndef CIRCULERQUEUE_H
#define CIRCULERQUEUE_H
#include <iostream>
using namespace std;
#define size 5

class circulerQueue
{
private:
    int arr[size], front = -1, rear = -1;

public:
    circulerQueue()
    {
        cout << ">>>>> Queue <<<<<\n";
    };

    void enqueue(int value)
    {
        if (front == (rear + 1) % size)
        {
            cout << "Overflow : " << value << " can not inserted\n";
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Underflow\n";
            return;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "\nElements :\n";
        for (int i = rear; i >= front; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    /*
    Use these in main.cpp
    circulerQueue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);
    q1.display();

    q1.dequeue();
    q1.dequeue();
    q1.display();
    */
};

#endif