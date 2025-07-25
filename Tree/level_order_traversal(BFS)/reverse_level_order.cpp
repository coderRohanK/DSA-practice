#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if(root == NULL) return res;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++) {
            TreeNode* temp = q.front();
            q.pop();
            level.push_back(temp->val);

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        res.push_back(level);
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    // Create tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = levelOrderBottom(root);

    cout << "Level Order Bottom-Up Traversal:" << endl;
    for(auto level : result) {
        for(int val : level)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
