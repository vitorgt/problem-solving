#include "../ListNode.hpp"

class Solution { // based on https://leetcode.com/yangliguang solution
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

class SolutionB { // my iterative solution O(n) time, O(1) space
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2)
            return l1;
        if (l1 && !l2)
            return l1;
        if (!l1 && l2)
            return l2;
        ListNode *head = NULL, *aux = NULL, *aux1 = l1, *aux2 = l2;
        if (aux1->val < aux2->val) {
            head = aux1;
            aux1 = aux1->next;
            aux = head;
        } else {
            head = aux2;
            aux2 = aux2->next;
            aux = head;
        }
        while (aux1 && aux2) {
            if (aux1->val < aux2->val) {
                aux->next = aux1;
                aux1 = aux1->next;
                aux = aux->next;
            } else {
                aux->next = aux2;
                aux2 = aux2->next;
                aux = aux->next;
            }
        }
        if (aux1) {
            aux->next = aux1;
        } else if (aux2) {
            aux->next = aux2;
        }
        return head;
    }
};
