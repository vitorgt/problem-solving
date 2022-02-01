class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        const int n = nums.size();
        vector<int> left(n + 1, 1), right(n + 1, 1), answer;
        for (int i = 0; i < n; i++) {
            left[i + 1] = left[i] * nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i];
        }
        for (int i = 0; i < n; i++) {
            answer.push_back(left[i] * right[i + 1]);
        }
        return answer;
    }
};
