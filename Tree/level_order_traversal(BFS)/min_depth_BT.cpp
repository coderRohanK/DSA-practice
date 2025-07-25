#include <bits/stdc++.h>
using namespace std;

// Definition of Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();

                // If leaf node, return current depth
                if(temp->left == NULL && temp->right == NULL) {
                    return depth;
                }

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            depth++;
        }
        return depth;
    }
};