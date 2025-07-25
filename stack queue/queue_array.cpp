#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;
int arr[MAX_SIZE];
int front = 0;
int rear = -1;

// Enqueue function
void enqueue(int x) {
    if (rear == MAX_SIZE - 1) {
        cout << "Queue Overflow" << endl;
        return;
    }
    rear++;
    arr[rear] = x;
}

// Dequeue function
int dequeue() {
    if (front > rear) {
        cout << "Queue Underflow" << endl;
        return -1;
    }
    int res = arr[front];
    front++;
    return res;
}

// Display function
void display() {
    if (front > rear) {
        cout << "Queue is empty" << endl;
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
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
