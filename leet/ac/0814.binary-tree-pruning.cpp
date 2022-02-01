#include "../TreeNode.hpp"

class Solution {
  public:
    TreeNode *pruneTree(TreeNode *root) {
        if (root == NULL)
            return NULL;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        return (root->val || root->left || root->right) ? root : NULL;
    }
};
