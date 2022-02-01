#include <bits/stdc++.h>
using namespace std;

class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    static ListNode *fromVector(vector<int> v) {
        if (v.empty())
            return NULL;

        ListNode *head = new ListNode(v[0]);
        ListNode *aux = head;

        for (size_t i = 1; i < v.size(); i++) {
            aux->next = new ListNode(v[i]);
            aux = aux->next;
        }

        return head;
    }

    static void print(ListNode *head) {
        if (!head)
            return;

        ListNode *aux = head;

        while (aux) {
            cout << aux->val << " ";
            aux = aux->next;
        }

        cout << endl;
    }
};
