#include "../TreeNode.hpp"

class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        stack<TreeNode *> lr, rl;
        lr.push(root);
        TreeNode *aux = NULL;
        while (!lr.empty() || !rl.empty()) {
            vector<int> level1;
            while (!lr.empty()) {
                aux = lr.top();
                if (aux->left)
                    rl.push(aux->left);
                if (aux->right)
                    rl.push(aux->right);
                level1.push_back(aux->val);
                lr.pop();
            }
            if (!level1.empty())
                ans.push_back(level1);
            vector<int> level2;
            while (!rl.empty()) {
                aux = rl.top();
                if (aux->right)
                    lr.push(aux->right);
                if (aux->left)
                    lr.push(aux->left);
                level2.push_back(aux->val);
                rl.pop();
            }
            if (!level2.empty())
                ans.push_back(level2);
        }
        return ans;
    }
};
