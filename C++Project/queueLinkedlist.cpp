#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        // First Node
        if (front == nullptr) {
            front = rear = newNode;
            rear->next = front;
        }
        else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }
    void dequeue() {
        if (front == nullptr) {
            cout << "Underflow\n";
            return;
        }
        Node* temp = front;
        // Only One Node
        if (front == rear) {
            front = rear = nullptr;
        }
        else {
            front = front->next;
            rear->next = front;
        }
        delete temp;
    }
    void display() {
        if (front == nullptr) {
            cout << "Queue is Empty\n";
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
            if (temp == front) {
                break;
            }
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(100); q.enqueue(200); q.enqueue(300); q.enqueue(400); q.enqueue(500);
    cout << "After enqueue : ";
    q.display();

    q.dequeue();
    cout << "After dequeue : ";
    q.display();
    return 0;
}
