class Solution {
  public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_multiset<string> ms(words.begin(), words.end());
        vector<set<string>> vs(words.size(), set<string>());
        for (auto i = ms.begin(); i != ms.end(); i++) {
            vs[ms.count(*i)].insert(*i);
        }
        for (int i = words.size() - 1; i >= 0 && k > 0; i--) {
            for (auto j = vs[i].begin(); j != vs[i].end() && k > 0;
                 j++) {
                ans.push_back(*j);
                k--;
            }
        }
        return ans;
    }
};
