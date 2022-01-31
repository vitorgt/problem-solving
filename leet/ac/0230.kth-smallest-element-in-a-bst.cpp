#include "../TreeNode.hpp"

class Solution {
  private:
    int used = 0;
    int found = -1;

  public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root || this->found != -1) return this->found;
        kthSmallest(root->left, k);
        this->used++;
        if (used == k) this->found = root->val;
        kthSmallest(root->right, k);
        return this->found;
    }
};
