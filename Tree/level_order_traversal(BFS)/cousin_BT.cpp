#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

bool isCousins(TreeNode* root, int x, int y) {
    if(root == NULL) return false;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();
        bool foundX = false, foundY = false;

        for(int i = 0; i < n; i++) {
            TreeNode* temp = q.front();
            q.pop();

            if(temp->val == x) foundX = true;
            if(temp->val == y) foundY = true;

            if(temp->left && temp->right) {
                if((temp->left->val == x && temp->right->val == y) ||
                   (temp->left->val == y && temp->right->val == x)) {
                    return false;
                }
            }

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }

        if(foundX && foundY)
            return true;

        if(foundX || foundY)
            return false;
    }
    return false;
}

int main() {
    // Example tree:
    //         1
    //       /   \
    //      2     3
    //       \     \
    //        4     5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);

    int x = 4, y = 5;

    if(isCousins(root, x, y))
        cout << x << " and " << y << " are cousins." << endl;
    else
        cout << x << " and " << y << " are not cousins." << endl;

    return 0;
}
