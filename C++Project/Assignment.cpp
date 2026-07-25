#include <iostream>
using namespace std;

//=>>> Assignment 1
// void runningSum(int nums[], int arrSize)
//{
//    int newArr[arrSize];
//
//    for (int i = 0; i < arrSize; i++)
//    {
//        newArr[i] = 0;
//    }
//
//    for (int i = 0; i < arrSize; i++)
//    {
//        newArr[i] = (i > 0) ? newArr[i - 1] + nums[i] : nums[i];
//    }
//
//    for (int num : newArr)
//    {
//        cout << num << " ";
//    }
//}
//
// int main()
//{
//    int n;
//    cout << "Enter the value of n : ";
//    cin >> n;
//
//    int numbers[n];
//
//    cout << "Enter the numbers : " << endl;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> numbers[i];
//    }
//
//    runningSum(numbers, n);
//
//    return 0;
//}
