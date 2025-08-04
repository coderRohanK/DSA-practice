#include <iostream>
#include <stack>
using namespace std;

// Global stacks
stack<int> st;
stack<int> minSt;

void push(int val) {
    st.push(val);
    if (minSt.empty() || val <= minSt.top()) {
        minSt.push(val);
    }
}

void pop() {
    if (!st.empty()) {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
}

int top() {
    if (!st.empty()) return st.top();
    return -1; // or throw exception
}

int getMin() {
    if (!minSt.empty()) return minSt.top();
    return -1; // or throw exception
}

// Example usage
int main() {
    push(5);
    push(3);
    push(7);
    cout << "Top: " << top() << endl;       // 7
    cout << "Min: " << getMin() << endl;    // 3
    pop();
    cout << "Top: " << top() << endl;       // 3
    cout << "Min: " << getMin() << endl;    // 3
    pop();
    cout << "Min: " << getMin() << endl;    // 5
    return 0;
}
