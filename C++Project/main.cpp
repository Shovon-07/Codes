#include <iostream>
#include "patternclass.h"

using namespace std;

int add(int numbers[], int arrSize);

int main()
{
    PatternClass pattern;
//    pattern.LeftPyramid();
    pattern.RightPyramid();

    // string name = "Al jubair shovon";
    // cout << name;

    // int n, result;
    // cout << "Enter length of array : ";
    // cin >> n;
    // int nums[n];
    // cout << "Enter the numbers : \n";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> nums[i];
    // }
    // result = add(nums, n);
    // cout << result << endl;

    // int m, n;
    // cout << "Enter size of row : ";
    // cin >> m;
    // cout << "Enter size of column : ";
    // cin >> n;
    // int arr[m][n];

    // for (int i = 0; i < m; i++)
    // {
    //     cout << "Enter the value of " << i + 1 << "th row : ";
    //     for (int j = 0; j < n; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}

int add(int numbers[], int arrSize)
{
    int sum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        sum += numbers[i];
    }
    return sum;
}

/***
 **** Skiped
 * Bitwise operator
 *

***/
