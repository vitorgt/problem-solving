#include "../TreeNode.hpp"

class Solution {
  public:
    TreeNode *create(vector<int> &nums, int l, int r) {
        if (l <= r) {
            int mid = floor(l + (r - l) / 2);
            TreeNode *node = new TreeNode(nums[mid]);
            node->left = create(nums, l, mid - 1);
            node->right = create(nums, mid + 1, r);
            return node;
        }
        return NULL;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return create(nums, 0, nums.size() - 1);
    }
};
