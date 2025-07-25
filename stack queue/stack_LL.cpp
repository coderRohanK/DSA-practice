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

Node* top = NULL;

// Push function
void push(int x) {
    Node* temp = new Node(x);
    temp->next = top;
    top = temp;
}

// Pop function
int pop() {
    if (top == NULL) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    int res = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return res;
}

// Display function
void display() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    cout << "Stack elements: ";
    display();

    cout << "Popped element: " << pop() << endl;
    cout << "Stack after pop: ";
    display();

    return 0;
}
