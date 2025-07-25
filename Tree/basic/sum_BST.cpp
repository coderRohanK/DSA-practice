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

int sumBT(Node* root) {
    if(root == NULL) return 0;
    return root->data + sumBT(root->left) + sumBT(root->right);
}

int main() {
    // Example tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Sum of all nodes in binary tree: " << sumBT(root) << endl;

    return 0;
}
