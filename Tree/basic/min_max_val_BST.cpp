#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

int findMin(TreeNode* root) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->val;
}

int findMax(TreeNode* root) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->val;
}

int main() {
    // Creating a simple BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    cout << "Minimum value: " << findMin(root) << endl;
    cout << "Maximum value: " << findMax(root) << endl;

    return 0;
}
