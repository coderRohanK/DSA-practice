#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode* parent;
    int lockedBy = -1; // -1 if unlocked, else user id
    int lockedDescendants = 0;

    TreeNode(int v) {
        val = v;
        parent = NULL;
    }
};

class LockingTree {
private:
    TreeNode* root;
    unordered_map<int, TreeNode*> nodes;

public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        vector<TreeNode*> tree(n);
        for (int i = 0; i < n; ++i) {
            tree[i] = new TreeNode(i);
        }

        for (int i = 0; i < n; ++i) {
            if (parent[i] != -1) {
                tree[i]->parent = tree[parent[i]];
                tree[parent[i]]->children.push_back(tree[i]);
            }
        }

        root = tree[0];
        for (int i = 0; i < n; ++i) {
            nodes[i] = tree[i];
        }
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

    bool upgrade(int num, int user) {
        TreeNode* node = nodes[num];
        if (node->lockedBy != -1 || node->lockedDescendants == 0 || hasLockedAncestor(node)) {
            return false;
        }

        if (!unlockAllDescendants(node)) return false;

        node->lockedBy = user;

        TreeNode* p = node->parent;
        while (p) {
            p->lockedDescendants++;
            p = p->parent;
        }

        return true;
    }

private:
    bool hasLockedAncestor(TreeNode* node) {
        TreeNode* p = node->parent;
        while (p) {
            if (p->lockedBy != -1) return true;
            p = p->parent;
        }
        return false;
    }

    bool unlockAllDescendants(TreeNode* node) {
        bool unlockedAny = false;
        for (TreeNode* child : node->children) {
            unlockedAny |= unlockAllDescendants(child);
        }

        if (node->lockedBy != -1) {
            node->lockedBy = -1;
            TreeNode* p = node->parent;
            while (p) {
                p->lockedDescendants--;
                p = p->parent;
            }
            unlockedAny = true;
        }

        return unlockedAny;
    }

public:
    void printAllLockedDescendants() {
        printLockedDescendantsCount(root);
    }

private:
    void printLockedDescendantsCount(TreeNode* node) {
        cout << "Node " << node->val << " has " << node->lockedDescendants << " locked descendants.\n";
        for (TreeNode* child : node->children) {
            printLockedDescendantsCount(child);
        }
    }
};


int main() {
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
    LockingTree tree(parent);

    tree.lock(3, 1);
    tree.lock(4, 2);
    tree.lock(6, 3);

    tree.printAllLockedDescendants();  // prints lockedDescendants for all nodes

    return 0;
}
