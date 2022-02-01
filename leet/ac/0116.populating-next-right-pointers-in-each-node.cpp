class Node {
  public:
    int val;
    Node *left, *right, *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution { // Recursive
  public:
    Node *connect(Node *root) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        if (root && root->left) {
            if (root->next)
                root->right->next = root->next->left;
            root->left->next = root->right;
            connect(root->left);
            connect(root->right);
        }

        return root;
    }
};

class Solution { // Iterative
  public:
    Node *connect(Node *root) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        if (!root || (!root->left && !root->right))
            return root;

        int lvl = 1, nxtlvl = 0;
        Node *at = NULL, *pastngb = NULL;
        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            while (!q.empty() && lvl--) {
                at = q.front();
                q.pop();

                if (pastngb) {
                    pastngb->next = at;
                }

                if (at->left) {
                    q.push(at->left);
                    nxtlvl++;
                }
                if (at->right) {
                    q.push(at->right);
                    nxtlvl++;
                }

                pastngb = at;
            }
            lvl = nxtlvl;
            nxtlvl = 0;
            pastngb = NULL;
        }

        return root;
    }
};
