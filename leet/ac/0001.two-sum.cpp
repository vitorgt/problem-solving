class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        const int n = nums.size();
        int need = 0;
        unordered_map<int, vector<int>> pos;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        for (int i : nums) {
            need = target - i;
            if (!pos[need].empty()) {
                if (i == need) {
                    if (pos[need].size() > 1)
                        return pos[need];
                } else {
                    ans.push_back(pos[i][0]);
                    ans.push_back(pos[need][0]);
                    break;
                }
            }
        }
        return ans;
    }
};
