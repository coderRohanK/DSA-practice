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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int s=q.size();
            vector<int> level;
            for(int i=0;i<s;i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->data);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            res.push_back(level);
        }
        for(int i=0;i<res.size();i++){
            if(i%2!=0){
                reverse(res[i].begin(), res[i].end());
            }
        }
        return res;    
    }
};