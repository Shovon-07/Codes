#ifndef RECURSION_H
#define RECURSION_H
#include <iostream>
using namespace std;
#define size 5
class recursion
{
private:
    /* data */
public:
    recursion()
    {
        cout << ">>>>> Recursion <<<<<\n";
    };

    int fibonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    void display(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << fibonacci(i) << " ";
        }
        cout << endl;
    }

    /*
    Use these in main.cpp
    recursion r;
    r.display(10);
    */
};

#endif