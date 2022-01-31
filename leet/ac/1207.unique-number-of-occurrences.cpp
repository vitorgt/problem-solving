class Solution {
  public:
    bool uniqueOccurrences(vector<int> &arr) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        unordered_map<int, int> ca, ac;
        for (auto i : arr) ac[i + 1000]++;

        for (auto &i : ac) {
            ca[i.second]++;
            if (ca[i.second] > 1) return false;
        }

        return true;
    }
};
