#include <iostream>
#include <vector>
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

vector<int> a;

bool isValidBST(TreeNode* root) {
    if (root == NULL) return true;

    if (!isValidBST(root->left))
        return false;

    a.push_back(root->val);

    if (!isValidBST(root->right))
        return false;

    for (int i = 1; i < a.size(); i++) {
        if (a[i] <= a[i - 1])
            return false;
    }
    return true;
}

int main() {
    // Creating a simple tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    if (isValidBST(root))
        cout << "Valid BST" << endl;
    else
        cout << "Not a valid BST" << endl;

    return 0;
}
