#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;
int arr[MAX_SIZE];
int top = -1;

// Push function
void push(int x) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    top++;
    arr[top] = x;
}

// Pop function
int pop() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    int res = arr[top];
    top--;
    return res;
}

// Utility function to display stack
void display() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
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
