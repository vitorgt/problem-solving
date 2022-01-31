class Solution {  // Time O(n)
  public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            dp.push_back(max(nums[i], dp[i - 1] + nums[i]));
            if (dp[i] > maxSum) maxSum = dp[i];
        }
        return maxSum;
    }
};

class SolutionB {  // Time O(n^2)
  public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], windowSum = 0;
        for (int l = 0; l < nums.size(); l++) {
            windowSum = 0;
            for (int r = l; r < nums.size(); r++) {
                windowSum += nums[r];
                if (windowSum > maxSum) {
                    maxSum = windowSum;
                }
            }
        }
        return maxSum;
    }
};
