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

Node* constructBST(vector<int>& postorder, int& index, int minVal, int maxVal) {
    if (index < 0)
        return NULL;

    int val = postorder[index];
    if (val < minVal || val > maxVal)
        return NULL;

    Node* root = new Node(val);
    index--;

    // Note: First build right subtree, then left subtree (reverse of postorder)
    root->right = constructBST(postorder, index, val + 1, maxVal);
    root->left = constructBST(postorder, index, minVal, val - 1);

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
    vector<int> postorder = {1, 7, 5, 50, 40, 10};
    int index = postorder.size() - 1;
    Node* root = constructBST(postorder, index, INT_MIN, INT_MAX);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);
    return 0;
}
