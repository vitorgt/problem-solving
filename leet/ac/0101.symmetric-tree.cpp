#include "../TreeNode.hpp"

class Solution {
  public:
    bool isSymmetric(TreeNode *tree1, TreeNode *tree2) {
        if (!tree1 && !tree2)
            return true;
        if (!tree1 || !tree2)
            return false;
        return tree1->val == tree2->val &&
               isSymmetric(tree1->left, tree2->right) &&
               isSymmetric(tree1->right, tree2->left);
    }
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        return isSymmetric(root->left, root->right);
    }
};
