class Solution {
  private:
    unordered_map<int, int> map_i_pos;
    int preorder_i = 0;

    TreeNode *dfs(int left, int right, vector<int> &preorder) {
        if (left > right || preorder_i == preorder.size()) return NULL;

        // preorder
        // first we assign value
        TreeNode *root = new TreeNode(preorder[preorder_i++]);

        // then left, then right
        root->left = dfs(left, map_i_pos[root->val] - 1, preorder);
        root->right = dfs(map_i_pos[root->val] + 1, right, preorder);

        return root;
    }

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        for (size_t i = 0; i < n; i++) map_i_pos[inorder[i]] = i;

        return dfs(0, n - 1, preorder);
    }
};

// doesn't work
class SolutionA {
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        vector<TreeNode *> transversal({root});
        unordered_map<int, int> pi;
        int n = inorder.size();
        for (size_t i = 0; i < n; i++) pi[inorder[i]] = i;
        for (size_t i = 1; i < n; i++) {
            if (pi[preorder[i]] < pi[preorder[i - 1]]) {
                transversal.back()->left = new TreeNode(preorder[i]);
                transversal.push_back(transversal.back()->left);
            } else {
                while (pi[preorder[i]] > pi[transversal.back()->val] &&
                       transversal.size() > 1)
                    transversal.pop_back();
                transversal.back()->right = new TreeNode(preorder[i]);
                transversal.push_back(transversal.back()->right);
            }
        }
        return root;
    }
};
