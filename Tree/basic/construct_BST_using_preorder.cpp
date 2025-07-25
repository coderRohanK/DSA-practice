#include <iostream>
#include <vector>
#include <climits>
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

Node* constructBST(vector<int>& preorder, int& index, int minVal, int maxVal) {
    if (index >= preorder.size())
        return NULL;

    int val = preorder[index];
    if (val < minVal || val > maxVal)
        return NULL;

    Node* root = new Node(val);
    index++;

    root->left = constructBST(preorder, index, minVal, val - 1);
    root->right = constructBST(preorder, index, val + 1, maxVal);

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {10, 5, 1, 7, 40, 50};
    int index = 0;
    Node* root = constructBST(preorder, index, INT_MIN, INT_MAX);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);
    return 0;
}
