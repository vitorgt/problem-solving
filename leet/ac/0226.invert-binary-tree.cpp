#include "../TreeNode.hpp"

class Solution {
  public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            TreeNode* aux = root->left;
            root->left = root->right;
            root->right = aux;
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};
