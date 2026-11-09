#include <iostream>
using namespace std;
#define size 5

class Queue {
    int arrQueue[size], front= -1, rear= -1;
public:
    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Overflow\n";
            return;
        } 
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        arrQueue[rear] = value;
    }
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Underflow\n";
            return;
        } 
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arrQueue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10); q.enqueue(20); q.enqueue(30); q.enqueue(40); q.enqueue(50);
    cout << "After enqueue : ";
    q.display();

    q.dequeue();
    cout << "After dequeue : ";
    q.display();

    return 0;
}