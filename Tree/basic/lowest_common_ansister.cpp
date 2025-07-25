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

TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if (root == NULL) return NULL;

    if (p < root->val && q < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (p > root->val && q > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;  // This is the split point, LCA found
}

int main() {
    // Construct BST
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    int p = 5, q = 15;
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca)
        cout << "LCA of " << p << " and " << q << " is: " << lca->val << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}
