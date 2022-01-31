class Solution {
  public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        if (root1 && root2) {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
        } else if (root2) {
            return root2;
        }
        return root1;
    }
};
