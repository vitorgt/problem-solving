#include "../TreeNode.hpp"

class Solution {
  public:
    int height(TreeNode *root) {
        if (root) {
            return 1 + max(height(root->left), height(root->right));
        }
        return 0;
    }
    int diameterOfBinaryTree(TreeNode *root) {
        if (root) {
            return max(height(root->left) + height(root->right),
                       max(diameterOfBinaryTree(root->left),
                           diameterOfBinaryTree(root->right)));
        }
        return 0;
    }
};
