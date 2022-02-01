#include "../TreeNode.hpp"

class Solution {
  private:
    bool isValidSequence(TreeNode *root, vector<int> &arr, int i) {
        if (root && i < arr.size()) {
            if (root->val == arr[i]) {
                if (i == arr.size() - 1) {
                    return !root->left && !root->right;
                } else {
                    return isValidSequence(root->left, arr, i + 1) ||
                           isValidSequence(root->right, arr, i + 1);
                }
            }
            return false;
        }
        return false;
    }

  public:
    bool isValidSequence(TreeNode *root, vector<int> &arr) {
        return isValidSequence(root, arr, 0);
    }
};
