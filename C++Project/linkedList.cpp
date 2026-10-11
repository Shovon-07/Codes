//=>>> Traversing
// #include <iostream>
// using namespace std;
//
// class Node {
// public:
//    int value;
//    Node *next;
//    Node(int v) {
//        value = v; // set value for data part
//        next = nullptr; // Set null values ​​for link parts
//    }
//};
// void traverse(Node &n1) {
//    Node *temp = &n1;
//    while (temp != nullptr) {
//        cout << temp->value << " ";
//        temp = temp->next;
//    }
//};
//
// int main() {
//    // Create nodes & insert value
//    Node *n1 = new Node(10);
//    Node *n2 = new Node(20);
//    Node *n3 = new Node(30);
//    Node *n4 = new Node(40);
//    Node *n5 = new Node(50);
//
//    // Linking with the next node
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;
//    n5->next = nullptr;
//    traverse(*n1); // Call traversing function
//    return 0;
//}

//=>>> Linked List insertion (at head, at tail and at any position)
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int value;
//     Node *next;
//     Node(int v)
//     {
//         value = v;      // set value for data part
//         next = nullptr; // Set null values ​​for link parts
//     }
// };
// void traverse(Node *&head)
// {
//     Node *temp = head;
//     while (temp != nullptr)
//     {
//         cout << temp->value << ", "; // print the values
//         temp = temp->next;           // change temp to the next address
//     }
// }
// void insertAtHead(Node *&head, int value)
// {
//     Node *newNode = new Node(value); // Create a new node
//     newNode->next = head;            // New node points to the current head
//     head = newNode;                  // Make the new node the head
//     traverse(head);
// }
// void insertAtTail(Node *&head, int value)
// {
//     Node *temp = head;
//     while (temp->next != nullptr)
//         temp = temp->next;           // change temp to the next address
//     Node *newNode = new Node(value); // create a new node
//     temp->next = newNode;            // replace the last node address to new node address
//     newNode->next = nullptr;         // assign new node address as null
//     traverse(head);
// }
// void insertAtPosition(Node *&head, int value, int pos)
// {
//     if (pos == 1)
//     {
//         insertAtHead(head, value);
//         return;
//     }
//     Node *temp = head;
//     int currentPos = 1;
//     while (temp != nullptr && currentPos < pos - 1)
//         temp = temp->next, currentPos++; // change temp to the next address
//     if (temp == nullptr)
//     {
//         cout << "Invalid position\n";
//         return;
//     }
//     Node *newNode = new Node(value); // create a new node
//     newNode->next = temp->next;      // replace the new node address with the next node address
//     temp->next = newNode;            // replace the next node address with the next node address
//     traverse(head);
// }

// int main()
// {
//     // Create nodes & insert value
//     Node *n1 = new Node(10);
//     Node *n2 = new Node(15);
//     Node *n3 = new Node(20);
//     Node *n4 = new Node(25);
//     Node *n5 = new Node(30);

//     // Linking with the next node
//     n1->next = n2;
//     n2->next = n3;
//     n3->next = n4;
//     n4->next = n5;
//     n5->next = nullptr;

//     Node *head = n1;

//     cout << "Original list : \n";
//     traverse(head); // Display the original linked list
//     cout << "\n\n";

//     cout << "After insert 5 at head : \n";
//     insertAtHead(head, 5); // Insert 5 at head
//     cout << "\n\n";

//     cout << "After insert 35 at tail : \n";
//     insertAtTail(head, 35); // Insert 35 at tail
//     cout << "\n\n";

//     cout << "After insert 50 at position 3 : \n";
//     insertAtPosition(head, 50, 3); // Insert 50 at given position
//     cout << "\n\n";

//     return 0;
// }

//=>>> Linked List deletion(at head, at tail, at any position)
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int value;
//     Node *next;
//     Node(int v)
//     {
//         value = v;      // set value for data part
//         next = nullptr; // Set null values ​​for link parts
//     }
// };
// void traverse(Node *&head)
// {
//     Node *temp = head;
//     while (temp != nullptr)
//     {
//         cout << temp->value << ", "; // print the values
//         temp = temp->next;           // change temp to the next address
//     }
// }
// void deletionAtHead(Node *&head)
// {
//     if (head == nullptr)
//     {
//         cout << "Underflow" << endl;
//         return;
//     }
//     Node *temp = head; // Create a new node
//     head = head->next; // replace head to next variable of head
//     delete temp;       // delete current node
//     traverse(head);
// }
// void deletionAtTail(Node *&head)
// {
//     if (head == nullptr)
//     {
//         cout << "Underflow" << endl;
//         return;
//     }
//     if (head->next == nullptr)
//     {
//         deletionAtHead(head);
//         return;
//     }
//     Node *temp = head; // Create a new node
//     while (temp->next->next != nullptr)
//     {
//         temp = temp->next; // Move to the second-last node
//     }
//     temp->next = nullptr; // second last node become last node
//     delete temp->next;    // delete the last node
//     traverse(head);
// }
// void deletionAtPosition(Node *&head, int pos)
// {
//     Node *temp = head;
//     int currentPos = 1;
//     while (temp != nullptr && currentPos < pos - 1)
//         temp = temp->next, currentPos++; // Move to before given position
//     Node *deletNode = temp->next;        // create a deleteable node;
//     temp->next = deletNode->next;        // change previous node next address
//     delete deletNode;                    // delete given node
//     traverse(head);
// }

