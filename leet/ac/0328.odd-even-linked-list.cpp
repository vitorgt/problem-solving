#include "../ListNode.hpp"

class Solution {
  public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next)
            return head;
        bool parity = true;
        ListNode *aux = head->next->next, *lastOdd = head;
        ListNode *evenHead = head->next, *lastEven = head->next;
        while (aux) {
            parity = !parity;
            if (parity) {
                lastEven->next = aux;
                lastEven = aux;
            } else {
                lastOdd->next = aux;
                lastOdd = aux;
            }
            aux = aux->next;
        }
        lastOdd->next = evenHead;
        lastEven->next = NULL;
        return head;
    }
};
