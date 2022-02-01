class Solution {
  public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        const int n = groupSizes.size();
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[groupSizes[i]].push_back(i);
            if (groups[groupSizes[i]].size() == groupSizes[i]) {
                ans.push_back(groups[groupSizes[i]]);
                groups[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};
