#include <bits/stdc++.h>
using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}

    void preorder(bool first = true) {
        TreeNode::preorder(this);
    }

    static void preorder(TreeNode *root, bool first = true) {
        if (!root) return;
        if (first) cout << "[";
        cout << root->val << ",";
        preorder(root->left, false);
        preorder(root->right, false);
        if (first) cout << "]" << endl;
    }

    void inorder(bool first = true) {
        TreeNode::inorder(this);
    }

    static void inorder(TreeNode *root, bool first = true) {
        if (!root) return;
        if (first) cout << "[";
        inorder(root->left, false);
        cout << root->val << ",";
        inorder(root->right, false);
        if (first) cout << "]" << endl;
    }

    void postorder(bool first = true) {
        TreeNode::postorder(this);
    }

    static void postorder(TreeNode *root = this, bool first = true) {
        if (!root) return;
        if (first) cout << "[";
        postorder(root->left, false);
        postorder(root->right, false);
        cout << root->val << ",";
        if (first) cout << "]" << endl;
    }
};
