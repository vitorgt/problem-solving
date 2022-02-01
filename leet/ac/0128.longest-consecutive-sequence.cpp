class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        if (!nums.size())
            return 0;

        unordered_set<int> s(nums.begin(), nums.end());

        int minNums = nums[0], ans = 0, i = 0;
        while (!s.empty()) {
            minNums = *s.begin();
            for (int j : s)
                minNums = min(j, minNums);
            for (i = minNums; s.count(i); i++)
                s.erase(i);
            ans = max(i - minNums, ans);
        }

        return ans;
    }
};
