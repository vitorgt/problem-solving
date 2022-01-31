#include "../TreeNode.hpp"

class Solution {
  private:
    TreeNode *parent(TreeNode *root, int find) {
        if (!root) return NULL;
        if (root->val == find) return root;
        if (root->left && root->left->val == find) return root;
        if (root->right && root->right->val == find) return root;
        TreeNode *left = parent(root->left, find);
        TreeNode *right = parent(root->right, find);
        return left ? left : right;
    }
    int depth(TreeNode *root, int find, int dep) {
        if (!root) return 0;
        if (root->val == find) return dep;
        return depth(root->left, find, dep + 1) +
               depth(root->right, find, dep + 1);
    }

  public:
    bool isCousins(TreeNode *root, int x, int y) {
        if (depth(root, x, 0) == depth(root, y, 0)) {
            if (parent(root, x) != parent(root, y)) {
                return true;
            }
        }
        return false;
    }
};
