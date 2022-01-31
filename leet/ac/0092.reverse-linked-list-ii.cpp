class Solution {
  public:
    ListNode *reverse(ListNode *head, int qnt) {
        ListNode *prev = NULL, *curr = head, *next = head->next;

        while (qnt-- && curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        if (left == right) return head;

        int changes = right - left + 1, right2 = right - 1;
        ListNode *prev = NULL, *next = head, *rev = head;

        if (left > 1) {
            prev = head;
            for (int i = 2; i < left && prev; i++) prev = prev->next;
            while (--left && rev) rev = rev->next;
        }

        while (right-- && next) next = next->next;

        if (prev) {
            prev->next = reverse(rev, changes);
        } else {
            head = reverse(rev, changes);
        }

        rev = head;
        while (right2-- && rev->next) rev = rev->next;
        rev->next = next;

        return head;
    }
};