// int main()
// {
//     // Create nodes & insert value
//     Node *n1 = new Node(10);
//     Node *n2 = new Node(15);
//     Node *n3 = new Node(20);
//     Node *n4 = new Node(25);
//     Node *n5 = new Node(30);
//     Node *n6 = new Node(35);
//     Node *n7 = new Node(40);
//     Node *n8 = new Node(45);
//     Node *n9 = new Node(50);
//     Node *n10 = new Node(55);

//     // Linking with the next node
//     n1->next = n2;
//     n2->next = n3;
//     n3->next = n4;
//     n4->next = n5;
//     n5->next = n6;
//     n6->next = n7;
//     n7->next = n8;
//     n8->next = n9;
//     n9->next = n10;
//     n10->next = nullptr;

//     Node *head = n1;

//     cout << "Original list : \n";
//     traverse(head); // Display the original linked list
//     cout << "\n\n";

//     cout << "After deletion at head : \n";
//     deletionAtHead(head); // deletion at head
//     cout << "\n\n";

//     cout << "After deletion at tail : \n";
//     deletionAtTail(head); // deletion at tail
//     cout << "\n\n";

//     cout << "After deletion at given position : \n";
//     deletionAtPosition(head, 3); // deletion at given position
//     cout << "\n\n";
//     return 0;
// }

//=>>> Move the elements from tail to head and head to tail
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int value;
//     Node *next;
//     Node(int v)
//     {
//         value = v;      // set value for data part
//         next = nullptr; // Set null values ​​for link parts
//     }
// };
// void traverse(Node *&head)
// {
//     Node *temp = head;
//     while (temp != nullptr)
//     {
//         cout << temp->value << ", "; // print the values
//         temp = temp->next;           // change temp to the next address
//     }
// }
// void moveTailToHead(Node *&head)
// {
//     if (head == NULL || head->next == NULL)
//         return;
//     Node *temp = head;
//     while (temp->next->next != NULL)
//         temp = temp->next; // Find second-last node
//     Node *lastNode = temp->next;
//     temp->next = NULL;
//     lastNode->next = head;
//     head = lastNode;
//     traverse(head);
// }
// void moveHeadToTail(Node *&head)
// {
//     if (head == NULL || head->next == NULL)
//         return;
//     Node *oldHead = head;
//     head = head->next;
//     Node *temp = head;
//     while (temp->next != NULL)
//         temp = temp->next;
//     temp->next = oldHead;
//     oldHead->next = NULL;
//     traverse(head);
// }

// int main()
// {
//     // Create nodes & insert value
//     Node *n1 = new Node(10);
//     Node *n2 = new Node(15);
//     Node *n3 = new Node(20);
//     Node *n4 = new Node(25);
//     Node *n5 = new Node(30);

//     // Linking with the next node
//     n1->next = n2;
//     n2->next = n3;
//     n3->next = n4;
//     n4->next = n5;
//     n5->next = nullptr;

//     Node *head = n1;

//     cout << "Original list : \n";
//     traverse(head); // Display the original linked list
//     cout << "\n\n";

//     cout << "Move Tail to Head : \n";
//     moveTailToHead(head);
//     cout << "\n\n";

//     cout << "Move Head to Tail : \n";
//     moveHeadToTail(head);
//     cout << "\n\n";
//     return 0;
// }

//=>>> Merge Two Sorted Lists( leetcode)
// #include <iostream>
// using namespace std;

// class node
// {
// public:
//     int value;
//     node *next;
//     node(int v)
//     {
//         value = v;
//         next = nullptr;
//     }
// };
// node *mergeTwoLists(node *head1, node *head2)
// {
//     node *temp = new node(0); // Create a temp node
//     node *current = temp;     // Current pointer starts from temp
//                               // Compare nodes from both lists
//     while (head1 != nullptr && head2 != nullptr)
//     {
//         if (head1->value <= head2->value)
//         {
//             current->next = head1;
//             head1 = head1->next;
//         }
//         else
//         {
//             current->next = head2;
//             head2 = head2->next;
//         }
//         current = current->next; // Move current to the newly added node
//     }
//     if (head1 != nullptr)
//         current->next = head1; // Add remaining nodes of list 1
//     if (head2 != nullptr)
//         current->next = head2; // Add remaining nodes of list 2
//     return temp->next;
// }
// void traversing(node *head)
// {
//     node *temp = head;
//     while (temp != nullptr)
//     {
//         cout << temp->value << ", ";
//         temp = temp->next;
//     }
// }

// int main()
// {
//     // First sorted list
//     node *node1 = new node(1);
//     node *node2 = new node(2);
//     node *node3 = new node(4);
//     node1->next = node2;
//     node2->next = node3;

//     node *head1 = node1;
//     cout << "1st Linked List:" << endl;
//     traversing(head1);
//     cout << "\n\n";

//     // Second sorted list
//     node *node4 = new node(1);
//     node *node5 = new node(3);
//     node *node6 = new node(4);
//     node4->next = node5;
//     node5->next = node6;

//     node *head2 = node4;
//     cout << "2nd Linked List:" << endl;
//     traversing(head2);
//     cout << "\n\n";

//     node *head = mergeTwoLists(head1, head2); // Merge the two sorted lists

//     cout << "After Merging Two Sorted Lists:" << endl;
//     traversing(head); // Display the merged list
//     cout << "\n";
//     return 0;
// }

//=>>> Remove Nth Node From End of List (leetcode)