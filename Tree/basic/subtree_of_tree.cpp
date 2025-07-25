#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool isSameTree(Node* p, Node* q) {
    if(p == NULL || q == NULL)
        return p == q;

    bool Lsame = isSameTree(p->left, q->left);
    bool Rsame = isSameTree(p->right, q->right);

    return Lsame && Rsame && p->data == q->data;
}

bool isSubtree(Node* root, Node* subRoot) {
    if(root == NULL) return false;

    if(isSameTree(root, subRoot)) return true;

    bool leftSub = isSubtree(root->left, subRoot);
    bool rightSub = isSubtree(root->right, subRoot);

    return leftSub || rightSub;
}

int main() {
    // Main tree
    Node* root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(2);

    // Subtree
    Node* subRoot = new Node(4);
    subRoot->left = new Node(1);
    subRoot->right = new Node(2);

    if(isSubtree(root, subRoot))
        cout << "subRoot is a subtree of root" << endl;
    else
        cout << "subRoot is NOT a subtree of root" << endl;

    return 0;
}
