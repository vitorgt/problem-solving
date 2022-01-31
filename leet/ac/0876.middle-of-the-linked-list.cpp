#include "../ListNode.hpp"

class Solution {
  public:
    ListNode *middleNode(ListNode *head) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        ListNode *hare = head, *tortoise = head;
        while (hare && hare->next) {
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        return tortoise;
    }
};
