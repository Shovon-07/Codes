#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front=nullptr;
    Node* rear=nullptr;
public:
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue() {
        if (front == nullptr) {
            cout << "Underflow\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    void display() {
        Node* temp = front;
        if (temp == nullptr) {
            cout << "Queue is Empty\n";
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(100); q.enqueue(200); q.enqueue(300);  q.enqueue(400);  q.enqueue(500);
    cout << "After enqueue : ";
    q.display();

    q.dequeue();
    cout << "After dequeue : ";
    q.display();

    return 0;
}
