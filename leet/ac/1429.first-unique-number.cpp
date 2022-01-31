/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

class FirstUnique {
  private:
    unordered_map<int, list<int>::iterator> unique;
    unordered_set<int> repeated;
    list<int> sorted;

  public:
    FirstUnique(vector<int> &nums) {
        for (int i : nums) {
            add(i);
        }
    }

    int showFirstUnique() {
        if (sorted.empty()) return -1;
        return sorted.front();
    }

    void add(int value) {
        auto u = unique.find(value);
        auto n = repeated.find(value);
        if (u == unique.end() && n == repeated.end()) {
            // if isnt in both uniques and not uniques
            unique[value] = sorted.insert(sorted.end(), value);
        } else if (u != unique.end()) {
            // found on unique
            sorted.erase(unique[value]);
            unique.erase(value);
            repeated.insert(value);
        }
    }
};

class FirstUniqueB {  // first try, may work, abandoned
  private:
    class Node {
      public:
        int val;
        Node *next;
        Node(int v) {
            this->val = v;
            this->next = NULL;
        }
        ~Node() {
        }
    };
    Node *head, *tail;
    unordered_map<int, Node *> addr;
    unordered_set<int> uniques, notu;

    Node *pushBack(int value) {
        Node *back = new Node(value);
        if (tail) {
            tail->next = back;
        } else {
            head = tail = back;
        }
        return back;
    }
    void pop(Node *rm) {
        Node *aux = head;
        while (aux && aux != rm && aux->next && aux->next != rm)
            aux = aux->next;
        if (aux == rm) {
            // it's head
            addr.erase(aux->val);
            if (aux == tail) {
                head = tail = NULL;
            } else {
                head = aux->next;
            }
        } else if (aux->next == rm) {
            // remove next
            addr.erase(aux->next->val);
            if (aux->next == tail) {
                tail = aux;
            }
            aux->next = aux->next->next;
        } else {
            // not found
        }
        delete aux;
    }

  public:
    FirstUnique(vector<int> &nums) {
        for (int i : nums) {
            add(i);
        }
    }
    int showFirstUnique() {
        return head->val;
    }
    void add(int value) {
        auto u = uniques.find(i), n = notu.find(i);
        if (u == uniques.end() && n == notu.end()) {
            // if isnt in both uniques and not uniques
            uniques.insert(i);
            addr[i] = pushBack(i);
        } else if (u != uniques.end()) {
            // found on uniques
            uniques.erase(i);
            pop(addr[i]);
            notu.insert(i);
        }  // else if(n != notu.end()) {
           // found on not uniques, do nothing
           //}
    }
};
