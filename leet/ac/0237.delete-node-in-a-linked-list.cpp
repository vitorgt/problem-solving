#include "../ListNode.hpp"

class Solution {
  public:
    void deleteNode(ListNode *node) {
        if (node && node->next && node->next->next) {
            node->val = node->next->val;
            deleteNode(node->next);
        } else {
            node->val = node->next->val;
            node->next = NULL;
        }
    }
};
