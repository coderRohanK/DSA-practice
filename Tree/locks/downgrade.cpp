#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode* parent;
    int lockedBy = -1;
    int lockedDescendants = 0;

    TreeNode(int v) {
        val = v;
        parent = nullptr;
    }
};

class LockingTree {
    TreeNode* root;
    unordered_map<int, TreeNode*> nodes;

public:
    LockingTree(vector<int>& parentList) {
        int n = parentList.size();
        vector<TreeNode*> temp(n);
        for (int i = 0; i < n; ++i)
            temp[i] = new TreeNode(i);

        for (int i = 0; i < n; ++i) {
            int parent = parentList[i];
            if (parent != -1) {
                temp[parent]->children.push_back(temp[i]);
                temp[i]->parent = temp[parent];
            }
        }
        root = temp[0];
        for (int i = 0; i < n; ++i)
            nodes[i] = temp[i];
    }

    bool lock(int num, int user) {
        TreeNode* node = nodes[num];
        if (node->lockedBy != -1) return false;
        node->lockedBy = user;

        TreeNode* p = node->parent;
        while (p) {
            p->lockedDescendants++;
            p = p->parent;
        }
        return true;
    }

    bool unlock(int num, int user) {
        TreeNode* node = nodes[num];
        if (node->lockedBy != user) return false;
        node->lockedBy = -1;

        TreeNode* p = node->parent;
        while (p) {
            p->lockedDescendants--;
            p = p->parent;
        }
        return true;
    }

    bool hasLockedAncestor(TreeNode* node) {
        TreeNode* p = node->parent;
        while (p) {
            if (p->lockedBy != -1)
                return true;
            p = p->parent;
        }
        return false;
    }

    bool unlockAllDescendants(TreeNode* node) {
        bool unlockedAny = false;
        for (TreeNode* child : node->children) {
            if (child->lockedBy != -1) {
                child->lockedBy = -1;
                TreeNode* p = child->parent;
                while (p) {
                    p->lockedDescendants--;
                    p = p->parent;
                }
                unlockedAny = true;
            }
            unlockedAny |= unlockAllDescendants(child);
        }
        return unlockedAny;
    }

    bool upgrade(int num, int user) {
        TreeNode* node = nodes[num];
        if (node->lockedBy != -1 || node->lockedDescendants == 0 || hasLockedAncestor(node))
            return false;

        bool unlocked = unlockAllDescendants(node);
        if (!unlocked) return false;

        node->lockedBy = user;
        TreeNode* p = node->parent;
        while (p) {
            p->lockedDescendants++;
            p = p->parent;
        }
        return true;
    }

    void printLockedDescendants(TreeNode* node) {
        if (!node) return;
        cout << "Node " << node->val << " has " << node->lockedDescendants << " locked descendants." << endl;
        for (TreeNode* child : node->children) {
            printLockedDescendants(child);
        }
    }

    // ✅ Downgrade: Unlock node, lock immediate children
    bool downgrade(int num, int user) {
        TreeNode* node = nodes[num];
        if (node->lockedBy != user) return false;

        // Unlock the node
        node->lockedBy = -1;
        TreeNode* p = node->parent;
        while (p) {
            p->lockedDescendants--;
            p = p->parent;
        }

        // Lock immediate children
        for (TreeNode* child : node->children) {
            if (child->lockedBy == -1) {
                child->lockedBy = user;
                TreeNode* p = child->parent;
                while (p) {
                    p->lockedDescendants++;
                    p = p->parent;
                }
            } else {
                // Cannot lock one of the children
                return false;
            }
        }

        return true;
    }

    // Use this to call from outside
    void countLockedDescendants() {
        printLockedDescendants(root);
    }

    TreeNode* getRoot() {
        return root;
    }

    unordered_map<int, TreeNode*>& getNodes() {
        return nodes;
    }
};

int main() {
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
    LockingTree tree(parent);

    tree.lock(3, 1);
    tree.lock(4, 1);

    tree.countLockedDescendants();

    // Downgrade node 1 by user 1
    cout << (tree.downgrade(1, 1) ? "Downgrade Success" : "Downgrade Failed") << endl;

    tree.countLockedDescendants();
}
