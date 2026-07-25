#include <iostream>

using namespace std;

int main()
{
    //=>>> Take input for the array elements and traverse or print them <<<=//
    int n, delPosition;
    cout << "Enter array size : ";
    cin >> n;

    int arr[n]; // Declare an array

    // Take input for array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\n\nDeletion position : ";
    cin >> delPosition;

    // Shift elements to the left
    for (int i = delPosition; i <= n; i++)
    {
        arr[i] = arr[i + 1];
    }

    n -= 1; // Decrease the value of n as the array size also decreases

    // Traverse/print array elements after deletion
    cout << "\nArray elements after deletion\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}