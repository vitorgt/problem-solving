class FirstUnique {
  private:
    unordered_map<char, list<pair<char, int>>::iterator> unique;
    unordered_set<char> repeated;
    list<pair<char, int>> sorted;

  public:
    FirstUnique(vector<char> &v) {
        for (int i = 0; i < v.size(); i++) {
            add(v[i], i);
        }
    }

    int indexFirstUnique() {
        if (sorted.empty()) return -1;
        return sorted.front().second;
    }

    char showFirstUnique() {
        if (sorted.empty()) return -1;
        return sorted.front().first;
    }

    void add(char value, int i) {
        auto u = unique.find(value);
        auto n = repeated.find(value);
        if (u == unique.end() && n == repeated.end()) {
            // if isnt in both uniques and not uniques
            unique[value] =
                sorted.insert(sorted.end(), make_pair(value, i));
        } else if (u != unique.end()) {
            // found on unique
            sorted.erase(unique[value]);
            unique.erase(value);
            repeated.insert(value);
        }
    }
};

class Solution {
  public:
    int firstUniqChar(string s) {
        vector<char> ss(s.begin(), s.end());
        FirstUnique *fu = new FirstUnique(ss);
        return fu->indexFirstUnique();
    }
};
