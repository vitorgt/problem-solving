#include "../TreeNode.hpp"

class Solution { // O(n)
  public:
    const int INF = 0x3f3f3f3f;
    int i = 0;
    TreeNode *bstFromPreorder(vector<int> &preorder, int key, int min,
                              int max) {
        if (i < preorder.size() && min < key && key < max) {
            TreeNode *root = new TreeNode(key);
            i++;
            if (i < preorder.size()) {
                root->left = bstFromPreorder(preorder, preorder[i], min, key);
                root->right = bstFromPreorder(preorder, preorder[i], key, max);
            }
            return root;
        }
        return NULL;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        return bstFromPreorder(preorder, preorder[i], -INF, INF);
    }
};

class solutionB { // O(n^2)
  public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        TreeNode *root = new TreeNode(preorder[0]), *aux = root;
        for (int i = 1; i < preorder.size(); i++, aux = root) {
            while (true) {
                if (preorder[i] < aux->val) {
                    if (!aux->left) {
                        aux->left = new TreeNode(preorder[i]);
                        break;
                    }
                    aux = aux->left;
                } else {
                    if (!aux->right) {
                        aux->right = new TreeNode(preorder[i]);
                        break;
                    }
                    aux = aux->right;
                }
            }
        }
        return root;
    }
};
