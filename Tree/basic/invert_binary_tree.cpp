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

Node* invertTree(Node* root) {
    if(root == NULL) return NULL;
    Node* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(9);

    cout << "Original Tree (Inorder): ";
    inorder(root);
    cout << endl;

    root = invertTree(root);

    cout << "Inverted Tree (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
