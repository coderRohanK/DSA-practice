#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* front = NULL;
Node* rear = NULL;

// Enqueue function
void enqueue(int x) {
    Node* temp = new Node(x);
    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

// Dequeue function
int dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow" << endl;
        return -1;
    }
    int res = front->data;
    Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL; // if queue becomes empty
    delete temp;
    return res;
}

// Display function
void display() {
    if (front == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    cout << "Queue elements: ";
    display();

    cout << "Dequeued element: " << dequeue() << endl;
    cout << "Queue after dequeue: ";
    display();

    return 0;
}
