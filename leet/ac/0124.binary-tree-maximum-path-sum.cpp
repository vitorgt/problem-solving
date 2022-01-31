#include "../TreeNode.hpp"

class Solution {  // based on leetcode.com/wei-bung solution
  private:
    const int INF = 0x3f3f3f3f;
    int maxSum = -INF;
    int maxPath(TreeNode* root) {
        if (!root) return 0;
        int left = max(0, maxPath(root->left));
        int right = max(0, maxPath(root->right));
        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }

  public:
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxSum;
    }
};

class SolutionB {  // abandoned, might eventually work
  private:
    const int INF = 0x3f3f3f3f;

  public:
    int maxPathSum(TreeNode* root) {
        if (root) {
            if (root->left || root->right) {
                int left = maxPathSum(root->left);
                int right = maxPathSum(root->right);
                return max(
                    left, max(root->val,
                              max(right,
                                  max(left + root->val,
                                      max(right + root->val,
                                          left + root->val + right)))));
            } else  // if(!root->left && !root->right)
                return root->val;
        }
        return -INF;
    }
};
