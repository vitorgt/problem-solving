#include <bits/stdc++.h>
#include "../TreeNode.hpp"
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        int lvlCount = 1, nextLvlCount = 0;
        TreeNode *aux = NULL;
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> lvl;
            while (lvlCount--) {
                aux = q.front();
                lvl.push_back(aux->val);
                if (aux->left) {
                    q.push(aux->left);
                    nextLvlCount++;
                }
                if (aux->right) {
                    q.push(aux->right);
                    nextLvlCount++;
                }
                q.pop();
            }
            ans.push_back(lvl);
            lvlCount = nextLvlCount;
            nextLvlCount = 0;
        }
        return ans;
    }
};

class SolutionB {
  private:
    vector<vector<int>> ans;
    void level(TreeNode *root, int l) {
        if (root) {
            try {
                this->ans[l].push_back(root->val);
            } catch (const exception &e) {
                vector<int> first(root->val, 1);
                this->ans.push_back(first);
            }
            level(root->left, l + 1);
            level(root->right, l + 1);
        }
    }

  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        this->level(root, 0);
        return this->ans;
    }
};
