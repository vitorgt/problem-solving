#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LFUCache {
  private:
    int capacity, used;

  public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->used = 0;
    }
    int get(int key) {}
    void put(int key, int value) {}
};

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
