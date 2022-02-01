class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        ListNode *prevHead = new ListNode(-1, head);
        ListNode *fast = prevHead, *slow = prevHead;

        while (n-- && fast)
            fast = fast->next;

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return prevHead->next;
    }
};

class SolutionB { // Fails
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        ListNode *fast = head, *slow = head, *slowPrev = head;
        int nCopy = n;
        while (fast) {
            nCopy = n;
            slowPrev = slow;
            slow = slow->next;
            while (nCopy-- && fast)
                fast = fast->next;
        }

        if (slowPrev == head)
            head = head->next;
        else if (slowPrev->next)
            slowPrev->next = slowPrev->next->next;
        else
            slowPrev->next = NULL;

        return head;
    }
};
