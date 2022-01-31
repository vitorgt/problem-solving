class Solution {
  private:
    bool fp = false, fq = false; // f: found
    vector<TreeNode*> tp, tq;    // t: transversal
    TreeNode *rp, *rq;           // r: ref
    void transverse(TreeNode* root) {
        if (!root) return;
        if (!fp) tp.push_back(root);
        if (!fq) tq.push_back(root);
        if (root == rp) fp = true;
        if (root == rq) fq = true;
        if (fp && fq) return;
        transverse(root->left);
        transverse(root->right);
        if (!fp) tp.pop_back();
        if (!fq) tq.pop_back();
    }

  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        rp = p;
        rq = q;
        transverse(root);
        int i = 0;
        while (i < tp.size() && i < tq.size() && tp[i] == tq[i]) i++;
        return tp[i - 1];
    }
};

class SolutionB { // better
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : (!right ? left : root);
    }
};
