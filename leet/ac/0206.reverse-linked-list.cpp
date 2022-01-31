#include "../ListNode.hpp"

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *curr = NULL, *temp = head, *prev = NULL;
        while (temp) {
            prev = curr;
            curr = temp;
            temp = curr->next;
            curr->next = prev;
        }
        return curr;
    }
};
