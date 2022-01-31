/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
  private:
    int capacity, used;
    unordered_map<int, list<pair<int, int>>::iterator> addr;
    list<pair<int, int>> cache;
    void pop(int key) {
        if (addr.find(key) != addr.end()) {
            cache.erase(addr[key]);
            addr.erase(key);
        }
    }

  public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->used = 0;
    }
    int get(int key) {
        if (addr.find(key) != addr.end()) {
            int value = addr[key]->second;
            pop(key);
            cache.push_front(make_pair(key, value));
            addr[key] = cache.begin();
            return value;
        }
        return -1;
    }
    void put(int key, int value) {
        if (addr.find(key) != addr.end()) {
            pop(key);
        } else {
            if (used >= capacity) {
                pop((prev(cache.end(), 1))->first);
            } else {
                used++;
            }
        }
        cache.push_front(make_pair(key, value));
        addr[key] = cache.begin();
    }
};

class LRUCacheB {
  private:
    class Node {
      public:
        int key, val;
        Node *left;
        Node *right;
        Node(int k, int v, Node *r) {
            this->key = k;
            this->val = v;
            this->left = NULL;
            this->right = r;
        }
        ~Node() {
        }
    };
    int capacity, used;
    Node *head, *tail;
    unordered_map<int, Node *> addr;
    void bubbleUp(Node *mv) {
        if (!mv || !mv->left) return;
        if (head && head != mv) {
            head->left = mv;
        }
        if (mv->right) {
            mv->right->left = mv->left;
        } else {
            // if mv has no right node it's the tail
            tail = mv->left;
        }
        mv->left->right = mv->right;
        mv->left = NULL;
        mv->right = head;
        head = mv;
    }
    Node *pushFront(int key, int value) {
        Node *front = new Node(key, value, head);
        if (head) {
            head->left = front;
        } else {
            // if it doesn't have head, it doesn't have a tail
            tail = front;
        }
        return head = front;
    }
    void popBack() {
        if (tail) {
            addr.erase(tail->key);
            Node *d = tail;
            if (tail->left) {
                tail = tail->left;
                tail->right = NULL;
            } else {
                head = NULL;
                tail = NULL;
            }
            delete d;
        }
    }

  public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->used = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    int get(int key) {
        if (addr.find(key) != addr.end()) {
            bubbleUp(addr[key]);
            return addr[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (addr.find(key) != addr.end()) {
            addr[key]->val = value;
            bubbleUp(addr[key]);
        } else {
            if (used >= capacity) {
                popBack();
            } else {
                used++;
            }
            addr[key] = pushFront(key, value);
        }
    }
};
