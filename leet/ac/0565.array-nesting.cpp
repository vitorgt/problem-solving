class Solution {
  public:
    int arrayNesting(vector<int> &nums) {
        const int n = nums.size();
        if (n == 0)
            return 0;
        int maxLen = 0, temp = 0;
        for (int i = 0; i < n; i++) {
            int len = 0;
            for (int at = i; nums[at] >= 0; len++) {
                temp = nums[at];
                nums[at] = -1;
                at = temp;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

class SolutionB { // 855 / 856 test cases passed
  public:
    int arrayNesting(vector<int> &nums) {
        const int n = nums.size();
        if (n == 0)
            return 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int len = 0;
            vector<bool> vis(n, false);
            for (int at = i; !vis[at]; at = nums[at], len++) {
                vis[at] = true;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

class SolutionC { // 854 / 856 test cases passed
  public:
    int arrayNesting(vector<int> &nums) {
        const int n = nums.size();
        if (n == 0)
            return 0;
        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            vector<int> len(n, -1);
            len[i] = 1;
            for (int at = i; len[nums[at]] == -1; at = nums[at]) {
                len[nums[at]] = len[at] + 1;
                maxLen = max(maxLen, len[nums[at]]);
            }
        }
        return maxLen;
    }
};
