#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;
#define m 3
#define n 3

class matrix
{
private:
    int arr[m][n];

public:
    matrix()
    {
        for (int i = 0; i < m; i++)
        {
            cout << "Value of " << i + 1 << "no row \n";
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
    };
    void display()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

#endif