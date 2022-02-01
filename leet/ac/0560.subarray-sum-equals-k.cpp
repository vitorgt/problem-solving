class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        const int n = nums.size();
        int count = 0, acc = 0;
        unordered_map<int, int> countAcc;
        countAcc[acc]++;
        for (int i = 0; i < n; i++) {
            acc += nums[i];
            // acc[j] - acc[i - 1] == k
            // acc[i - 1] == acc[j] - k
            count += countAcc[acc - k];
            countAcc[acc]++;
        }
        return count;
    }
};
