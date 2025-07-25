#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void reverse(Node* start, Node* end) {
    if (start == end) return;
    Node* x = start;
    Node* y = start->right;
    Node* z;
    while (x != end) {
        z = y->right;
        y->right = x;
        x = y;
        y = z;
    }
}

void printReverse(Node* start, Node* end) {
    reverse(start, end);
    Node* p = end;
    while (true) {
        cout << p->data << " ";
        if (p == start)
            break;
        p = p->right;
    }
    reverse(end, start);
}

void morrisPostorder(Node* root) {
    Node dummy(0);
    dummy.left = root;
    Node* current = &dummy;
    while (current) {
        if (current->left == NULL) {
            current = current->right;
        } else {
            Node* pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            } else {
                printReverse(current->left, pre);
                pre->right = NULL;
                current = current->right;
            }
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Morris Postorder Traversal: ";
    morrisPostorder(root);
    cout << endl;

    return 0;
}
