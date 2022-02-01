template <typename T> class FirstUnique {
  private:
    unordered_map<T, list<pair<T, int>>::iterator> unique;
    unordered_set<T> repeated;
    list<pair<T, int>> sorted;

  public:
    FirstUnique(vector<T> &v) {
        for (int i = 0; i < v.size(); i++) {
            add(v[i], i);
        }
    }

    int indexFirstUnique() {
        if (sorted.empty())
            return -1;
        return sorted.front().second;
    }

    T showFirstUnique() {
        if (sorted.empty())
            return -1;
        return sorted.front().first;
    }

    void add(T value, int i) {
        auto u = unique.find(value);
        auto n = repeated.find(value);
        if (u == unique.end() && n == repeated.end()) {
            // if isnt in both uniques and not uniques
            unique[value] = sorted.insert(sorted.end(), make_pair(value, i));
        } else if (u != unique.end()) {
            // found on unique
            sorted.erase(unique[value]);
            unique.erase(value);
            repeated.insert(value);
        }
    }
};
