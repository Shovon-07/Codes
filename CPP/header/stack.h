#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
#define size 5

class stack
{
private:
    int arr[size], top = -1;

public:
    stack()
    {
        cout << ">>>>> Stack <<<<<\n";
    };

    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "Overflow : " << value << " can not inserted\n";
            return;
        }
        top++;
        arr[top] = value;
        // cout << value << " inserted\n";
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Underflow\n";
            return;
        }
        cout << arr[top] << " is deleted\n";
        top--;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "\nElements :\n";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
        cout << endl;
    }

    /*
    Use these in main.cpp
    stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    s1.display();

    s1.pop();
    s1.pop();
    s1.display();
    */
};

#endif