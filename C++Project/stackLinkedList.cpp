#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

class Stack {
    Node *top = nullptr;
public:
    void push(int value) {
        Node *newNode = new Node();
        newNode->value = value;
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (top == nullptr) {
            cout << "Underflow\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return;
        }
        Node *temp = top;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10); s.push(20); s.push(30); s.push(40); s.push(50);
    cout << "After push : ";
    s.display();

    s.pop(); s.pop();
    cout << "After pop : ";
    s.display();

    return 0;
}