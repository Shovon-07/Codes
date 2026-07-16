#include <iostream>
#include "patternclass.h"

using namespace std;

PatternClass::PatternClass()
{
    cout << ">>> Pattern printing <<<\n"
         << endl;
}

//=>>> Left pyramid
void PatternClass::LeftPyramid()
{
    int n;
    cout << "How many time do you want to make pattern : ";
    cin >> n;

    for (int col = 0; col <= n; col++)
    {
        for (int row = 0; row <= col; row++)
        {

            cout << "*";
        }
        cout << endl;
    }
}

//=>>> Right pyramid
void PatternClass::RightPyramid()
{
    int n;
    cout << "? How many time do you want to make pattern : ";
    cin >> n;
    for (int row = 0; row <= n; row++)
    {
        for (int space = 0; space <= n - row; space++)
        {

            cout << " ";
        }
        for (int col = 0; col <= row; col++)
        {

            cout << ".";
        }
        cout << endl;
    }
}

