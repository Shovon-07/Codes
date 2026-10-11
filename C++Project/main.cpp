#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int v)
    {
        value = v;      // set value for data part
        next = nullptr; // Set null values ​​for link parts
    }
};
void traverse(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << ", "; // print the values
        temp = temp->next;           // change temp to the next address
    }
}
void deletionAtHead(Node *&head)
{
    if (head == nullptr)
    {
        cout << "Underflow" << endl;
        return;
    }
    Node *temp = head; // Create a new node
    head = head->next; // replace head to next variable of head
    delete temp;       // delete current node
    traverse(head);
}
void deletionAtTail(Node *&head)
{
    if (head == nullptr)
    {
        cout << "Underflow" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        deletionAtHead(head);
        return;
    }
    Node *temp = head; // Create a new node
    while (temp->next->next != nullptr)
    {
        temp = temp->next; // Move to the second-last node
    }
    temp->next = nullptr; // second last node become last node
    delete temp->next;    // delete the last node
    traverse(head);
}
void deletionAtPosition(Node *&head, int pos)
{
    Node *temp = head;
    int currentPos = 1;
    while (temp != nullptr && currentPos < pos - 1)
        temp = temp->next, currentPos++; // Move to before given position
    Node *deletNode = temp->next;        // create a deleteable node;
    temp->next = deletNode->next;        // change previous node next address
    delete deletNode;                    // delete given node
    traverse(head);
}

int main()
{
    // Create nodes & insert value
    Node *n1 = new Node(10);
    Node *n2 = new Node(15);
    Node *n3 = new Node(20);
    Node *n4 = new Node(25);
    Node *n5 = new Node(30);
    Node *n6 = new Node(35);
    Node *n7 = new Node(40);
    Node *n8 = new Node(45);
    Node *n9 = new Node(50);
    Node *n10 = new Node(55);

    // Linking with the next node
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;
    n10->next = nullptr;

    Node *head = n1;

    cout << "Original list : \n";
    traverse(head); // Display the original linked list
    cout << "\n\n";

    cout << "After deletion at head : \n";
    deletionAtHead(head); // deletion at head
    cout << "\n\n";

    cout << "After deletion at tail : \n";
    deletionAtTail(head); // deletion at tail
    cout << "\n\n";

    cout << "After deletion at given position : \n";
    deletionAtPosition(head, 3); // deletion at given position
    cout << "\n\n";
    return 0;
}

//=>>> Bubble sort
// #include <iostream>
// using namespace std;

// int main()
// {
//     // Step 1: Input size of the array
//     int n;
//     cout << "Array Size = ";
//     cin >> n;

//     int arr[n];

//     // Step 2: Read array elements
//     cout << "Enter array elements:" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     // Step 3: Perform Bubble Sort logic
//     for (int i = 0; i <= n - 2; i++)
//     {
//         for (int j = 0; j <= n - i - 2; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 // Swap arr[j] and arr[j + 1]
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }

//     // Step 4: Display the sorted array
//     cout << "Bubble sorted array = ";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int binary_search(int arr[], int n, int target)
// {
//     int lb = 0, ub = n - 1; // Set lower & uper bound
//     sort(arr, arr + n);     // Sort array in ascending order

//     cout << "Sorted array : ";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     for (int i = lb; i <= ub; i++)
//     {
//         int mid = (lb + ub) / 2; // Find middle point

//         if (arr[mid] == target)
//         {
//             return mid; // Found targeted value
//         }
//         else if (arr[mid] < target)
//         {
//             lb = mid + 1; // Right shift the value of lower bound
//         }
//         else if (arr[mid] > target)
//         {
//             ub = mid - 1; // Left shift the value of uper bound
//         }
//         else
//         {
//             return -1;
//         }
//     }
// }

// int main()
// {
//     int n, target;

//     cout << "Enter array size : ";
//     cin >> n; // Take array size from user
//     cout << "Enter targeted value : ";
//     cin >> target; // Take targeted value from user

//     int arr[n]; // Initialize array

