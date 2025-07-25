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

void inorder(TreeNode* root, int& k, int& result) {
    if (root == NULL) return;

    inorder(root->left, k, result);

    k--;
    if (k == 0) {
        result = root->val;
        return;
    }

    inorder(root->right, k, result);
}

int kthSmallest(TreeNode* root, int k) {
    int result = -1;
    inorder(root, k, result);
    return result;
}

int main() {
    // Constructing BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    int k = 3;
    int ans = kthSmallest(root, k);
    if (ans != -1)
        cout << k << "th smallest element is: " << ans << endl;
    else
        cout << "Less than k nodes in BST" << endl;

    return 0;
}
