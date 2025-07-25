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

int maxDiameter = 0;

int height(Node* root) {
    if(root == NULL) return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    maxDiameter = max(maxDiameter, leftH + rightH);
    return 1 + max(leftH, rightH);
}

int diameterOfBinaryTree(Node* root) {
    maxDiameter = 0; // reset for each call
    height(root);
    return maxDiameter;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Diameter of Binary Tree: " << diameterOfBinaryTree(root) << endl;

    return 0;
}
