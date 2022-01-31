class Solution {
  public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        multimap<int, char> pq;
        for (auto f : freq) {
            pq.insert({f.second, f.first});
        }
        for (auto f : pq) {
            ans = string(f.first, f.second) + ans;
        }
        return ans;
    }
};
