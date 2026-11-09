#include <iostream>
using namespace std;
#define size 5

class Stack {
    int top = -1;
    int arrStack[size];
public:
    void push(int value) {
        if (top == size - 1) {
            cout << "Overflow\n";
            return;
        }
        top += 1;
        arrStack[top] = value;
    }
    void pop() {
        if (top == -1) {
            cout << "Underflow\n";
            return;
        }
        --top;
    }
    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arrStack[i] << " ";
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
    cout << "\nAfter pop : ";
    s.display();
    return 0;
}