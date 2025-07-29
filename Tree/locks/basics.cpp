#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode* parent;
    int lockedBy = -1; // -1 if unlocked, else user id
    int lockedDescendants = 0; // for upgrade efficiency

    TreeNode(int v) {
        val = v;
        parent = NULL;
    }
};

// LockingTree class
class LockingTree {
    TreeNode* root;
    unordered_map<int, TreeNode*> nodes; // map value to node pointer for quick access

public:
    // Constructor to build the tree from parent array
    LockingTree(vector<int>& parentArr) {
        int n = parentArr.size();
        vector<TreeNode*> treeNodes(n);
        for(int i = 0; i < n; i++) {
            treeNodes[i] = new TreeNode(i);
            nodes[i] = treeNodes[i];
        }

        root = treeNodes[0];

        for(int i = 1; i < n; i++) {
            int p = parentArr[i];
            treeNodes[i]->parent = treeNodes[p];
            treeNodes[p]->children.push_back(treeNodes[i]);
        }
    }

    // Lock operation
    bool lock(int num, int user) {
        TreeNode* node = nodes[num];
        if(node->lockedBy != -1) return false; // already locked

        node->lockedBy = user;

        // increment lockedDescendants count in all ancestors
        TreeNode* p = node->parent;
        while(p) {
            p->lockedDescendants++;
            p = p->parent;
        }
        return true;
    }

    // Unlock operation
    bool unlock(int num, int user) {
        TreeNode* node = nodes[num];
        if(node->lockedBy != user) return false; // can't unlock if not locked by same user

        node->lockedBy = -1;

        // decrement lockedDescendants count in all ancestors
        TreeNode* p = node->parent;
        while(p) {
            p->lockedDescendants--;
            p = p->parent;
        }
        return true;
    }

    // Helper: check if any ancestor is locked
    bool hasLockedAncestor(TreeNode* node) {
        TreeNode* p = node->parent;
        while(p) {
            if(p->lockedBy != -1) return true;
            p = p->parent;
        }
        return false;
    }

    // Helper: unlock all locked descendants
    bool unlockAllDescendants(TreeNode* node) {
        bool unlockedAny = false;

        for(auto child : node->children) {
            unlockedAny |= unlockAllDescendants(child);
        }

        if(node->lockedBy != -1) {
            node->lockedBy = -1;

            // decrement lockedDescendants in ancestors
            TreeNode* p = node->parent;
            while(p) {
                p->lockedDescendants--;
                p = p->parent;
            }

            unlockedAny = true;
        }

        return unlockedAny;
    }

    // Upgrade operation
    bool upgrade(int num, int user) {
        TreeNode* node = nodes[num];

        // Check if node is unlocked
        if(node->lockedBy != -1) return false;

        // Check if no ancestors are locked
        if(hasLockedAncestor(node)) return false;

        // Check at least one locked descendant
        if(node->lockedDescendants == 0) return false;

        // Unlock all locked descendants
        unlockAllDescendants(node);

        // Lock the current node
        node->lockedBy = user;

        // Increment lockedDescendants in ancestors
        TreeNode* p = node->parent;
        while(p) {
            p->lockedDescendants++;
            p = p->parent;
        }

        return true;
    }
};

// Demo driver code
int main() {
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
    LockingTree tree(parent);

    cout << boolalpha;
    cout << "Lock 4 by user 1: " << tree.lock(4, 1) << endl;       // true
    cout << "Upgrade 1 by user 2: " << tree.upgrade(1, 2) << endl; // true
    cout << "Lock 0 by user 3: " << tree.lock(0, 3) << endl;       // true
    cout << "Unlock 0 by user 3: " << tree.unlock(0, 3) << endl;   // true
    cout << "Lock 5 by user 4: " << tree.lock(5, 4) << endl;       // true
    cout << "Upgrade 2 by user 6: " << tree.upgrade(2, 6) << endl; // true
    cout << "Unlock 2 by user 6: " << tree.unlock(2, 6) << endl;   // true

    return 0;
}
