class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for (string s : strs) {
            string s2 = s;
            sort(s2.begin(), s2.end());
            m[s2].push_back(s);
        }
        for (auto pop : m) {
            ans.push_back(pop.second);
        }
        return ans;
    }
};
