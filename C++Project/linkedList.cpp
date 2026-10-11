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

//=>>> Insert at head
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
// void traverse(Node *head) {
//    Node *temp = head;
//    cout<<"New value inserted at head: ";
//    while (temp != nullptr) {
//        cout << temp->value << ", "; // print values
//        temp = temp->next; // now point to the next node
//    }
//}
// int main() {
//    // Create nodes & insert value
//    Node *n1 = new Node(10);
//    Node *n2 = new Node(20);
//    Node *n3 = new Node(30);
//    Node *n4 = new Node(40);
//    Node *n5 = new Node(50);
//    Node *newNode=new Node(5); // create new node
//
//    // Linking with the next node
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;
//    n5->next = nullptr;
//    newNode->next=n1; // linking to the first node
//    traverse(newNode); // Call traversing function
//    return 0;
//}
