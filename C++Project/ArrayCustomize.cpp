#include <iostream>
using namespace std;

// int main()
//{
//     //=>>> Take input for the array elements and traverse or print them <<<=//
//     int n;
//     cout << "Enter array size : ";
//     cin >> n;
//
//     int arr[n]; // Declare an array
//
//     // Take input for array elements
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//
//     // Traverse/print array elements
//     cout << "\nArray elements\n";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//
//     //=>>> Inserting a value into this array <<<=//
//     int position, value;
//
//     cout << "\n\nInsertion position : ";
//     cin >> position;
//     cout << "Insertion value : ";
//     cin >> value;
//
//     // Shift elements to the right to create space for new value
//     for (int i = n; i >= position; i--)
//     {
//         arr[i] = arr[i - 1];
//     }
//
//     arr[position] = value; // Insert new value
//     n += 1;                // Increase the value of n as the array size also increases
//
//     // Traverse/print array elements after insertion
//     cout << "\nArray elements after insertion\n";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//
//     //=>>> Deleting a value into this array <<<=//
//     int delPosition;
//     cout << "\n\nDeletion position : ";
//     cin >> delPosition;
//
//     // Shift elements to the left
//     for (int i = delPosition; i <= n; i++)
//     {
//         arr[i] = arr[i + 1];
//     }
//
//     n -= 1; // Decrease the value of n as the array size also decreases
//
//     // Traverse/print array elements after deletion
//     cout << "\nArray elements after deletion\n";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//
//     cout << endl;
//
//     return 0;
// }

////=>>> Array insertion
// #include <iostream>
//
// using namespace std;
//
// int main()
//{
//     int n=5, pos=1, value=100;
//     int arr[100]= {10,20,30,40,50};
//
//     for(int i=n; i>=pos; i--)
//     {
//         arr[i]=arr[i-1];
//     }
//
//     arr[pos]=value;
//     n+=1;
//
//     for(int i=0; i<n; i++)
//     {
//         cout<< arr[i]<<" ";
//     }
//
//     return 0;
// }
//
////=>>> Array insertion (two value)
// #include <iostream>
//
// using namespace std;
//
// int main()
//{
//     int n=5, pos=1, value1=100,value2=200;
//     int arr[100]= {10,20,30,40,50};
//
//     for(int i=n+1; i>=pos; i--)
//     {
//         arr[i]=arr[i-2];
//     }
//
//     arr[pos]=value1;
//     arr[pos+1]=value2;
//     n+=2;
//
//     for(int i=0; i<n; i++)
//     {
//         cout<< arr[i]<<" ";
//     }
//
//     return 0;
// }
//
////=>>> Array deletion
// #include <iostream>
//
// using namespace std;
//
// int main()
//{
//     int n=5, pos=1;
//     int arr[100]= {10,20,30,40,50};
//
//     for(int i=pos; i<n; i++)
//     {
//         arr[i]=arr[i+1];
//     }
//
//     n-=1;
//
//     for(int i=0; i<n; i++)
//     {
//         cout<< arr[i]<<" ";
//     }
//
//     return 0;
// }
//
////=>>> Array deletion (two value)
// #include <iostream>
//
// using namespace std;
//
// int main()
//{
//     int n=5, pos1=1,pos2=2;
//     int arr[100]= {10,20,30,40,50};
//
//     for(int i=pos1; i<n; i++)
//     {
//         arr[i]=arr[i+2];
//     }
//
//     n-=2;
//
//     for(int i=0; i<n; i++)
//     {
//         cout<< arr[i]<<" ";
//     }
//
//     return 0;
// }
//
