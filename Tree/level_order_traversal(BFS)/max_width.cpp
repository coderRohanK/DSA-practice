#include <bits/stdc++.h>
using namespace std;

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while(q.size() > 0) {
            int currLevelSize = q.size();
            int stIdx = q.front().second;
            int endIdx = q.back().second;

            maxWidth = max(maxWidth, endIdx - stIdx + 1);

            for(int i = 0; i < currLevelSize; i++) {
                auto curr = q.front();
                q.pop();

                if(curr.first->left) {
                    q.push({curr.first->left, curr.second * 2 + 1});
                }
                if(curr.first->right) {
                    q.push({curr.first->right, curr.second * 2 + 2});
                }
            }
        }
        return maxWidth;
    }
};