//     cout << "Enter the numbers : \n";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i]; // Take each array element as input
//     }

//     int res = binary_search(arr, n, target); // Call function by value

//     // Print the position if target was fonded
//     if (res == -1)
//         cout << "Not founded\n";
//     else
//         cout << target << " is founded at position " << res << endl;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n, target, loc;
//     bool isFound = false;

//     cout << "Enter array size : ";
//     cin >> n; // Take array size from user
//     cout << "Enter targeted value : ";
//     cin >> target; // Take targeted value from user

//     int arr[n]; // Initialize array

//     cout << "Enter the numbers : \n";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i]; // Take each array element as input
//     }
//     // Compare each element with targeted value
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == target)
//         {
//             isFound = true, loc = i; // Mark target as found
//             break;
//         }
//     }

//     // Print the position if target was fonded
//     if (isFound == true)
//         cout << target << " is founded at position " << loc << endl;
//     else
//         cout << target << " is not found" << endl;

//     return 0;
// }

// // #include <iostream>
// // #include <vector>
// // using namespace std;

// // // Class containing array searching algorithms
// // class Solution
// // {
// // public:
// //     int search(vector<int> &nums, int target)
// //     {
// //         int lb = 0;               // Lower bound pointer (start index)
// //         int up = nums.size() - 1; // Upper bound pointer (end index)
// //         // Loop while search interval is valid
// //         while (lb <= up)
// //         {
// //             int mid = lb + (up - lb) / 2; // Calculate mid index safely to prevent integer overflow
// //             // Case 1: Target element found at mid
// //             if (nums[mid] == target)
// //                 return mid; // Return index of target
// //             // Case 2: Target is larger than mid (discard left half)
// //             else if (nums[mid] < target)
// //                 lb = mid + 1; // Move lower bound to right half
// //             // Case 3: Target is smaller than mid (discard right half)
// //             else
// //                 up = mid - 1; // Move upper bound to left half
// //         }
// //         return -1; // Target does not exist in array
// //     }
// // };

// // int main()
// // {
// //     int n;
// //     cout << "Enter array size : ";
// //     cin >> n;

// //     vector<int> nums(n); // Initialize vector with size n
// //     cout << "Enter the numbers : \n";
// //     for (int i = 0; i < n; i++)
// //         cin >> nums[i]; // Read sorted elements

// //     int target;
// //     cout << "Enter targeted value : ";
// //     cin >> target;

// //     // Create object instance and execute binary search
// //     Solution sol;
// //     int result = sol.search(nums, target);
// //     // Print search results
// //     if (result != -1)
// //         cout << "Target found at index: " << result << endl;
// //     else
// //         cout << "Target not found" << endl;

// //     return 0; // Terminate successfully
// // }

// // #include <iostream>

// // using namespace std;

// // int main()
// // {
// //     int n, count = 0;

// //     cout << "Enter array size : ";
// //     cin >> n;

// //     int arr[n];

// //     cout << "Enter numbers : " << endl;
// //     for (int i = 0; i < n; i++)
// //     {
// //         cin >> arr[i];
// //     }

// //     for (int i = 0; i < n; i++)
// //     {
// //         int flag = 0;
// //         for (int j = 0; j < i; j++)
// //         {
// //             if (arr[i] == arr[j])
// //             {
// //                 flag = 1;
// //                 break;
// //             }
// //         }

// //         if (flag == 0)
// //             count++;
// //     }

// //     cout << count << " " << endl;

// //     return 0;
// // }

// // Lab Report 2
// // Title: Step by Step excecution of Searching Algorithms
// // subtitle:
// // Linear Search
// // Binary Search
// // Binary Search - LeetCode
// // CSES - Distinct Numbers (Must carry the submission ensurance with others like code,output etc).
// // Lab Report Statements:
// // Report No.
// // Title.
// // Problem 1: Subtitle Name
// // Pseudocode.
// // Code (use testcase and should be comment out the statements line)
// // Output(take the screenshot with code)+ give the screenshot of the submission(if needed)
// // Thus complete all the 4 problems.
